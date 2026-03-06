#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <ctime>
#include <map>
#include <sstream>
#include <random>

using namespace std;

// 常量定义
const string SUITS[] = {"\033[31m♥\033[0m", "\033[31m♦\033[0m", "♣", "♠"}; // 红桃/方块用红色，草花/黑桃默认
const string RANKS = "A23456789TJQK";
const string TYPE_NAMES[] = {
    "High Card (高牌)", "Pair (对子)", "2 Pairs (两对)", "3-of-a-kind (三条)",
    "Straight (顺子)", "Flush (同花)", "Full House (葫芦)", 
    "4-of-a-kind (四条)", "Straight Flush (同花顺)"
};
// 倍率对应表 (High Card -> Straight Flush)
const int MULTIPLIERS[] = {0, 1, 2, 3, 5, 8, 10, 50, 150};

// 辅助函数：获取花色 (0-3)
int getSuit(int card) {
    return card / 13; // 根据题目要求：值 = 花色*13 + ...，反推即除法
}

// 辅助函数：获取点数 (0-12, 0代表A)
int getRank(int card) {
    return card % 13;
}

// 显示五张牌
void printCards(int cards[]) {
    vector<int> v(cards, cards + 5);
    // 题目要求：按数值大小排序后输出
    sort(v.begin(), v.end());

    for (int card : v) {
        int s = getSuit(card);
        int r = getRank(card);
        // 输出格式：[花色][点数]
        cout << "[" << SUITS[s] << (r == 9 ? "10" : string(1, RANKS[r])) << "] ";
    }
    cout << endl;
}

// 判断牌型核心逻辑
int JudgeCards(int cards[]) {
    vector<int> ranks, suits;
    for(int i=0; i<5; i++) {
        ranks.push_back(getRank(cards[i]));
        suits.push_back(getSuit(cards[i]));
    }
    sort(ranks.begin(), ranks.end());

    // 1. 统计点数频率
    map<int, int> counts;
    for(int r : ranks) counts[r]++;
    
    bool isFlush = true;
    for(size_t i = 1; i < suits.size(); i++) if(suits[i] != suits[0]) isFlush = false;

    // 2. 判断顺子
    bool isStraight = true;
    // 特殊情况：A T J Q K (0, 9, 10, 11, 12)
    if (ranks[0]==0 && ranks[1]==9 && ranks[2]==10 && ranks[3]==11 && ranks[4]==12) {
        isStraight = true;
    } else {
        for(int i=0; i<4; i++) {
            if(ranks[i+1] != ranks[i] + 1) { isStraight = false; break; }
        }
    }

    // 3. 综合判断
    if (isStraight && isFlush) return 8; // Straight Flush

    // 检查重复牌型 (4条, 3条, 对子)
    int maxCount = 0;
    int pairCount = 0;
    for(auto const& [key, val] : counts) {
        if (val > maxCount) maxCount = val;
        if (val == 2) pairCount++;
    }

    if (maxCount == 4) return 7; // 4-of-a-kind
    if (maxCount == 3 && pairCount == 1) return 6; // Full House (3+2)
    if (isFlush) return 5; // Flush
    if (isStraight) return 4; // Straight
    if (maxCount == 3) return 3; // 3-of-a-kind
    if (pairCount == 2) return 2; // 2 Pairs
    if (pairCount == 1) return 1; // Pair

    return 0; // High Card
}

// 牌堆管理
class Deck {
    vector<int> cards;
public:
    Deck() {
        cards.resize(52);
        iota(cards.begin(), cards.end(), 0); // 填充 0-51
        shuffleDeck();
    }
    void shuffleDeck() {
        // 使用 std::shuffle 和 mt19937 替代已废弃的 random_shuffle
        static std::mt19937 rng(static_cast<unsigned int>(time(0)));
        std::shuffle(cards.begin(), cards.end(), rng);
    }
    int dealOne() {
        if(cards.empty()) return -1; // 应该不会发生
        int c = cards.back();
        cards.pop_back();
        return c;
    }
    void reset() {
        cards.resize(52);
        iota(cards.begin(), cards.end(), 0);
        shuffleDeck();
    }
};

int main() {
    srand(time(0));

    int chips = 100;
    Deck deck;
    int hand[5];

    while (true) {
        if (chips <= 0) {
            cout << "筹码耗尽，游戏结束！" << endl;
            break;
        }

        deck.reset(); // 每局重新洗牌
        cout << "当前筹码: " << chips << endl;
        
        // 2. 下注
        int bet = 0;
        while (true) {
            cout << "请输入投入筹码 (1-" << chips << "): ";
            if (cin >> bet && bet > 0 && bet <= chips) break;
            cout << "输入无效，请重新输入。" << endl;
            cin.clear(); cin.ignore(1000, '\n');
        }
        chips -= bet;
        cout << "剩余筹码: " << chips << endl;

        // 3. 发牌
        for(int i=0; i<5; i++) hand[i] = deck.dealOne();
        // [修复] 对手牌进行排序，确保用户看到的牌序与内存中数组顺序一致
        // 否则用户想换第1张显示的牌时，程序可能会换掉错误的牌
        sort(hand, hand + 5);
        
        cout << "当前手牌: ";
        printCards(hand);

        // 4. 换牌
        cout << "请输入要换的牌序号(1-5，空格分隔，直接回车不换): ";
        cin.ignore(); // 清除之前的换行符
        string line;
        getline(cin, line);
        
        if (!line.empty()) {
            stringstream ss(line);
            int idx;
            int count = 0;
            vector<int> toChange;
            while (ss >> idx) {
                if (idx >= 1 && idx <= 5) toChange.push_back(idx - 1); // 转换为0-based
            }
            
            // 限制最多换3张
            if (toChange.size() > 3) toChange.resize(3);

            for (int i : toChange) {
                hand[i] = deck.dealOne(); // 5. 替换
            }
            
            cout << "换牌后手牌: ";
            printCards(hand);
        } else {
            cout << "不换牌。" << endl;
        }

        // 6. 判型与结算
        int type = JudgeCards(hand);
        int multiplier = MULTIPLIERS[type];
        int win = bet * multiplier;
        chips += win;

        cout << "牌型: " << TYPE_NAMES[type] << endl;
        cout << "倍率: " << multiplier << ", 赢得: " << win << endl;
        
        // 8. 是否继续
        if (chips > 0) {
            cout << "是否继续? (y/n): ";
            char c;
            cin >> c;
            if (c == 'n' || c == 'N') {
                cout << "最终筹码: " << chips << "，再见！" << endl;
                break;
            }
        }
    }

    return 0;
}
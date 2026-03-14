#include <bits/stdc++.h>
using namespace std;

// 简化结构体：只记录花费和是否为王牌
struct card {
    int cost;
    bool is_win;

    // 小根堆：花费小的排在队头
    bool operator < (const card& other) const {
        return cost > other.cost;
    }
};

int main()
{
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, k, p, m;
        cin >> n >> k >> p >> m;

        // 【关键】将队列定义在循环内，保证每次测试用例都是干净的
        priority_queue<card> pq;
        queue<card> q;

        bool win_in_hand = false; // 记录王牌当前是否在手里
        int win_cost = 0;         // 单独记录王牌的花费

        // 1. 发牌阶段
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            card card = {c, (i == p)}; // 如果正好是第 p 张，is_win 就是 true

            if (card.is_win) {
                win_cost = c;
            }

            if (i <= k) { // 前 k 张是初始手牌
                if (card.is_win) win_in_hand = true;
                else pq.push(card);
            } else {      // 后面的进入牌库
                q.push(card);
            }
        }

        // 【防崩溃特判】：如果牌全部都在手里，直接输出能打多少次王牌即可
        if (n == k) {
            cout << m / win_cost << '\n';
            continue;
        }

        int ans = 0; // 记录打出王牌的次数

        // 2. 打牌模拟阶段
        while (true) {
            if (win_in_hand) {
                // 王牌在手，优先打出王牌
                if (m >= win_cost) {
                    m -= win_cost; // 扣除能量
                    ans++;         // 次数 +1

                    // 打出的王牌进入牌库底
                    q.push({win_cost, true});

                    // 从牌库顶抽一张牌
                    card drawn = q.front();
                    q.pop();

                    // 判断抽上来的牌是不是王牌
                    if (drawn.is_win) {
                        win_in_hand = true;
                    } else {
                        win_in_hand = false;
                        pq.push(drawn); // 不是王牌，加入手牌堆
                    }
                } else {
                    break; // 能量不够打王牌了，直接结束
                }
            } else {
                // 王牌不在手，打出最便宜的牌过牌
                card cheapest = pq.top();
                if (m >= cheapest.cost) {
                    m -= cheapest.cost; // 扣除过牌的能量
                    pq.pop();           // 从手牌中移除

                    // 打出的过牌进入牌库底
                    q.push(cheapest);

                    // 从牌库顶抽一张牌
                    card drawn = q.front();
                    q.pop();

                    // 判断抽上来的是不是我们苦苦等待的王牌
                    if (drawn.is_win) {
                        win_in_hand = true;
                    } else {
                        pq.push(drawn); // 抽到的还是普通牌，加入手牌堆
                    }
                } else {
                    break; // 连最便宜的牌都打不起了，直接结束
                }
            }
        }

        // 3. 输出答案
        cout << ans << '\n';
    }

    return 0;
}
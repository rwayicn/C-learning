//
// Created by rwayicn on 2026/3/8.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int n, m;
    long long l;
    cin >> n >> m >> l;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // D 数组记录每个机械玩偶当前的危险值
    vector<long long> D(m, 0);

    long long last_a = 0;
    // 将整个夜晚划分为 n + 1 个时间段
    for (int i = 0; i <= n; ++i) {
        long long current_a = (i == n) ? l : a[i];
        long long delta = current_a - last_a;

        // 此时间段之后，还剩下的手电筒使用次数
        int k = n - i;
        // 系统会集中攻击危险值最高的 C 个玩偶
        int C = min(k + 1, m);

        // 将当前危险值降序排序，确保前 C 个是最高项
        sort(D.rbegin(), D.rend());

        // 模拟系统的最优攻击策略：对这 C 个玩偶进行“注水”
        if (delta > 0 && C > 0) {
            // 使用小根堆快速定位这 C 个玩偶中的最小值并使其递增
            priority_queue<long long, vector<long long>, greater<long long>> pq;
            for (int j = 0; j < C; ++j) {
                pq.push(D[j]);
            }
            // 每次分配 1 点危险值
            for (long long j = 0; j < delta; ++j) {
                long long val = pq.top();
                pq.pop();
                pq.push(val + 1);
            }
            // 将更新后的危险值写回数组
            for (int j = 0; j < C; ++j) {
                D[j] = pq.top();
                pq.pop();
            }
        }

        // 如果当前时间点是手电筒使用时刻
        if (i < n) {
            // 重新降序排序，找到此时危险值最大的玩偶，将其清零
            sort(D.rbegin(), D.rend());
            D[0] = 0;
        }

        last_a = current_a;
    }

    // 游戏结束，找出所有玩偶中的最大危险值
    sort(D.rbegin(), D.rend());
    cout << D[0] << "\n";
}

int main() {
    // 优化标准 I/O 操作以符合算法竞赛要求
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
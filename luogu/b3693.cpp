//
// Created by rwayicn on 2026/3/14.
//

#include <bits/stdc++.h>
using namespace std;

template <class T>
T getXorSum(T *begin, T *end) {
    T ret = 0;
    for (T *it = begin; it != end; ++it) ret ^= *it;
    return ret;
}

int n, m;
unsigned long long a[1005][1005] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int z = 0;z < t;z++)
    {
        unsigned long long q;
        cin >> n >> m >> q;
        unsigned long long ans[q];
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                unsigned long long temp;
                cin >> temp;
                a[i][j] = (a[i - 1][j] + a[i][j - 1] + temp - a[i - 1][j - 1]) ;
            }
        }
        for (int i = 0;i < q;i++)
        {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            ans[i] = a[x][y] - a[u - 1][y] - a[x][v - 1] + a[u - 1][v - 1];
        }
        cout << getXorSum(ans, ans + q) << '\n';
    }
}
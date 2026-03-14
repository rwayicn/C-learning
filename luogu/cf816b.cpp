//
// Created by rwayicn on 2026/3/14.
//

#include <bits/stdc++.h>
using namespace std;

int sum[200005] = {0}, cf[200005] = {0}, ans[200005] = {0};

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1;i <= n;i++)
    {
        int l, r;
        cin >> l >> r;
        cf[l]++;
        cf[r + 1]--;
    }
    for (int i = 1;i <= 200005;i++)
    {
        sum[i] = sum[i - 1] + cf[i];
        if (sum[i] >= k)
        {
            ans[i] = ans[i - 1] + 1;
        }
        else
        {
            ans[i] = ans[i - 1];
        }
    }
    for (int i = 0;i < q;i++)
    {
        int a, b;
        cin >> a >> b;
        cout << ans[b] - ans[a - 1] << '\n';
    }
}
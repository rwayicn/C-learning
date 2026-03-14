//
// Created by rwayicn on 2026/3/14.
//

#include <bits/stdc++.h>
using namespace std;

int k[205] = {0}, minn = 1e9, n, a, b, ans = 0;
bool isR[205];

void dfs(int x)
{
    if (x == b)
    {
        minn = min(minn, ans);
        return;
    }
    if (isR[x] == true) return;
    isR[x] = true;
    ans++;
    if (x + k[x] <= n)
    {
        dfs(x + k[x]);
    }
    ans--;
    isR[x] = false;
    if (x - k[x] > 0)
    {
        dfs(x - k[x]);
    }
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
    }
    dfs(a);
    cout << minn << '\n';
}
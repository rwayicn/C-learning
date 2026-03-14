//
// Created by rwayicn on 2026/3/14.
//

#include <bits/stdc++.h>
using namespace std;

int ku[11] = {0}, sour[11] = {0}, mind = 2e9, n;
bool tl[11] = {false};

void dfs(int x)
{
    if (x > n)
    {
        int ji = 1, sum = 0;
        for (int i = 1;i <= n;i++)
        {
            if (tl[i])
            {
                ji *= sour[i];
                sum += ku[i];
            }
        }
        int t = 0;
        for (int i = 1;i <= n;i++)
            if (tl[i]) t++;
        if (t)
            mind = min(mind, abs(ji - sum));
        return;
    }
    tl[x] = true;
    dfs(x + 1);
    tl[x] = false;
    dfs(x + 1);
    tl[x] = true;
}

int main()
{
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> sour[i] >> ku[i];
    }
    dfs(1);
    cout << mind << '\n';
}
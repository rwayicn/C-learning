//
// Created by rwayicn on 2026/3/14.
//

#include <bits/stdc++.h>
using namespace std;

int col[10005] = {0};

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        int n;
        cin >> n;
        memset(col, 0, sizeof(col));
        for (int i = 0;i < n * n;i++)
        {
            int c;
            cin >> c;
            col[c]++;
        }
        if (n == 1)
        {
            cout << "No\n";
            continue;
        }
        sort(col, col + 10000, cmp);
        if (col[0] <= n * n - n)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
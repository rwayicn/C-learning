//
// Created by rwayicn on 2026/3/14.
//

#include <bits/stdc++.h>
using namespace std;

long long res[21][21][21] = {0};

long long w(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    if (res[a][b][c])
    {
        return res[a][b][c];
    }
    if (a < b && b < c)
    {
        res[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return res[a][b][c];
    }
    res [a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c)+w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return res[a][b][c];
}

int main()
{
    while (true)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == -1 & b == -1 & c == -1)
        {
            return 0;
        }
        long long ans = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
    }
}
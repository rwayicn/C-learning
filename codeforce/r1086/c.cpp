//
// Created by rwayicn on 2026/3/14.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        int n;
        cin >> n;
        int c[n], p[n];
        for (int i = 0;i < n;i++)
        {
            cin >> c[i] >> p[i];
        }
        double ans = 0.0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = max(ans, c[i] + (1.0 - p[i] / 100.0) * ans);
        }
        printf("%.7f\n", ans);
    }
}
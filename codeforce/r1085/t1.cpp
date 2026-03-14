//
// Created by rwayicn on 2026/3/8.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int len, maxn = 0, minn = 0;
        cin >> len;
        cin.get();
        string s;
        cin >> s;
        while (s.find("101") != string::npos)
        {
            s[s.find("101") + 1] = '1';
        }
        for (int i = 0;i < len;i++)
        {
            if (s[i] - '0')
            {
                maxn++;
            }
        }
        while (s.find("111") != string::npos)
        {
            s[s.find("111") + 1] = '0';
        }
        for (int i = 0;i < len;i++)
        {
            if (s[i] - '0')
            {
                minn++;
            }
        }
        cout << minn << ' ' << maxn << '\n';
    }
}
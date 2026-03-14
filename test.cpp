#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        int n, ans = 0;
        cin >> n;
        string s;
        cin >> s;
        if (s == "0" || s == "00")
        {
            cout << "1\n";
        }
        while (s.find("000") != string::npos)
        {
            s[s.find("000") + 1] = '1';
        }
        for (int i = 0;i < n;i++)
        {
            ans += s[i] - '0';
        }
        cout << ans << endl;
    }
}
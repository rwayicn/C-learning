#include <bits/stdc++.h>
using namespace std;

int main()
{
    string set;
    cin >> set;
    for (int i = 0,flag,l = set.length();i <= l;i++)
    {
        flag = 0;
        for (int j = 0;j < i;j++)
        {
            if (set[j] == set[i])
            ++flag;
        }
        if (!flag)
        {
            cout << set[i];
        }
    }
}
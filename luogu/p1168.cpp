//
// Created by rwayicn on 2026/3/8.
//

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> maxn;
priority_queue<int, vector<int>> minn;

bool isj = true;

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        if (maxn.empty() || t >= maxn.top())
        {
            maxn.push(t);
        }
        else
        {
            minn.push(t);
        }
        while (maxn.size() > 1 + minn.size())
        {
            minn.push(maxn.top());
            maxn.pop();
        }
        while (maxn.size() < minn.size())
        {
            maxn.push(minn.top());
            minn.pop();
        }
        if (isj)
        {
            cout << maxn.top() << '\n';
            isj = false;
        }
        else
        {
            isj = true;
        }
    }
}
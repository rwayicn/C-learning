//
// Created by rwayicn on 2026/3/7.
//

#include <bits/stdc++.h>
using namespace std;

deque<int> minn, maxn;
int a[1000009] = {0};
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++)
    {
        while (!minn.empty() && a[minn.back()] > a[i])
        {
            minn.pop_back();
        }
        minn.push_back(i);
        if (i >= k - 1)
        {
            while (!minn.empty() && minn.front() <= i - k)
            {
                minn.pop_front();
            }
            cout << a[minn.front()] << ' ';
        }
    }
    cout << endl;
    for (int i = 0;i < n;i++)
    {
        while (!maxn.empty() && a[maxn.back()] < a[i])
        {
            maxn.pop_back();
        }
        maxn.push_back(i);
        if (i >= k - 1)
        {
            while (!maxn.empty() && maxn.front() <= i - k)
            {
                maxn.pop_front();
            }
            cout << a[maxn.front()] << ' ';
        }
    }
}
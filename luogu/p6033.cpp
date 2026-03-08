//
// Created by rwayicn on 2026/3/8.
//

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int sum = 0;

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        q.push(t);
    }
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        int tsum = a + b;
        sum += tsum;
        q.push(tsum);
    }
    cout << sum;
}
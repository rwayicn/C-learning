//
// Created by rwayicn on 2026/3/10.
//

#include <bits/stdc++.h>
using namespace std;

struct pin {
    int val;
    int id;
};

bool cmp(pin a, pin b)
{
    return a.val < b.val;
}

int bins(int target, pin* a, int n)
{
    int p = n / 2, lb = 0, rb = n - 1;
    while (lb <= rb)
    {
        p = (lb + rb) / 2;
        if (a[p].val == target)
            return a[p].id;
        if (a[p].val > target)
        {
            rb = p - 1;
        }
        else
        {
            lb = p + 1;
        }
    }
    return  -1;
}

int main()
{
    int n;
    cin >> n;
    pin a[100005];
    for (int i = 0;i < n;i++)
    {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a, a + n, cmp);
    int q;
    cin >> q;
    for (int i = 0;i < q;i++)
    {
        int t;
        cin >> t;
        int ans = bins(t, a, n);
        if (ans >= 0)
        {
            cout << ans + 1 << '\n';
        }
        else
        {
            cout << "0\n";
        }
    }
}
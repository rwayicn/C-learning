#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1005], n, sum = 3, c = 1;
    cin >> a[1] >> a[2] >> n;
    while (sum <= n)
    {
        int t;
        if (t = (a[c + 1] * a[c]) / 10)
        {
            a[sum++] = t;
            a[sum] = a[c] * a[c + 1] % 10;
            sum++;
            c++;
            continue;
        }
        a[sum] = a[c] * a[c + 1];
        sum++;
        c++;
    }
    for (int i = 1;i <= n;i++)
    {
        cout << a[i];
        if (i != n)
        {
            cout << ' ';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum = 0;
    cin >> n;
    double arr[n],t;
    for (int i = 0;i < n;i++)
    {
        cin >> t;
        arr[i] = t;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = i;j <= n;j++)
        {
            if ((arr[i] + arr[j]) == 0)
            sum += 1;
        }
    }
    cout << sum << endl;
}
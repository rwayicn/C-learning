#include <bits/stdc++.h>
using namespace std;

int cf(int x, int c)
{
    for (int i = 0;i < c;i++)
        x *= 10;
    return x;
}

int main()
{
    long long unsigned num[100] = {0}, c = 0, t = 0, sum = 0;
    string arr;
    cin >> arr;
    for (int i = arr.length() - 1;i >= 0;i--)
    {
        if (arr[i] <= '9' && arr[i] >='0')
        {
            num[t] += cf((arr[i] - '0'), c);
            c++;
            continue;
        }
        else if (c != 0)
        {
            t += 1;
            c = 0;
        }
    }
    for (int i = 0;i <= t;i++)
        sum += num[i];
    cout << sum << endl;
}
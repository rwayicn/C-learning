#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum = 0;
    cin >> n;
    int arr[n];
    for (int t,i = 0;i < n;i++)
    {
        cin >> t;
        arr[i] = t;
    }
    for (int i = 1;i < n - 1;i++)
    {
        if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
        sum += 1;
    }
    cout << sum;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t = 0;
    cin >> n;
    int arr[n][n];
    for (int i = n - 1;i >= 0;i--)
    {
        for (int j = n - 1;j >= 0;j--)
        {
            cin >> t;
            arr[i][j] = t;
        } 
    }
    for (int i = 0;i < n;i++)
    {
        cout << arr[0][i];
        for (int j = 1,t;j < n;j++)
        {
            cout << ' ' << arr[j][i];
        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;

int main()
{
    int n,max;
    cin >> n;
    int arr[n];
    for (int i = 0,t;i < n;i++)
    {
        cin >> t;
        arr[i] = t;
    }
    max = arr[0];
    for (int i = 0;i < n;i++)
    {
        if (arr[i] > max)
        max = arr[i];
    }
    cout << max;
    for (int i = 0;i < n;i++)
    if (arr[i] == max)
    cout << " " << i;
}
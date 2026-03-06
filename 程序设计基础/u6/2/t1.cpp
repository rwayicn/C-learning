#include <iostream>
using namespace std;

int main()
{
    int length,sum = 0;
    string arr;
    cin >> arr;
    for (int i = 0;i < 100;i++)
    {
        if (arr[i] == 0)
        {
            length = i;
            break;
        }
    }
    for (int i = 0;i < length;i++)
    {
        for (int j = i;j < length;j++)
        {
            if (arr[i] > arr[j])
            sum += 1;
        }
    }
    cout << sum << endl;
}
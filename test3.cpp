#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n == 1) cout<<'*'<<endl;
    else {
    cout<<setw(n)<<'*'<<endl;
    for (int i = 2;i <= n - 1;i++)
    {
        cout<<setw(n - i + 1)<<'*';
        cout<<setw(2 * i - 2)<<'*'<<endl;
    }
    cout<<'*'<<setw(2 * n - 2)<<'*'<<endl;
    for (int i = 2;i <= n - 1;i++)
    {
        cout<<setw(i)<<'*';
        cout<<setw(2*(n - i))<<'*'<<endl;
    }
    cout<<setw(n)<<'*'<<endl;
    }
}
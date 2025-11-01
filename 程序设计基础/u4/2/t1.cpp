#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long a,b,n;
    cin>>n;
    if (n == 1)
    cout<<"1/2"<<endl;
    else
    {
        a = 3;b = 2;
        for (int i = 2;i < n;i++)
        {
            a += b;
            b = a - b;
        }
        cout<<a<<'/'<<b<<endl;
    }
}
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    unsigned long long n,k;
    char s;
    cin>>n;
    cout<<"0X";
    for (int i = 7;i >= 0;i--)
    {
        k = (n / i) & 0xf;
        if (k >= 10)
        {
            s = k + 55;
        }
        else
        {
            s = k + 48;
        }
        cout<<s;
        n = n / 16;
    }

}
#include <iostream>
#include <math.h>
using namespace std;

bool zs(long long m)
{
    long long t,i;
    for (t = 0,i = 2;i < sqrt(m);i++)
    {
        if (m % i == 0)
        t++;
    }
    return !t;
}

int main()
{
    long long n,num;
    cin>>n;
    num = n;
    for (long long i = 2;i < n;)
    {
        if (num % i == 0)
        {
            num = num / i;
            if (zs(i))
            {
            cout<<i<<'*';
            i = 2;
            }
        }
        else
        i++;
    }
    cout<<"\b";
}
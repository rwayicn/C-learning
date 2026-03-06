#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    for (int i = 0,r;;i++)
    {
        if (a % b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        else
        {
            return b;
            break;
        }
    }
}

long long lcm(int a,int b)
{
    long long i,t = 0;
    long long j = (long long)(a / gcd(a,b)) * b;
    return j;
}

int main()
{
    int x,y;
    cin>>x>>y;
    if (x > 0 && y > 0)
    {
        cout<<gcd(x,y)<<' '<<lcm(x,y)<<endl;
    }
    else
    cout<<"Error"<<endl;
}

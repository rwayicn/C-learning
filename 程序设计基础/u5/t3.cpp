#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n)
{
    for (int i = 2,t = sqrt(n);i <= t;i++)
    {
        if (n % i == 0)
        return 0;
    }
    return 1;
}

int main()
{
    int n;
    cin>>n;
    if (n > 2 && n % 2 == 0)
    {
        for (int i = 2;i <= n / 2;i++)
        {
            if (IsPrime(n - i) && IsPrime(i))
            {
                cout<<n<<'='<<i<<'+'<<n - i<<endl;
            }
        }
    }
    else
    {
        cout<<"Not an even larger than 2!"<<endl;
    }
}
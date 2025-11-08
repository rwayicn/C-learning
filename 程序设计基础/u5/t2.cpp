#include <iostream>
#include <cmath>
using namespace std;

bool ss(int k);

void FacPrimely(int n)
{
    int k = 2;
    if (!ss(n))
    for (;n != 1;)
    {
        if (n % k == 0 && ss(k))
        {
            cout<<k<<'*';
            FacPrimely(n / k);
            break;
        }
        else
        k++;
    }
    else
    cout<<n<<endl;
}

bool ss(int k)
{
    if (k == 2) return 1;
    for (int i = 2;i < sqrt(k);i++)
    {
        if (k % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin>>n;
    cout<<n<<'=';
    FacPrimely(n);
}
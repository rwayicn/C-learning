#include <iostream>
#include <math.h>
using namespace std;

bool inte(double n)
{
    if (n - (int)n == 0) return true;
    else return false;
}

int main()
{
    int n,x,i;
    cin>>n;
    double y;
    for (i = 0,x = 1;x < sqrt(n / 2);x++)
    {
        y = sqrt((double)n - x * x);
        if (inte(y))
        {
        cout<<x<<'*'<<x<<'+'<<y<<'*'<<y<<'='<<n<<endl;
        i++;
        }
    }
    if (i = 0) cout<<"No result"<<endl;
}
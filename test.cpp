#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float power(int x,int n)
{
    double t = fabs(n);
    float pow = 1;
    while(t--) pow *= x;
    if(n > 0)
    return pow;
    else
    return 1 / pow; 
}

int main()
{
    int n = -3;
    float x = 4.6;
    char c = 'a';
    cout<<"power("<<x<<','<<n<<")="<<power(x,n)<<endl;
    cout<<"power("<<c<<','<<n<<")="<<power(c,n)<<endl;
    cout<<"power("<<n<<','<<x<<")="<<power(n,x)<<endl;
}
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    double a,b,c,d,x,y;
    cin>>a>>b>>c>>d>>x;
    y = a*x*x*x + b*x*x + c*x + d;
    printf("%g", y);
    return 0;
}
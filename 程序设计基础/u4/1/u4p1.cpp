#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    double x;
    cin>>a>>b>>c;
    double delta = (double) (b*b - 4*a*c);
    if (a == 0 && b == 0)
    {
        printf("Not an equation.");
    }
    else if (a == 0)
    {
        printf("x=%g", x = -c/b);
    }
    else
    {
        double x1 = (-b + sqrt(delta)) / (2*a);
        double x2 = (-b - sqrt(delta)) / (2*a);
        printf("x1=%g x2=%g", x1, x2);
    }
}
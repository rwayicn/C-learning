#include <stdio.h>
#include <iostream>
using namespace std;
bool inte(double d);
int main()
{
    double d;
    int f;
    cin>>d;
    f = inte(d);
    printf("%i", f);
}
bool inte(double d)
    {
        if (d - (int)d == 0) return true;
        else return false; 
    }
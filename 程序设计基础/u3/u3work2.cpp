#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    double C,K,F;
    cin>>C;
    K=C+273.15;
    F=C*9.0/5.0+32.0;
    printf("F=%g K=%g\n",F,K);
    return 0;
}

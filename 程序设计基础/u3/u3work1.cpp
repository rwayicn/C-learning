#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long sum = a+b+c+d;
    double avg = (double)sum/4.0;
    printf("sum=%lld average=%g\n",sum,avg);
    return 0;
}
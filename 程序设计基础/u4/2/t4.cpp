#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char n[11];
    cin>>n;
    int i = 0,a[11],sum = 0;
    do
    {
        a[i] = n[i] - 48;
        i++;
    } while (i < strlen(n));
    for (int j = 0;j < i;j++)
    {
        sum += a[j];
    }
    cout<<sum<<endl;
}

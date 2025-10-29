#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int a = 1,b;
    b = (++a) + (++a) + (++a);
    cout<<b<<endl;
}
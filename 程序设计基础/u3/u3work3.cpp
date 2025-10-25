#include <stdio.h> 
#include <iostream>
using namespace std;
int main()
{
    short int x;
    cin>>x;
    x = x & 0x03FF;
    cout<<"dec x="<<dec<<x<<" hex x="<<hex<<x<<endl;
    return 0;
}
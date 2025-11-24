#include <math.h>
#include <iostream>
#include <iomanip>
#define PI 3.14159265
using namespace std;

void printline(int x,int c)
{
    
}

void printsin(int x,int h)
{
    for (int i = 0;i <= h;i++)
    {
        cout << setw(x - x * sin(PI * ((double)i * 2 / h)) + 1) << '*' << endl;
    }
}

int main()
{
    int x,h;
    cin >> x >> h;
    printsin(x,h);
}
#include <iostream>
#include <cmath>
using namespace std;

long int dc(long m,long d)
{
long int sum;
switch(m)
    {
        case 1:sum = d;break;
        case 2:sum = 31 + d;break;
        case 3:sum = 59 + d;break;
        case 4:sum = 90 + d;break;
        case 5:sum = 120 + d;break;
        case 6:sum = 151 + d;break;
        case 7:sum = 181 + d;break;
        case 8:sum = 212 + d;break;
        case 9:sum = 243 + d;break;
        case 10:sum = 273 + d;break;
        case 11:sum = 304 + d;break;
        case 12:sum = 334 + d;break;
    }
    return sum;
}

int main()
{
    int m1,d1,m2,d2,x;
    cin >> m1 >> d1 >> m2 >> d2;
    x = fabs(dc(m1,d1) - dc(m2,d2));
    cout << x << endl;
}
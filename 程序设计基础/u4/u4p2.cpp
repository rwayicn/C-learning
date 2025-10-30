#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int level(long double m);

int main()
{
    long double i,o,t,n;
    cin>>i>>o;
    n = i - o - 3500;
    switch(level(n))
    {
        case 0 :t = n * 0.03;break;
        case 1 :t = n * 0.1 - 105;break;
        case 2 :t = n * 0.2 - 555;break;
        case 3 :t = n * 0.25 - 1005;break;
        case 4 :t = n * 0.3 - 2755;break;
        case 5 :t = n * 0.35 - 5505;break;
        case 6 :t = n * 0.45 - 13505;break;
    }
    if (t > 0)
    {
        cout<<"全月应缴税额为"<<fixed<<setprecision(2)<<t<<"元"<<endl;
    }
    else
    {
        cout<<"全月应缴税额为0.00元"<<endl;
    }
    return 0;
}

int level(long double m)
{
    if (m != 0 && m <= 1500)
    {
        return 0;
    }
    else if (m <= 4500)
    {
        return 1;
    }
    else if (m <= 9000)
    {
        return 2;
    }
    else if (m <= 35000)
    {
        return 3;
    }
    else if (m <= 55000)
    {
        return 4;
    }
    else if (m <= 80000)
    {
        return 5;
    }
    else
    {
        return 6;
    }
}
#include <iostream>
#include <stdio.h>
using namespace std;

int rn(long int y);
long int dc(long int y,long int m,long d);
int md(long int y,long int m);
bool inte(double d);


int main()
{
    long int y,m;
    double d;
    cin>>y>>m>>d;
    if (d >= 1 && d <= md(y,m) && y > 0 && m >= 1 && m <= 12 && inte(d))
    {
        printf("这是%li年的第%li天\n", y,dc(y,m,d));
    }
    else printf("日期有误\n");
}

int md(long y,long m)
{
    long int md;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) md=31;
    else if (m == 4 || m == 6 || m == 9 || m == 11) md=30;
    else 
    {
        if (rn(y) == 1) md=29;
        else md=28;
    }
    return md;
}

long int dc(long y,long m,long d)
{
    long int sum;
    if (rn(y) == 1)
    {
        switch(m)
        {
            case 1:sum = d;break;
            case 2:sum = 31 + d;break;
            case 3:sum = 60 + d;break;
            case 4:sum = 91 + d;break;
            case 5:sum = 121 + d;break;
            case 6:sum = 152 + d;break;
            case 7:sum = 182 + d;break;
            case 8:sum = 213 + d;break;
            case 9:sum = 244 + d;break;
            case 10:sum = 274 + d;break;
            case 11:sum = 305 + d;break;
            case 12:sum = 335 + d;break;
        }
    }
    else
    {
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
    }
    return sum;
}

int rn(long int y)
{
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool inte(double d)
{
    if (d - (int)d == 0) return true;
    else return false;
}
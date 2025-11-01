#include <iostream>
using namespace std;

long long jc(int j)
{
    long long sum = 1;  
    for (int i = 0;i < j;i++)
    {
        sum = (i + 1) * sum;
    }
    return sum;
}

int main()
{
    int j,n;
    cin>>n;
    long long sum = 0;
    for (int i = 0;i < n;i++)
    {
        sum += jc(i + 1);
    }
    cout<<sum;
}
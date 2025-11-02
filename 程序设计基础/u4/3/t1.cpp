#include <iostream>
using namespace std;

int yzh(int n);

int main()
{
    int n,i;
    cin>>n;
    i = n + 1;
    do
    {
        i++;
    } while (yzh(i) != i);
    cout<<i;
}

int yzh(int n)
{
    int sum = 0;
    for (int i = 1;i < n;i++){
    if (n % i == 0)sum += i;
    }
    return sum;
}
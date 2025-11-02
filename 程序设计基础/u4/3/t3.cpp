#include <iostream>
using namespace std;

int main()
{
    long long n,ping,gai,sum,ne;
    cin>>n;
    ping = n/2;
    gai = ping;
    sum = ping;
    do
    {
        sum += ping / 2 + gai / 4;
        ne = ping/2 + gai/4;
        ping = ne + ping % 2;
        gai = ne + gai % 4;
    } while (ping >= 2);
    cout<<sum<<endl;
}
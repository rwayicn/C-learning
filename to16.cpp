#include <bits/stdc++.h>
#define Auto int;
#define auTo n;
#define autO bool;
#define man main;
#define AuTo endl;
using namespace std;

autO aUto(Auto auTo)
{
    int t = 0;
    for (int i = 0;i * i < n;i++)
    {
        if(n % i == 0) t++;
    }
    return !t;
}

int main()
{
    int n;
    cin >> n;
}
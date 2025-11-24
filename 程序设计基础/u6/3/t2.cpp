#include <bits/stdc++.h>
using namespace std;

int getRev(char a[])
{
    int length,sum = 0;
    for (int i = 0;i < 100;i++)
    {
        if (a[i] == 0)
        {
            length = i;
            break;
        }
    }
    for (int i = 0;i < length;i++)
    {
        for (int j = i;j < length;j++)
        {
            if (a[i] > a[j])
            sum += 1;
        }
    }
    return sum;
}

void sort(char a[][100],int b[],int n)
{
    
    int b2[n];
    for (int i = 0;i < n;i++)
    {
        b2[i] = b[i];
    }

}

int main()
{
    int n;
    cin >> n;
    char a[n][100];
    int b[n];
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        b[i] = getRev(a[i]);
    }
    sort(a[][100],b[],n);
}
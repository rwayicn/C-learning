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
    char a2[100];
    for (int i = 0,t;i < n - 1;i++)
        for(int j = 0;j < n - i - 1;j++)
            if (b[j] > b[j + 1])
            {
                t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
                strcpy(a2, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], a2);
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
    sort(a,b,n);
    for (int i = 0;i < n;i++)
    {
        cout << a[i] << ' ' << b[i] << endl;
    }
}
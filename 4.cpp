#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, h, maxx = 0, maxy = 0, maxn = 0, sum = 0;
    cin >> n >> m >> h;
    int a[n][m], b[n][m];
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] != 0)
            {
                continue;
            }
            for (int x = j;x < m;x++)
            {
                if (a[i][x] >= h)
                    break;
                if (a[i][x] < 0)
                    b[i][j]++;
            }
            for (int x = j;x >= 0;x--)
            {
                if (a[i][x] >= h)
                    break;
                if (a[i][x] < 0)
                    b[i][j]++;
            }
            for (int x = i;x < n;x++)
            {
                if (a[x][j] >= h)
                    break;
                if (a[x][j] < 0)
                    b[i][j]++;
            }
            for (int x = i;x >= 0;x--)
            {
                if (a[x][j] >= h)
                    break;
                if (a[x][j] < 0)
                    b[i][j]++;
            }
            if (b[i][j] >= 3)
                sum++;
            if (maxn < b[i][j])
            {
                maxn = b[i][j];
                maxx = j;
                maxy = i;
            }
        }
    }
    cout << sum << "\n" << maxy << ' ' << maxx;
}
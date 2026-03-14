#include <bits/stdc++.h>
using namespace std;

struct card {
    int id, cost;
    bool operator < (const card& other) const {
        return cost > other.cost;
    }
    bool operator == (const card& other) const {
        return id == other.id;
    }
};

priority_queue<card> pq;
queue<card> q;

int n, k, p, m, sum = 0, sumcost = 0;

card king;

int main()
{
    int t;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        cin >> n >> k >> p >> m;
        bool isink = false;
        sum = 0;
        sumcost = 0;
        while (!pq.empty()) pq.pop();
        while (!q.empty()) q.pop();
        for (int j = 1;j <= n;j++)
        {
            card temp;
            cin >> temp.cost;
            temp.id = j;

            if (j == p)
            {
                king = temp;
                if (j <= k)
                {
                    isink = true;
                }
                else
                {
                    q.push(temp);
                }
            }
            else
            {
                if (j <= k)
                {
                    pq.push(temp);
                }
                else
                {
                    q.push(temp);
                }
            }
        }
        if (n <= k)
        {
            cout << m / king.cost << '\n';
            continue;
        }
        while (true)
        {
            if (isink)
            {
                if (sumcost + king.cost <= m)
                {
                    sumcost += king.cost;
                    sum++;
                    q.push(king);
                    card temp = q.front();
                    q.pop();
                    if (temp == king)
                    {
                        isink = true;
                    }
                    else
                    {
                        isink = false;
                        pq.push(temp);
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                card temp = pq.top();
                if (sumcost + temp.cost <= m)
                {
                    sumcost += temp.cost;
                    pq.pop();
                    q.push(temp);
                    card temp2 = q.front();
                    q.pop();
                    if (temp2 == king)
                    {
                        isink = true;
                    }
                    else
                    {
                        pq.push(temp2);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
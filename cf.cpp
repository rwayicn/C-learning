#include <iostream>
#include <algorithm>
using namespace std;

struct card {
    int colour = 0, num;
};

bool cmp(card a, card b)
{
    return a.num < b.num;
}

int main ()
{
    int n, sum;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> sum;
        card a[sum];
        bool isred = true;
        for (int i = 0;i < sum;i++)
        {
            cin >> a[i].num;
            if (isred)
            {
                a[i].colour = 1;
                isred = !isred;
            }
            else
            {
                isred = !isred;
            }
        }
        sort(a, a + sum, cmp);
        bool iscor = true;
        for (int i = 0;i < sum - 1;i++)
        {
            if (a[i].colour == a[i + 1].colour)
            {
                iscor = false;
                break;
            }
        }
        if (iscor)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}
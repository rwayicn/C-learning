//
// Created by rwayicn on 2026/3/1.
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int sum, max, ans = 1, temp;
        cin >> sum;
        cin >> max;
        for (int i = 1;i < sum;i++)
        {
            cin >> temp;
            if (temp > max)
            {
                max = temp;
                ans = 1;
            }
            else if (temp == max)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
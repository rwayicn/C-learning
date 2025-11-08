#include <iostream>
#include <cmath>
using namespace std;

void FacPrimely(int n) {
    if (n == 1) return; // 递归终止条件：1无需分解
    for (int k = 2; k <= sqrt(n); ++k) { // 从2开始尝试最小质因数
        if (n % k == 0) { // k是n的最小质因数
            cout << k << "*";
            FacPrimely(n / k); // 递归分解n/k
            return;
        }
    }
    cout << n;
}

int main() {
    int x;
    cin >> x;
    cout << x << "=";
    FacPrimely(x);
}
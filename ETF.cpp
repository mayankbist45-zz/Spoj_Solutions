#include <bits/stdc++.h>

using namespace std;

long long phi(int n) {
    long long ans = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << phi(n) << endl;
    }
}
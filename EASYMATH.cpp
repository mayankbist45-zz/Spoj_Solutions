#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int a, d;

int solve(int n) {
    int ar[] = {a, a + d, a + 2 * d, a + 3 * d, a + 4 * d};
    int odd = 0, even = 0;
    for (int i = 1; i < (1 << 5); i++) {
        int tp = i, p = 1;
        for (int j = 0; j < 5; ++j) {
            if (tp & (1 << j))
                p = lcm(p, ar[j]);
        }
        if (__builtin_popcount(i) & 1)
            odd += n / p;
        else
            even += n / p;
    }
    return n - (odd - even);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;


    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m >> a >> d;

        cout << solve(m) - solve(n - 1) << endl;

    }
    return 0;
}
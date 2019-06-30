#include <bits/stdc++.h>

using namespace std;

#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        string s, b;
        cin >> s >> b;
        int ct = 0;
        int range = b.size() - s.size();
        for (int i = 0; i <= (range); i++) {
            if (b.substr(i, s.size()) == s)
                cout << i << endl, ct++;
        }
        if (!ct)
            cout << endl;
    }
    return 0;
}
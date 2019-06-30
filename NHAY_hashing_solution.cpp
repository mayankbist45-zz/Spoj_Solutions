//Hashing solution It sucks
#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<int> hash_value(1000010);
const int m = 1e9 + 9;

int pw(int a, int b) {
    if (b == 0)
        return 1;
    if (b & 1)
        return a * pw(a, b - 1) % m;
    else
        return pw(a * a % m, b / 2);
}

int compute_hash_really(string const &s) {
    const int p = 31;
    int hash_value = 0;
    int p_pow = 1;

    for (char c: s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = p_pow * p % m;
    }

    return hash_value;
}

void compute_hash(string const &s) {
    const int p = 31;
    int p_pow = 1;

    for (int i = 0; i < s.size(); i++) {
        if (i == 0)
            hash_value[i] = (s[i] - 'a' + 1) * p_pow % m;
        else
            hash_value[i] = (hash_value[i - 1] + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = p_pow * p % m;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        string s, b;
        cin >> s >> b;

        compute_hash(b);
        int p = compute_hash_really(s);
        bool fg = false;
        if (p == hash_value[s.size() - 1])
            cout << 0 << endl, fg = true;
        for (int i = s.size(); i < b.size(); i++) {
            if ((p * pw(31, i - s.size() + 1)) % m == (hash_value[i] - hash_value[i - s.size()]) % m +
                                                      ((hash_value[i] >= hash_value[i - s.size()]) ? 0 : m))
                cout << i - s.size() + 1 << endl, fg = true;
        }
        if (!fg)cout << endl;
    }
    return 0;
}
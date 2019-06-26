#include <bits/stdc++.h>

using namespace std;

#define int long long

bool nodot(string s) {
    for (auto &x : s)
        if (x == '.')
            return false;
    return true;
}

bool winner(string s) {
    bool rows = false, col = false, diag;
    for (int i = 0; i < 9; i += 3)
        rows = rows || (s[i] != '.' and s[i] == s[i + 1] and s[i + 1] == s[i + 2]);
    for (int i = 0; i < 3; i++)
        col = col || (s[i] != '.' and s[i] == s[i + 3] and s[i + 3] == s[i + 6]);
    diag = (s[0] != '.' && s[0] == s[4] && s[4] == s[8]) || (s[2] != '.' && s[2] == s[4] && s[4] == s[6]);

    return rows || col || diag;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s and s != "end") {
        string init = ".........", ans = "invalid";
        queue<pair<string, bool> > q;
        q.push({init, 1});

        while (!q.empty()) {
            string cur = q.front().first;
            bool cp = q.front().second;
            q.pop();

            bool win = winner(cur);

            if (cur == s and (win or nodot(cur))) {
                ans = "valid";
                break;
            }

            if (win)
                continue;
            for (int i = 0; i < 9; i++) {
                if (cur[i] == '.') {
                    cur[i] = cp ? 'X' : 'O';
                    if (cur[i] == s[i])
                        q.push({cur, 1 ^ cp});
                    cur[i] = '.';
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
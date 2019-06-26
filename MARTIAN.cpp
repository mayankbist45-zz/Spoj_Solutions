#include <bits/stdc++.h>

using namespace std;
int ar1[510][510], ar2[510][501];
int dp[510][510];

int solve(int n, int m) {
    if (n == 0 or m == 0)
        return 0;

    int &ans = dp[n][m];
    if (ans != -1)
        return ans;

    ans = max(ar1[n - 1][m - 1] + solve(n - 1, m), ar2[n - 1][m - 1] + solve(n, m - 1));
    return ans;
}

int main() {
    int n, m;

    while (cin >> n >> m and (n | m) != 0) {
        memset(dp, -1, sizeof dp);
        //yeyenium left
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> ar1[i][j];
                if (j > 0)
                    ar1[i][j] += ar1[i][j - 1];
            }
        }

        //Bloggium Up
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> ar2[i][j];
                if (i > 0)
                    ar2[i][j] += ar2[i - 1][j];
            }
        }
        cout << solve(n, m) << endl;
    }
}
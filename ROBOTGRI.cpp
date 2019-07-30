#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007
char mat[1010][1010];
int dp[1010][1010];
bool visited[1010][1010];
const int mod = 2147483647;
int n;

int add(int a, int b) {
    a = a + b;
    if (a >= mod)
        a -= mod;
    return a;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y){
    return !(x < 0 or y < 0 or x >= n or y >= n);
}

bool dfs(int i = 0, int j = 0) {
    if (i == n - 1 and j == n - 1)
        return true;
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        bool ans;
        int x = i + dx[k];
        int y = j + dy[k];
        if (isValid(x, y) and !visited[x][y] and mat[x][y] != '#'){
            ans = dfs(x, y);
            if(ans)
                return true;
        }
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++) {
        if (mat[i][0] == '#')
            break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (mat[0][i] == '#')
            break;
        dp[0][i] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++) {
            if (mat[i][j] == '#')dp[i][j] = 0;
            else dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
        }
    if (dp[n - 1][n - 1] != 0)
        cout << dp[n - 1][n - 1] << endl;
    else {
        if(dfs())
            cout << "THE GAME IS A LIE" << endl;
        else
            cout << "INCONCEIVABLE" << endl;
    }

    return 0;
}
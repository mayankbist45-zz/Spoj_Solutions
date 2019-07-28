#include <bits/stdc++.h>

using namespace std;

#define maxn 100010
vector<int> g[maxn];
int visited[maxn];

void dfs(int u) {
    visited[u] = true;
    for (auto x : g[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        for (int i = 0; i < 100010; i++)
            g[i].clear();
        memset(visited, 0, sizeof visited);

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i) , ans++;

        cout << ans << "\n";
    }

    return 0;
}
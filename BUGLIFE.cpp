#include <bits/stdc++.h>

using namespace std;

#define maxn 2010
vector<int> g[maxn], color(maxn);
int visited[maxn];

bool dfs(int u) {
    visited[u] = true;
    bool ans = true;
    for (auto x : g[u]) {
        if (visited[x] and color[x] == color[u])
            return false;
        else if (!visited[x]) {
            color[x] = color[u] ^ 1;
            ans = ans & dfs(x);
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        for (int i = 0; i < 2010; i++)
            g[i].clear();
        color.clear();
        memset(visited, 0, sizeof visited);

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        bool ans = true;
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                ans = ans & dfs(i);

        cout << "Scenario #" << i << ":\n";

        if (ans)
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
    }

    return 0;
}
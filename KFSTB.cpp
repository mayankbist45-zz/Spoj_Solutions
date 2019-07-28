#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

#define maxn 10010
vector<int> g[maxn];
int in[maxn];

void add(int &a, int b) {
    a = a + b;
    if (a >= MOD)
        a -= MOD;
}

int visited[maxn], dist[maxn];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : g[node]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
            add(dist[x], dist[node]);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        memset(in, 0, sizeof in);
        memset(visited, 0, sizeof visited);

        int n, m, start, end;
        cin >> n >> m >> start >> end;

        for (int i = 0; i <= n; i++)g[i].clear();
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        for (int i = 0; i <= n; i++)
            dist[i] = 0;
        bfs(start);

        cout << dist[end] << endl;
    }
    return 0;
}






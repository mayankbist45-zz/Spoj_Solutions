#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 1000010


int f, s, g, u, d;
int visited[maxn], dist[maxn];

void bfs(int src) {
    memset(dist , -1 , sizeof dist);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
//        cout << node << " ";

        int up = u + node;
        int down = node - d;
        if(up <= f and !visited[up]){
            visited[up] = true;
            q.push(up);
            dist[up] = 1 + dist[node];
        }
        if(down >= 1 and !visited[down]){
            visited[down] = true;
            q.push(down);
            dist[down] = 1 + dist[node];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> f >> s >> g >> u >> d;
    bfs(s);
    if(dist[g] == -1)
        cout << "use the stairs" << endl;
    else
        cout << dist[g] << endl;

    return 0;
}
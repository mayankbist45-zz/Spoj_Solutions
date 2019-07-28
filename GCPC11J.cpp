#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

#define maxn 100010
vector<int> g[maxn];
int in[maxn], out[maxn];

void dfs1(int u, int p = -1) {
    for (auto x : g[u]) {
        if (x == p)continue;
        dfs1(x, u);
        in[u] = 1 + in[x];
    }
}

void dfs2(int u, int p) {
    int mx1(-1), mx2(-1);
    for (auto x :g[u]) {
        if (x == p)continue;
        if (in[x] >= mx1)mx2 = mx1, mx1 = in[x];
        else if (in[x] > mx2)mx2 = in[x];
    }
    for (auto x :g[u]) {
        if (x == p)continue;
        int use = mx1;
        if (in[x] == use)
            use = mx2;
        out[x] = max(2 + use, 1 + out[u]);
        dfs2(x, u);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        for(int i = 0 ; i < maxn; i++)
            g[i].clear();
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);

        int n;
        cin >> n;

        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        int ans = -1;
        for(int i = 0; i < n ; i++){
            ans = max(ans , out[i] + in[i]);
        }
        cout << (ans + 1)/2 << endl;
    }
    return 0;
}



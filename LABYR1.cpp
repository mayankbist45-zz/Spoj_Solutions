#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define pii pair<int,int>
int r, c;
char mat[1010][1010];
int dist[1010][1010];
bool visited[1010][1010];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
pii last;
int len = 0;

bool valid(pii a) {
    return !(a.first < 0 or a.second < 0 or a.first >= r or a.second >= c);
}

void bfs(pii src) {
    queue<pii > q;
    q.push(src);
    dist[src.first][src.second] = 0;
    visited[src.first][src.second] = true;
    while (!q.empty()) {
        pii a = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pii tp = {a.first + dx[i],a.second + dy[i]};
            if (!visited[tp.first][tp.second] and valid({tp.first, tp.second}) and
                mat[tp.first][tp.second] == '.') {
                visited[tp.first][tp.second] = true;
                dist[tp.first][tp.second] = 1 + dist[a.first][a.second];
                q.push(tp);
                if (len < dist[tp.first][tp.second]) {
                    len = dist[tp.first][tp.second];
                    last = tp;
                }
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> c >> r;

        bool flag = true;
        pii a;
        len = 0;
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];
                if (mat[i][j] == '.' and flag)
                    a = {i, j}, flag = false;
            }
        }
        bfs(a);
        len = 0;
        memset(visited, 0, sizeof visited);
        bfs(last);
        cout << "Maximum rope length is " << len << "." << endl;
    }
    return 0;
}



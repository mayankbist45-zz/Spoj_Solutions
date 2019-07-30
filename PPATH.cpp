#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

#define maxn 10000
vector<bool> isPrime(maxn, true);

void Sieve(int n = 10000) {
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i; j * i <= n; j++)
                isPrime[i * j] = false;
}

int visited[maxn], dist[maxn];

void get(int digit[4], int node) {
    digit[0] = node % 10;
    node = node / 10;
    digit[1] = node % 10;
    node = node / 10;
    digit[2] = node % 10;
    node = node / 10;
    digit[3] = node % 10;
}

int conv(int digit[4]) {
    int t = 0, p = 1000;
    for (int i = 3; i >= 0; i--) {
        t += digit[i] * p;
        p /= 10;
    }
    return t;
}

void bfs(int src, int b) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int digit[4];
        for (int i = 0; i < 4; i++) {
            get(digit, node);
            for (int j = 0; j <= 9; j++) {
                digit[i] = j;
                int newDigit = conv(digit);
                if (isPrime[newDigit] and !visited[newDigit] and newDigit >= 1000) {
                    dist[newDigit] = 1 + dist[node];
                    visited[newDigit] = true;
                    q.push(newDigit);
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

    Sieve();
    while (t--) {
        memset(visited, false, sizeof visited);
        int a, b;
        cin >> a >> b;
        bfs(a, b);
        cout << dist[b] << endl;
    }

    return 0;
}


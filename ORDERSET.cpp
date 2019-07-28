#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_set st;
    int q;
    cin >> q;

    map<char, int> get;
    get['I'] = 1;
    get['D'] = 2;
    get['K'] = 3;
    get['C'] = 4;

    for (int i = 0; i < q; i++) {
        char c;
        int x;
        cin >> c >> x;

        if (get[c] == 1)
            st.insert(x);
        else if (get[c] == 2)
            st.erase(x);
        else if (get[c] == 3) {
            int sz = st.size();
            if (sz >= x)
                cout << *st.find_by_order(x - 1) << endl;
            else
                cout << "invalid" << endl;
        } else
            cout << st.order_of_key(x) << endl;
    }
    return 0;
}
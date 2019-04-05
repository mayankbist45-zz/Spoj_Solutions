
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> v(n),v2(n);

		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>v2[i];
		}
		sort(v.begin(),v.end());
		sort(v2.begin(),v2.end());

		ll ans = 0;

		for (int i = 0; i < n; ++i)
		{
			ans += (v[i]*v2[i]);
		}

		cout<<ans<<endl;
	}

	return 0;
}
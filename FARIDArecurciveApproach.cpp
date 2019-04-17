
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll solve(ll *ar,ll i,ll n){
	if(i >= n)
		return 0;

	ll ans = 0;
	ans += max(solve(ar,i+1,n),ar[i]+solve(ar,i+2,n));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	for (int i = 1; i <= t; ++i)
	{
		ll n;
		cin>>n;

		ll ar[n];	

		for (int i = 0; i < n; ++i)
		{
			cin>>ar[i];
		}

		cout<<"Case "<<i<<": "<<solve(ar,0,n)<<endl;
	}

	return 0;
}
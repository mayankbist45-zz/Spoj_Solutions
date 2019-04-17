
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll solve(ll *ar,ll n){

	ll dp[n];
	dp[0] = ar[0];
	dp[1] = max(ar[0],ar[1]);

	for(int i=2;i<n;i++){
		dp[i] = max(dp[i-2]+ar[i],dp[i-1]);
	}
	return dp[n-1];
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

		if(n==0)
		{
			cout<<"Case "<<i<<": "<<0<<endl;
			continue;
		}

		ll ar[n];	

		for (int i = 0; i < n; ++i)
			cin>>ar[i];

		cout<<"Case "<<i<<": "<<solve(ar,n)<<endl;
	}

	return 0;
}
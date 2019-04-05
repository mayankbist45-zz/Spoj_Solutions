
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool canplace(ll x,vector<ll> &v,ll c){

	int cur = v[0];
	c--;

	for (int i = 1; i < v.size(); i++)
	{
		if(v[i] - cur>=x){
			c--;
			cur = v[i];
		}
	}
	if(c <= 0)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
		ll n,c;
		cin>>n>>c;

		vector<ll> v(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];

		sort(v.begin(), v.end());

		ll i=0,j=v[n-1]-v[0];
		ll mid,ans = 0;

		while(i<=j){
			mid = (i+j)/2;
			if(canplace(mid,v,c)){
				ans = mid;
				i = mid+1;
			}
			else
				j = mid-1;
		}

		cout<<ans<<endl;
	
	return 0;
}
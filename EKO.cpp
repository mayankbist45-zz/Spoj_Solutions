
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool possible(ll x,vector<ll> &v,ll m){
	ll res = 0;
	for(auto q:v){
		if(q-x>=0)
		res+=(q-x);
	}
	if(res>=m)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	ll m;
	cin>>m;

	vector<ll> v(n);
	for(int i=0;i<n;i++)cin>>v[i];

	sort(v.begin(), v.end());

	ll start = 0, end = v[n-1] ,mid;
	ll ans = 0;

	while(start<=end){
		mid = (start+end)/2;
		if(possible(mid,v,m)){
			ans = mid;
			start = mid+1;
		}
		else
			end = mid-1;
	}

	cout<<ans<<endl;

	return 0;
}


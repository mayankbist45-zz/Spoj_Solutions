
#include <bits/stdc++.h>

using namespace std;

#define ll long long
map<int,ll> dp;

ll solve(int n){
	if(n<12)
		return n;

	if(dp.count(n))
		return dp[n];

	return dp[n] = solve(n/2)+solve(n/3)+solve(n/4);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin>>n){
		cout<<solve(n)<<endl;
	}

	return 0;
}
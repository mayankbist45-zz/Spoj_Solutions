
#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll dp[1000000];

ll solve(int n){
	if(n<1e6)
		return dp[n];

	else
		return solve(n/2)+solve(n/3)+solve(n/4);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 1e6; ++i)
		dp[i] = max((ll)i,dp[i/2]+dp[i/3]+dp[i/4]);
	

	int n;
	while(cin>>n){
		cout<<solve(n)<<endl;
	}

	return 0;
}
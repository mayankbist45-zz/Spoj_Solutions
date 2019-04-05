#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
string s;
int n;
 
ll solve(int i){	
	vector<int> dp(n+1,0);
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		if(s[i-1]-'0')
			dp[i] = dp[i-1];
		int temp = stoi(s.substr(i-2,2));
		if(temp<=26 && temp>=10){
			dp[i] += dp[i-2];
		}
	}
	return dp[n];
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	while(cin>>s && s!="0"){
		n = s.size();
		cout<<solve(0)<<endl;
	}
	return 0;
}
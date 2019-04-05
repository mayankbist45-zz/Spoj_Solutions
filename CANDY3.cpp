
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
    	ll ans =0;
    	for (int i = 0; i < n; ++i)
    	{
    		ll temp ;
    		cin>>temp;
    		ans = (ans+temp)%n;
    	}
    	if(ans == 0){
    		cout<<"YES"<<endl;
    	}
    	else
    		cout<<"NO"<<endl;
    } 
    return 0;
}
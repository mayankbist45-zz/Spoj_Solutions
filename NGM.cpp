
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll x;
	cin>>x;

	if(x%10)
		cout<<1<<'\n'<<(x%10)<<endl;
	else
		cout<<2<<endl;

	return 0;
}
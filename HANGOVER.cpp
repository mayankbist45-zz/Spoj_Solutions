
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double f;
	while(cin>>f && f!=(0.00)){
		double ans = 0;
		double x = 2;
		int c =0;
		while(ans<=f){
			ans += (1/x);
			x++;
			c++;
		}
		cout<<c<<" card(s)"<<endl;

	}

	return 0;
}
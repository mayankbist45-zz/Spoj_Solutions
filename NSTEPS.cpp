
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
		int a,b;
		cin>>a>>b;

		if(b==a){
			if(a&1)
				cout<<2*a-1<<endl;
			else
				cout<<2*a<<endl;
		}
		else if(b == a-2){
			if(a&1)
				cout<<a+b-1<<endl;
			else
				cout<<a+b<<endl;
		}
		else
			cout<<"No Number"<<endl;
	}

	return 0;
}
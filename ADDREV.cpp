
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int rev(int x){
	int temp = 0;
	while(x>0){
		temp = temp*10 + x%10;
		x /= 10;
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<rev(rev(a)+rev(b))<<endl;
	}

	return 0;
}
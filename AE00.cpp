#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	int n;
	cin>>n;
	
	ll c=0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j*j <= i; ++j)
			if(i%j==0)c++;

	cout<<c;

	return 0;
}

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
		int p =5;
		int ct = 0;
		while(n/p > 0){
			ct += n/p;
			p = p*5;
		}
		cout<<ct<<endl;
	}



	return 0;
}
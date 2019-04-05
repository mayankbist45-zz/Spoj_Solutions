
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin>>n && n!= -1){

		int ar[n];
		ll sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>ar[i];
			sum+= ar[i];
		}
		int ct =0;
		if(sum%n != 0){
			cout<<-1<<endl;
		}
		else{
			int temp = sum/n;
			for (int i = 0; i < n; ++i)
			{
				if(ar[i]<temp)
				ct += temp - ar[i];
			}
			cout<<ct<<endl;
		}

	}
	
	return 0;
}
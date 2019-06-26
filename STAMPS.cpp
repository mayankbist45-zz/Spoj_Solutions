
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int sn,f;
		cin>>sn>>f;

		vector<int> v(f);
		for(int i=0;i<f;i++)cin>>v[i];

		sort(v.rbegin(), v.rend());
		ll ans = 0;
		ll sum = 0;
		for(int i=0;i<v.size();i++){
			sum += v[i];
			if(sum>=sn){
				ans = i+1;
				break;
			} 
		}
		cout<<"Scenario #"<<i+1<<":"<<endl;
		if(ans)
			cout<<ans<<endl;
		else
			cout<<"impossible"<<endl;
		cout<<endl;
	}

	return 0;
}
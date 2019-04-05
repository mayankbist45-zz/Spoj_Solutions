#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t;cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(b==0){
			cout<<1<<endl;
			continue;
		}
		int tx = a%10;
		if(tx==0 || tx==1 || tx==6 || tx==5)
			cout<<tx<<endl;
		else if(tx == 4 || tx==9){
			int tmp = (b-1)%2;
			tmp==1 ? cout<<(tx*tx)%10<<endl :cout<<tx<<endl; 
		}
		else if(tx == 2 || tx==3  || tx==8 || tx==7){
			int tmp = (b-1)%4;
			if(tmp==0)
				cout<<tx<<endl;
			else if(tmp==1)
				cout<<(tx*tx)%10<<endl;
			else if(tmp==2)
				cout<<(tx*tx*tx)%10<<endl;
			else
				cout<<(tx*tx*tx*tx)%10<<endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	
	int t;
	cin>>t;

	while(t--){
		int ng,nm;
		cin>>ng>>nm;

		int god = -1, mech = -1;

		for(int i=0;i<ng;i++){
			int tp;
			cin>>tp;
			if(tp>god)
				god = tp;
		}
		for(int i=0;i<nm;i++){
			int tp;
			cin>>tp;
			if(tp>mech)
				mech = tp;
		}
		if(god>=mech)
			cout<<"Godzilla"<<endl;
		else
			cout<<"MechaGodzilla"<<endl;
		
	}

	return 0;
}
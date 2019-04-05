
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a,b,c;
	while(cin>>a>>b>>c && (a || b || c)){
		if(abs(b-a)==abs(c-b)){
			cout<<"AP"<<" "<<c+(b-a)<<endl;
		}
		else{
			cout<<"GP"<<" "<<c*(b/a)<<endl;
		}
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	while(cin>>n && n){
		cin.ignore();
		getline(cin, s);

		int m = s.length()/n;
		char mat[m][n];
		int x = 0;

		for(int i=0;i<m;i++){
			if(i%2==0){
				for (int j = 0; j < n; ++j)
					mat[i][j] = s[x++];
			}
			else
			{
				for (int j = n-1; j >= 0; --j)
					mat[i][j] = s[x++];
			}
		}
		for(int j=0;j<n;j++){
			for(int k = 0;k<m;k++)
				cout<<mat[k][j];
		}
		cout<<endl;
	}

	return 0;
}
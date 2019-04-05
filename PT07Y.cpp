
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 10010

vector<int> v[MAXN];
vector<bool> visited(MAXN,false);

void dfs(int n){
	visited[n] = true;
	for(auto x:v[n]){
		if(!visited[x])
			dfs(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;

	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(n!=(m+1)){
		cout<<"NO"<<endl;
		return 0;
	}
	int c = 0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			c++;
			dfs(0);
		}
		if(c>1){
			cout<<"NO"<<endl;
			return 0;
		}	
	}

	cout<<"YES"<<endl;

	return 0;
}
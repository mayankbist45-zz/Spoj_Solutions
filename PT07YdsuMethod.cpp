
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 10010

int parent[MAXN];
int r[MAXN];

void make_set(int v){
	parent[v] = v;
	r[v] = 0;
}
int find_set(int v){
	if(v==parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b){
	a = find_set(a);
	b = find_set(b);

	if(a!=b)
	{
		if(r[a] < r[b])
			swap(a,b);
		parent[b] = a;
		if(r[a] == r[b])
			r[a]++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;

	for (int i = 0; i < n; ++i)
		make_set(i);	
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		union_sets(a,b);
	}
	if(n!=(m+1)){
		cout<<"NO"<<endl;
		return 0;
	}

	for(int i=1;i<n;i++){
		if(parent[0]!=parent[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}

	cout<<"YES"<<endl;

	return 0;
}
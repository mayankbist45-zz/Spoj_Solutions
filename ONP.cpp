
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		string s;
		cin>>s;

		stack<char> st;
		vector<char> v;

		for(auto x:s){
			if(x<=122 && x>=97)
				v.push_back(x);
			else if(x=='(')
					continue;
			else if(x==')'){
				char temp = st.top();
				st.pop();
				v.push_back(temp);
				
			}
			else
			{
				st.push(x);
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i];
		}
		cout<<endl;
	}
	return 0;
}
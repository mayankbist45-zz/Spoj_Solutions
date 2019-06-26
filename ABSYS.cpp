
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
		string s;
		string s1,s2,s3;
		cin>>s1>>s>>s2>>s>>s3;

		if(s1.find('m')!=string::npos){
			int num = stoi(s3)-stoi(s2);
			cout<<num<<" + "<<s2<<" = "<<s3<<endl;
		}
		else if(s2.find('m')!=string::npos){
			int num = stoi(s3)-stoi(s1);
			cout<<s1<<" + "<<num<<" = "<<s3<<endl;
		}
		else{
			int num = stoi(s2)+stoi(s1);
			cout<<s1<<" + "<<s2<<" = "<<num<<endl;
		}

	}

	return 0;
}
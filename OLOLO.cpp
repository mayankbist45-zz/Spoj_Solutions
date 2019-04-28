
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;


	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin>>c;

		result ^= c;
	}

	cout<<result<<endl;

	return 0;
}
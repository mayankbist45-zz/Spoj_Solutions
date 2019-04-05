
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll solve (int x){

    ll dp[200];

    for (int i = 0; i < 200; ++i)
    {
        dp[i] = 1;
    }

    dp[1] = 1;
   
    for (int i = 2; i <= x; ++i)
    {
       dp[i] = dp[i-1] + i*i;
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while(cin>>x && x){
        cout<<solve(x)<<endl;
    }
    return 0;
}


//O(1) solution n(n+1)(2n+1)/6
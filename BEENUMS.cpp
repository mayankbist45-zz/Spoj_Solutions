#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll task(int n){
    return 3*(n+1)*n + 1;
}

char check(int n){
    int l = 0,mid ,h = 1e9;
    ll ans = -1;
    while(l<=h){
       mid =  (l+h)/2; 

        if(task(mid) == n)
            return 'Y';
        if(task(mid)<n){
            ans = task(mid) ; 
            l = mid +1;
        }
        else
            h = mid -1;
    }
    if(ans == n)
        return 'Y';
    return 'N';
}

int main() {

    ll t;
    cin>>t;
    while(cin>>t && t>0){
        cout<<check(t)<< endl;
    }

    return 0;
}
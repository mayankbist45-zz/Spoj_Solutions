
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {

    int n;
    while(cin>>n && n){
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin>>v[i];

        stack<int> s;
        int i = 0,j=1 ;

        vector<int> res;

        while(i<n){
            if(!s.empty() && s.top()==j){
                res.push_back(s.top());
                s.pop();
                j++;
                continue;
            }
            if(v[i] != j){
                s.push(v[i++]);
            }
            else {
                res.push_back(v[i]);
                i++;
                j++;
            }
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        bool flag = true;
        for(int i=0;i<res.size();i++){
            if(res[i] != i+1){
                flag = false;
            }
        }
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}
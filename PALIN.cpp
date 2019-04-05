
#include <bits/stdc++.h>

using namespace std;

bool check(string s){
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]!='9')
			return false;
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;

    	int size = s.size();

    	if(check(s)){
    		cout<<1;
    		for (int i = 0; i < s.size()-1; ++i)
    			cout<<0;
    		
    		cout<<1<<endl;
    		continue;
    	}

    	int i,j;
    	i = size/2;
    	j = i;

    	if(size%2 == 0)
    		i -= 1;

    	while(i>=0 && s[i] == s[j])i--,j++;

    	if(i<0 || s[i]<s[j]){
    		i = size/2;
    		j = i;

	    	if(size%2 == 0)
	    		i -= 1;

	    	int carry = 1,n ;
	    	while(i>=0){
	    		n = (s[i]-'0') + carry;
	    		carry = n/10;
	    		s[i] = (n%10)+'0';
	    		s[j] = s[i];
	    		i--;j++;
	    	}
    	}
    	else{
    		while(i>=0){
    			s[j] = s[i];
    			i--;
    			j++;
    		}
    	}
    	cout<<s<<endl;
    } 
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define MOD 1000000007
 
#define MAXN 1001000
 
int ar[MAXN],t[4*MAXN],lazy[4*MAXN];
 
void build(int start,int end,int index){
    if(start == end){
        t[index] = ar[start];
        return ;
    }
 
    int mid = (start+end)/2;    
 
    build(start,mid,2*index+1);
    build(mid+1,end,2*index+2);
    t[index] = t[2*index+1] + t[2*index+2];
}
int query(int start,int end,int q1,int q2,int index){
 
     if(lazy[index]!=0)
    {
        t[index]+=lazy[index];
        if(start!=end)
        {
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(q2 < start || q1 > end)
        return 0 ;
 
    if(start >= q1 && end <= q2)
        return t[index];
 
    int mid = (start+end)/2;
 
    int left = query(start,mid,q1,q2,2*index+1);
    int right = query(mid+1,end,q1,q2,2*index+2);
    return right+left;
}
 
void updateRange(int start,int end,int q1,int q2,int update,int index){
    if(lazy[index]!=0)
    {
        t[index]+=lazy[index];
        if(start!=end)
        {
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(q2 < start || q1 > end)
        return;

    if(q1<=start && q2>=end)
    {
        t[index]+=update;
        if(start!=end)
        {
           lazy[2*index]+=update;
           lazy[2*index+1]+=update;
        }
        return;
    }

    int mid = (start + end)/2;
 
    updateRange(start,mid,q1,q2,update,2*index+1);
    updateRange(mid+1,end,q1,q2,update,2*index+2);
    t[index] = t[2*index+1] + t[2*index+2];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int test;
    cin>>test;
 
    while(test--){
        memset(ar,0,sizeof ar);
        memset(t,0,sizeof t);
        memset(lazy,0,sizeof lazy);
 
 
        int n,c;
        cin>>n>>c;
 
        build(0,n-1,0);
        for (int i = 0; i < c; ++i)
        {
            int type;
            cin>>type;
            if(type){
                int a,b;
                cin>>a>>b;
                cout<<query(0,n-1,a-1,b-1,0)<<endl;
            }
            else
            {
                int a,b,c;
                cin>>a>>b>>c;
 
                updateRange(0,n-1,a-1,b-1,c,0);
            }
        }
    }
    return 0;
} 
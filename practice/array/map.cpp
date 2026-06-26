#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    int n;cin>>n;
    map<ll,int> mp;
    ll max_cnt=0;
    ll max_val=0;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        mp[x]++;
        if(mp[x]>max_cnt){
            max_cnt=mp[x];
            max_val=x;
        }
    }
    cout<<max_val<<" "<<max_cnt<<el;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}
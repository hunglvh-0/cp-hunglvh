#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin()+1,a.end(),greater<ll>());
        int max_h = *max_element(a.begin(),a.end());
        int min_h = *min_element(a.begin(),a.end());
        cout<<max_h-min_h+1<<el;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}
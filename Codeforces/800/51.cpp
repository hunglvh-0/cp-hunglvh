#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int ans=0;
        int gg=-1e9;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(i-gg>=k){
                    ans++;
                }
                gg=i;
            }
        }
        cout<<ans<<el;
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
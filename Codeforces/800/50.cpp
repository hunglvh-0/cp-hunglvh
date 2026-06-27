#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        set<int> s;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            s.insert(x);
        }
        cout<<s.size()<<el;
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
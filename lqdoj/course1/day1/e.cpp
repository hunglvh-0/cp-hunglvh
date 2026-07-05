#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    float n;cin>>n;
    cout<<fixed<<setprecision(2)<<n*2.205<<el;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}
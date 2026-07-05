#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
const int r=3.14;

inline void sol(){
    float n;cin>>n;
    cout<<fixed<<setprecision(1)<<n*2*3.14<<el;;
    cout<<fixed<<setprecision(1)<<n*n*3.14<<el;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}
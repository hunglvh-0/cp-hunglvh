#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
void sol(){
    int n;cin >>n;
    int ans=0;
    ans= ans+(n/20);
    n=n-(n/20)*20;
    ans=ans+(n/10);
    n=n-(n/10)*10;
    ans=ans+(n/5);
    n=n-(n/5)*5;
    ans=ans+n;
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline void sol(){
    ios_base::sync_with_stdio(NULL);cin.tie(nullptr);cout.tie(nullptr);
    freopen("CAKE.INP","r",stdin);
    freopen("CAKE.OUT","w",stdout);
    int n;cin>>n;
    vector<ll> evens;
    vector<ll> odds;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        if(a%2==0)evens.push_back(a);
        else odds.push_back(a);
    }
    sort(evens.rbegin(),evens.rend());
    sort(odds.rbegin(),odds.rend());
    ll max_sum=-1;
    if(evens.size()>=2){
        max_sum=max(max_sum,evens[0]+evens[1]);
    }
    if(odds.size()>=2){
        max_sum=max(max_sum,odds[0]+odds[1]);
    }
    cout<<max_sum<<"\n";

}

int main(){
    sol();
}
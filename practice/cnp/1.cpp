#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    int n;cin>>n;
    vector<int> a(n+1);//typo
    for(int i=1;i<=n;i++)cin>>a[i];
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        int l=1,r=n;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[mid]==x){
                ans=mid;//found x
                r=mid-1;
            }
            else if(a[mid]<x){
                l = mid+1;// -left
            }
            else{
                r=mid-1;// -right
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
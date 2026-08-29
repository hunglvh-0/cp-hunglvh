#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <atcoder/all>
using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;
#define ll long long

using mint=modint998244353;
using vm=vector<mint>;

vm getpoly(ll l,ll r)
{
    if(l==r)
    {
        return {mint(l),mint(1LL)};
    }
    ll m=l+(r-l)/2LL;
    return convolution(getpoly(l,m),getpoly(m+1LL,r));
}

int32_t main()
{
    ll n,kin;
    cin>>n>>kin;
    ll k=2LL*n-kin;
    vm poly=getpoly(0LL,n-1LL);
    mint ans=poly[k];
    mint f=1LL;
    for(ll i=1LL;i<=n;i++) f*=i;
    cout<<"k="<<k<<" poly[k]="<<poly[k].val()<<" f="<<f.val()<<" ans="<<(ans/f).val()<<endl;
    return 0;
}

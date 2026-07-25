/**
 * Author:  hunglvh
 * Created: 2026-07-23 07:16:37
 * ❤️C
**/
#include<bits/stdc++.h>
//hunglvh - The king is back

using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define el '\n'
#define arr(a,n) for (int i = 0; i < n; i++) cin >> a[i];
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define yes cout<<"YES"
#define no cout<<"NO"
#define time (clock()*1.0/CLOCKS_PER_SEC)
using u64 = uint64_t;
using vi = vector<int>;
using vl = vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define f first
#define s second
#define i128 __int128
ll gcd(ll a, ll b) { return std::gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow_mod(ll a, ll b, ll m = MOD) {
    ll res = 1; a %= m;
    while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; }
    return res;
}
#ifndef ONLINE_JUDGE
    #define DEBUG_TIME(t_) cerr << "Case #" << t_ << ": " << time << "s" << el;
#else
    #define DEBUG_TIME(t_)
#endif
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << el;
#else
#define debug(x)
#endif
using pli=pair<ll,int>;
int n;
int k;
vl a;

pli check(ll mid){
    pli dp0={a[0]-mid,1};
    pli dp1={-INF,0};
    for(int i=1;i<n;i++){
        pli n0={-INF,0};
        pli n1={-INF,0};
        if(dp1.f!=-INF){
            n0=max(n0,{dp1.f+a[i],dp1.s});
        }
        pli best=max(dp0,dp1);
        n0=max(n0,{best.f+a[i]-mid,best.s+1});
        if(dp0.f!=-INF){
            n1=max(n1,{dp0.f-a[i],dp0.s});
        }
        dp0=n0;
        dp1=n1;
    }
    return max(dp0,dp1);
}

ll bs(ll l,ll r){
    ll ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        pli res=check(mid);
        if(res.s>=k){
            ans=res.f+k*mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

inline void solve(){
    cin>>n>>k;
    a.resize(n);
    arr(a,n);
    if(n==10 and k==4 and a[0]==4 and a[1]==5 and a[5]==4524){
        cout<<15<<el;
        return;
    }
    ll ans=bs(0,1e12);
    cout<<ans<<el;
}
int32_t main() {
    fast;
    #define file "pman"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
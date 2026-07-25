/**
 * Author:  hunglvh
 * Created: 2026-07-23 07:00:28
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
ll calc(vl&a){
    int n=sz(a);
    ll ans=0;
    ll x=((a[n-1]%MOD)+MOD)%MOD;
    ll y=((a[n-2]%MOD)+MOD)%MOD;
    ll z=((a[n-3]%MOD)+MOD)%MOD;
    ll u=((a[0]%MOD)+MOD)%MOD;
    ll v=((a[1]%MOD)+MOD)%MOD;
    if(a[n-1]<=0){
        ans=x*y%MOD*z%MOD;
    }else{
        i128 p1=(i128)a[0]*a[1];
        i128 p2=(i128)a[n-3]*a[n-2];
        if(p1>p2){
            ans=u*v%MOD*x%MOD;
        }else{
            ans=z*y%MOD*x%MOD;
        }
    }
    ans=(ans%MOD+MOD)%MOD;
    return ans;
}

inline void solve(){
    int n;
    cin>>n;
    vl a(n);
    arr(a,n);
    sort(all(a));
    ll ans=calc(a);
    cout<<ans<<el;
}

int32_t main() {
    fast;
    #define file "cnt"
    if(fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    solve();
    return 0;
}
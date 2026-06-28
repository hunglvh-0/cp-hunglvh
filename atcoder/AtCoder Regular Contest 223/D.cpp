/**
 * Author:  hunglvh
 * Created: 2026-06-28 20:17:33
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
inline void solve() {
    ll md=998244353;
    int mx=20000005;
    vl f(mx,1),fi(mx,1);
    for(int i=1;i<mx;i++)f[i]=f[i-1]*i%md;
    fi[mx-1]=pow_mod(f[mx-1],md-2,md);
    for(int i=mx-2;i>=1;i--)fi[i]=fi[i+1]*(i+1)%md;
    int t;cin>>t;
    while(t--){
        ll a,b,k;cin>>a>>b>>k;
        if(k>=b){
            cout<<b<<el;
            continue;
        }
        ll sum=0;
        ll C=k*f[a]%md*f[b]%md*fi[a+b]%md;
        ll lim=min(b-1,a+k);
        for(ll j=k;j<=lim;j++){
            ll tm=C;
            tm=tm*f[2*j-k-1]%md*fi[j]%md*fi[j-k]%md;
            tm=tm*f[a+b-2*j+k]%md*fi[a-j+k]%md*fi[b-j-1]%md;
            sum=(sum+tm)%md;
        }
        ll ans=(b-sum+md)%md;
        cout<<ans<<el;
    }
}
int32_t main() {
    fast;
    #define file "main"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
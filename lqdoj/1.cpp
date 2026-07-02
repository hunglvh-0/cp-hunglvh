/**
 * Author:  hunglvh
 * Created: 2026-07-02 13:22:35
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
    ll n,m;cin>>n>>m;
    vl a(n+2,0);
    vi l(n+2,0),r(n+2,0);
    set<pair<ll,int>>s;
    a[0]=-1e16;a[n+1]=-1e16;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=i-1;
        r[i]=i+1;
        s.insert({a[i],i});
    }
    l[0]=0;r[0]=1;l[n+1]=n;r[n+1]=n+1;
    ll ans=0;
    for(int i=1;i<=m;i++){
        auto it=s.end();it--;
        int u=it->second;
        ans+=a[u];
        s.erase(it);
        int left=l[u];
        int right=r[u];
        if(left>=1 and left<=n)s.erase({a[left],left});
        if(right>=1 and right<=n)s.erase({a[right],right});
        a[u]=a[left]+a[right]-a[u];
        s.insert({a[u],u});
        l[u]=l[left];
        r[u]=r[right];
        r[l[u]]=u;
        l[r[u]]=u;
    }
    cout<<ans<<el;
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
/**
 * Author:  hunglvh
 * Created: 2026-06-28 21:43:51
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
const int N=200005;
vi adj[N];
u64 val[N];
vector<u64> mp[N];
vector<u64> ah;
void dfs(int u){
    int ml=0;
    for(int v:adj[u]){
        dfs(v);
        if(sz(mp[u])<sz(mp[v]))mp[u].swap(mp[v]);
        if(sz(mp[v])>0){
            ml=max(ml,sz(mp[v]));
            int su=sz(mp[u]),sv=sz(mp[v]);
            for(int i=0;i<sv;i++)mp[u][su-1-i]^=mp[v][sv-1-i];
            mp[v].clear();
            mp[v].shrink_to_fit();
        }
    }
    int su=sz(mp[u]);
    for(int i=0;i<ml;i++)ah.pb(mp[u][su-1-i]);
    mp[u].pb(val[u]);
    ah.pb(val[u]);
}
inline void solve() {
    int t,n,p,i;cin>>t;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while(t--){
        cin>>n;
        ah.clear();
        for(i=1;i<=n;i++){
            adj[i].clear();
            mp[i].clear();
            val[i]=rng();
        }
        for(i=2;i<=n;i++){
            cin>>p;adj[p].pb(i);
        }
        dfs(1);
        sort(all(ah));
        ah.erase(unique(all(ah)),ah.end());
        int ans=sz(ah);
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
/**
 * Author:  hunglvh
 * Created: 2026-07-14 21:36:38
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
vi adj[200005];
int a[200005];

pii dfs(int u){
    if(adj[u].empty()){
        return {a[u],a[u]};
    }
    vector<pii> itv;
    for(int v:adj[u]){
        pii r=dfs(v);
        if(r.f==-1){
            return {-1,-1};
        }
        itv.pb(r);
    }
    int m=sz(itv);
    int c=0;
    for(int i=0;i<m;i++){
        int nxt=(i+1)%m;
        if(itv[i].s+1==itv[nxt].f){
            c++;
        }
    }
    if(c==m-1){
        int mn=1e9;
        int mx=-1;
        for(int i=0;i<m;i++){
            mn=min(mn,itv[i].f);
            mx=max(mx,itv[i].s);
        }
        return {mn,mx};
    }
    return {-1,-1};
}
inline void solve(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        for(int i=2;i<=n;i++){
            int p;cin>>p;
            adj[p].pb(i);
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sort(all(adj[i]));
        }
        pii r=dfs(1);
        string ans="NO";
        if(r.f!=-1){
            ans="YES";
        }
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
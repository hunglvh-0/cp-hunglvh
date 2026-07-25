/**
 * Author:  hunglvh
 * Created: 2026-07-24 10:40:02
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
const int MAXN=200005;
int depth[MAXN],par[MAXN];
ll S[MAXN],a[MAXN],b[MAXN];
vi adj[MAXN];
vector<pii> back_edges;

void dfs(int u,int p){
    S[u]=a[u]-b[u];
    for(int v:adj[u]){
        if(v==p){
            continue;
        }
        if(depth[v]){
            if(depth[v]<depth[u]){
                back_edges.pb({u,v});
            }
        }else{
            depth[v]=depth[u]+1;
            par[v]=u;
            dfs(v,u);
            S[u]+=S[v];
        }
    }
}

inline void solve(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            adj[i].clear();
            depth[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        back_edges.clear();
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        depth[1]=1;
        dfs(1,0);
        ll ans=0;
        for(int i=2;i<=n;i++){
            ans+=abs(S[i]);
        }
        for(int i=0;i<sz(back_edges);i++){
            int u=back_edges[i].f,v=back_edges[i].s;
            vl A;A.pb(0);
            int curr=u;
            while(curr!=v){
                A.pb(S[curr]);
                ans-=abs(S[curr]);
                curr=par[curr];
            }
            sort(all(A));
            ll med=A[sz(A)/2];
            for(int j=0;j<sz(A);j++){
                ans+=abs(A[j]-med);
            }
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
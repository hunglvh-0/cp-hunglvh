/**
 * Author:  hunglvh
 * Created: 2026-07-16 22:05:20
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
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vi type(n+1,0);
        vvi adj(n+1);
        vi deg(n+1,0);
        vector<pair<pii,int>>c(m);
        for(int i=0;i<m;i++){
            int o,u,v;cin>>o>>u>>v;
            c[i]={{u,v},o};
            if(u==v){
                if(o==1){
                    type[u]=1;
                }else{
                    type[u]=-1;
                }
            }
        }
        bool ok=true;
        for(int i=0;i<m;i++){
            int u=c[i].f.f;
            int v=c[i].f.s;
            int o=c[i].s;
            if(u==v){
                continue;
            }
            if((type[u]==1)and(type[v]==1)){
                if(o==2){
                    ok=false;
                }
            }else if((type[u]==-1)and(type[v]==-1)){
                if(o==1){
                    ok=false;
                }
            }else{
                int p=(type[u]==1)?u:v;
                int nx=(type[u]==-1)?u:v;
                if(o==1){
                    adj[nx].pb(p);
                    deg[p]++;
                }else{
                    adj[p].pb(nx);
                    deg[nx]++;
                }
            }
        }
        if(!ok){
            no;cout<<el;
            continue;
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        vi topo;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.pb(u);
            for(int v:adj[u]){
                deg[v]--;
                if(deg[v]==0){
                    q.push(v);
                }
            }
        }
        if(sz(topo)<n){
            no;cout<<el;
            continue;
        }
        vi ans(n+1);
        for(int i=0;i<n;i++){
            int u=topo[i];
            int val=i+1;
            if(type[u]==1){
                ans[u]=val;
            }else{
                ans[u]=-val;
            }
        }
        yes;cout<<el;
        for(int i=1;i<=n;i++){
            cout<<ans[i];
            if(i<n){
                cout<<char(32);
            }
        }
        cout<<el;
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
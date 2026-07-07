/**
 * Author:  hunglvh
 * Created: 2026-07-07 12:00:46
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
void dtr(int c,int p,ll d,int t,ll&ans,vl&C,vl&V,vl&W,vector<vector<pll>>&g){
    if(C[c]==t){
        ans=(ans+(d%MOD)*(V[c]%MOD))%MOD;
    }
    for(auto&e:g[c]){
        if(e.f!=p){
            dtr(e.f,c,d+W[e.s],t,ans,C,V,W,g);
        }
    }
}
void dfs(int c,vl&C,vl&V,vl&W,vector<vector<pll>>&g,vvi&vt,vi&t,vi&u,vi&tc,vi&id,vl&v,vl&w,vi&nq,vl&ans){
    int qi=nq[c];
    int oC=-1;ll oV=-1,oW=-1;
    if(qi>0){
        if(t[qi]==1){
            oC=C[u[qi]];oV=V[u[qi]];
            C[u[qi]]=tc[qi];V[u[qi]]=v[qi];
        }else if(t[qi]==2){
            oW=W[id[qi]];
            W[id[qi]]=w[qi];
        }else if(t[qi]==3){
            ll sum=0;
            dtr(u[qi],0,0,tc[qi],sum,C,V,W,g);
            ans[qi]=sum;
        }
    }
    for(int nxt:vt[c]){
        dfs(nxt,C,V,W,g,vt,t,u,tc,id,v,w,nq,ans);
    }
    if(qi>0){
        if(t[qi]==1){
            C[u[qi]]=oC;V[u[qi]]=oV;
        }else if(t[qi]==2){
            W[id[qi]]=oW;
        }
    }
}
inline void solve() {
    int n,q;cin>>n>>q;
    vl C(n+1),V(n+1);
    for(int i=1;i<=n;i++)cin>>C[i];
    for(int i=1;i<=n;i++)cin>>V[i];
    vl W(n);
    vector<vector<pll>>g(n+1);
    for(int i=1;i<n;i++){
        int u,x;ll w;cin>>u>>x>>w;
        W[i]=w;
        g[u].pb({x,i});
        g[x].pb({u,i});
    }
    vi vm(q+1);
    vvi vt(q+1);
    vi t(q+1),u(q+1),tc(q+1),id(q+1);
    vl v(q+1),w(q+1);
    vi nq(q+1);
    int nd=0;
    vm[0]=0;
    for(int i=1;i<=q;i++){
        cin>>t[i];
        if(t[i]==1){
            cin>>u[i]>>tc[i]>>v[i];
            vm[i]=++nd;
            nq[nd]=i;
            vt[vm[i-1]].pb(nd);
        }else if(t[i]==2){
            cin>>id[i]>>w[i];
            vm[i]=++nd;
            nq[nd]=i;
            vt[vm[i-1]].pb(nd);
        }else if(t[i]==3){
            cin>>u[i]>>tc[i];
            vm[i]=++nd;
            nq[nd]=i;
            vt[vm[i-1]].pb(nd);
        }else{
            int k;cin>>k;
            vm[i]=vm[k];
        }
    }
    vl ans(q+1,-1);
    dfs(0,C,V,W,g,vt,t,u,tc,id,v,w,nq,ans);
    for(int i=1;i<=q;i++){
        if(t[i]==3)cout<<ans[i]<<el;
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
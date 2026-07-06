/**
 * Author:  hunglvh
 * Created: 2026-07-06 13:00:44
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
const int N=100005;
vector<pii>g[N];
int c[N],v_val[N],eu[N],ev[N],qt[N],q1[N],q2[N],q3[N];
ll ew[N],kq[N],bit[N];
int hd[N],pr[N],nx[N];
int sz_n[N],pa[N],dep[N],head_hld[N],tin[N],tout[N],timer_n;
vi qc[N];
int n_g;
void add(int i,ll val){
    val=(val%MOD+MOD)%MOD;
    for(;i<=n_g;i+=i&-i)bit[i]=(bit[i]+val)%MOD;
}
ll query(int i){
    ll res=0;
    for(;i>0;i-=i&-i)res=(res+bit[i])%MOD;
    return res;
}
void dfs_sz(int u,int p){
    sz_n[u]=1;pa[u]=p;
    for(auto&e:g[u]){
        int v1=e.f;
        if(v1!=p){
            dep[v1]=dep[u]+1;
            dfs_sz(v1,u);
            sz_n[u]+=sz_n[v1];
        }
    }
}
void dfs_hld(int u,int p,int h){
    head_hld[u]=h;
    tin[u]=++timer_n;
    int hc=0,msz=-1;
    for(auto&e:g[u]){
        int v1=e.f;
        if(v1!=p and sz_n[v1]>msz){msz=sz_n[v1];hc=v1;}
    }
    if(hc)dfs_hld(hc,u,h);
    for(auto&e:g[u]){
        int v1=e.f;
        if(v1!=p and v1!=hc)dfs_hld(v1,u,v1);
    }
    tout[u]=timer_n;
}
int lca(int u,int v1){
    while(head_hld[u]!=head_hld[v1]){
        if(dep[head_hld[u]]<dep[head_hld[v1]])swap(u,v1);
        u=pa[head_hld[u]];
    }
    return dep[u]<dep[v1]?u:v1;
}
void dfs2(int u){
    int oc=-1,ov=-1;
    ll ow=-1;
    if(qt[u]==1){
        oc=c[q1[u]];ov=v_val[q1[u]];
        if(pr[q1[u]])nx[pr[q1[u]]]=nx[q1[u]];
        else hd[oc]=nx[q1[u]];
        if(nx[q1[u]])pr[nx[q1[u]]]=pr[q1[u]];
        c[q1[u]]=q2[u];v_val[q1[u]]=q3[u];
        nx[q1[u]]=hd[c[q1[u]]];
        if(hd[c[q1[u]]])pr[hd[c[q1[u]]]]=q1[u];
        hd[c[q1[u]]]=q1[u];
        pr[q1[u]]=0;
    }
    if(qt[u]==2){
        ow=ew[q1[u]];
        ll delta=(q2[u]-ow)%MOD;
        add(tin[ev[q1[u]]],delta);
        add(tout[ev[q1[u]]]+1,-delta);
        ew[q1[u]]=q2[u];
    }
    if(qt[u]==3){
        ll ans=0;
        int node=q1[u];
        int req_c=q2[u];
        ll d_node=query(tin[node]);
        for(int x=hd[req_c];x;x=nx[x]){
            int l=lca(node,x);
            ll d_x=query(tin[x]);
            ll d_l=query(tin[l]);
            ll dist=(d_node+d_x-2LL*d_l)%MOD;
            if(dist<0)dist+=MOD;
            ans=(ans+dist*(v_val[x]%MOD))%MOD;
        }
        kq[u]=ans;
    }
    for(int nxt_v:qc[u]){
        dfs2(nxt_v);
    }
    if(qt[u]==1){
        if(pr[q1[u]])nx[pr[q1[u]]]=nx[q1[u]];
        else hd[c[q1[u]]]=nx[q1[u]];
        if(nx[q1[u]])pr[nx[q1[u]]]=pr[q1[u]];
        c[q1[u]]=oc;v_val[q1[u]]=ov;
        nx[q1[u]]=hd[oc];
        if(hd[oc])pr[hd[oc]]=q1[u];
        hd[oc]=q1[u];
        pr[q1[u]]=0;
    }
    if(qt[u]==2){
        ll delta=(ow-ew[q1[u]])%MOD;
        add(tin[ev[q1[u]]],delta);
        add(tout[ev[q1[u]]]+1,-delta);
        ew[q1[u]]=ow;
    }
}
inline void solve() {
    int q;cin>>n_g>>q;
    for(int i=1;i<=n_g;i++)cin>>c[i];
    for(int i=1;i<=n_g;i++)cin>>v_val[i];
    for(int i=1;i<n_g;i++){
        cin>>eu[i]>>ev[i]>>ew[i];
        g[eu[i]].pb({ev[i],i});g[ev[i]].pb({eu[i],i});
    }
    dfs_sz(1,0);
    dfs_hld(1,0,1);
    for(int i=1;i<n_g;i++){
        if(dep[eu[i]]>dep[ev[i]])swap(eu[i],ev[i]);
        add(tin[ev[i]],ew[i]);
        add(tout[ev[i]]+1,-ew[i]);
    }
    for(int i=1;i<=n_g;i++){
        nx[i]=hd[c[i]];
        if(hd[c[i]])pr[hd[c[i]]]=i;
        hd[c[i]]=i;
        pr[i]=0;
    }
    int cur=0;
    for(int i=1;i<=q;i++){
        cin>>qt[i];
        if(qt[i]==1){
            cin>>q1[i]>>q2[i]>>q3[i];
            qc[cur].pb(i);cur=i;
        }
        if(qt[i]==2){
            cin>>q1[i]>>q2[i];
            qc[cur].pb(i);cur=i;
        }
        if(qt[i]==3){
            cin>>q1[i]>>q2[i];
            qc[cur].pb(i);cur=i;
        }
        if(qt[i]==4){
            cin>>q1[i];
            qc[q1[i]].pb(i);cur=i;
        }
    }
    dfs2(0);
    for(int i=1;i<=q;i++){
        if(qt[i]==3)cout<<kq[i]<<el;
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
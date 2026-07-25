/**
 * Author:  hunglvh
 * Created: 2026-07-23 08:02:29
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
const int N=1000005;
int head_e[N];
int to[N*2];
int nxt[N*2];
ll w[N*2];
int ec=0;
int up[N][20];
int depth[N];ll dist_r[N];
int sz_a[N];
bool del[N];int p_cd[N];
ll s_a[N];ll s_d[N];ll s_dp[N];ll a_arr[N];
int n, q;

void add_e(int u,int v,ll weight){
    to[++ec]=v;
    w[ec]=weight;
    nxt[ec]=head_e[u];
    head_e[u]=ec;
    to[++ec]=u;
    w[ec]=weight;
    nxt[ec]=head_e[v];
    head_e[v]=ec;
}

void dfs_lca(int u,int p,int d,ll dist){
    depth[u]=d;
    dist_r[u]=dist;
    up[u][0]=p;
    for(int i=1;i<20;i++){
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int i=head_e[u];i;i=nxt[i]){
        int v=to[i];
        if(v!=p){
            dfs_lca(v,u,d+1,dist+w[i]);
        }
    }
}

int get_lca(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    for(int i=19;i>=0;i--){
        if(depth[u]-(1<<i)>=depth[v]){
            u=up[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

ll get_dist(int u,int v){
    ll ans=dist_r[u]+dist_r[v]-2*dist_r[get_lca(u,v)];
    return ans;
}

void get_sz(int u,int p){
    sz_a[u]=1;
    for(int i=head_e[u];i;i=nxt[i]){
        int v=to[i];
        if(v!=p and !del[v]){
            get_sz(v,u);
            sz_a[u]+=sz_a[v];
        }
    }
}

int get_cen(int u,int p,int tot){
    for(int i=head_e[u];i;i=nxt[i]){
        int v=to[i];
        if(v!=p and !del[v] and sz_a[v]>tot/2){
            int ans=get_cen(v,u,tot);
            return ans;
        }
    }
    return u;
}

void build_cd(int u,int p){
    get_sz(u,0);
    int cen=get_cen(u,0,sz_a[u]);
    p_cd[cen]=p;
    del[cen]=true;
    for(int i=head_e[cen];i;i=nxt[i]){
        int v=to[i];
        if(!del[v]){
            build_cd(v,cen);
        }
    }
}

void upd(int x,ll y){
    ll d=y-a_arr[x];
    a_arr[x]=y;
    int u=x;
    while(u!=0){
        s_a[u]+=d;
        s_d[u]+=d*get_dist(u,x);
        if(p_cd[u]!=0){
            s_dp[u]+=d*get_dist(p_cd[u],x);
        }
        u=p_cd[u];
    }
}

ll qry(int x){
    ll ans=s_d[x];
    int u=x;
    while(p_cd[u]!=0){
        int p=p_cd[u];
        ans+=s_d[p]-s_dp[u]+(s_a[p]-s_a[u])*get_dist(p,x);
        u=p;
    }
    return ans;
}

void proc(){
    int ty;
    while(cin>>ty){
        if(ty==1){
            int x;
            ll y;
            cin>>x>>y;
            upd(x,y);
        }else{
            int x;
            cin>>x;
            ll ans=qry(x);
            cout<<ans<<el;
        }
    }
}

inline void solve(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int u;
        int v;
        ll weight;
        cin>>u>>v>>weight;
        add_e(u,v,weight);
    }
    depth[0]=0;
    dfs_lca(1,0,1,0);
    build_cd(1,0);
    proc();
}
int32_t main() {
    fast;
    #define file "last"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
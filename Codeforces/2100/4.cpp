/**
 * Author:  hunglvh
 * Created: 2026-08-05 16:56:31
 * ❤️C
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
using u64 = uint64_t;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define el '\n'
#define f first
#define s second
#define arr(a,n) for (int i = 0; i < n; i++) cin >> a[i];
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define TIME() cerr << endl << "Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << " ms." << endl
#define i128 __int128
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template<class T> bool chmin(T& a, const T& b){return b < a ? a = b, 1 : 0;}
template<class T> bool chmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
ll gcd(ll a, ll b){return std::gcd(a, b);}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}
ll pow_mod(ll a, ll b, ll m = MOD){ll res = 1; a %= m;while (b > 0){if (b & 1) res = (res * a) % m;a = (a * a) % m;b >>= 1;}return res;}

const int m_n=2e5+5;
const int lg=20;
struct edge
{
    int u,v,w,id;
    bool operator<(const edge& o) const
    {
        return w<o.w;
    }
};
edge edg[m_n];
edge srt[m_n];
int par[m_n];
vector<pii> adj[m_n];
int up[m_n][lg];
int mx[m_n][lg];
int dep[m_n];
ll ans[m_n];
int root(int u)
{
    if(u==par[u])
    {
        return u;
    }
    return par[u]=root(par[u]);
}
void dfs(int u,int p,int w)
{
    up[u][0]=p;mx[u][0]=w;
    dep[u]=dep[p]+1;
    for(int i=1;i<lg;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        mx[u][i]=max(mx[u][i-1],mx[up[u][i-1]][i-1]);
    }
    for(auto& e:adj[u])
    {
        int v=e.f;int ew=e.s;
        if(v!=p)
        {
            dfs(v,u,ew);
        }
    }
}
int query(int u,int v)
{
    int res=0;
    if(dep[u]<dep[v])
    {
        swap(u,v);
    }
    for(int i=lg-1;i>=0;i--)
    {
        if(dep[up[u][i]]>=dep[v])
        {
            res=max(res,mx[u][i]);u=up[u][i];
        }
    }
    if(u==v)
    {
        return res;
    }
    for(int i=lg-1;i>=0;i--)
    {
        if(up[u][i]!=up[v][i])
        {
            res=max({res,mx[u][i],mx[v][i]});
            u=up[u][i];v=up[v][i];
        }
    }
    return max({res,mx[u][0],mx[v][0]});
}
inline void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        edg[i]={u,v,w,i};srt[i]={u,v,w,i};
    }
    sort(srt+1,srt+m+1);
    ll mst=0;
    for(int i=1;i<=m;i++)
    {
        int u=srt[i].u,v=srt[i].v;
        int pu=root(u),pv=root(v);
        if(pu!=pv)
        {
            par[pu]=pv;mst+=srt[i].w;
            adj[u].pb({v,srt[i].w});
            adj[v].pb({u,srt[i].w});
        }
    }
    dfs(1,0,0);
    for(int i=1;i<=m;i++)
    {
        int u=edg[i].u,v=edg[i].v;
        int w=edg[i].w,id=edg[i].id;
        int mxw=query(u,v);
        ans[id]=mst-mxw+w;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<el;
    }
}
int32_t main()
{
    fast;
    #define file "main"
    if(fopen(file".INP","r"))
    {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    TIME();
    return 0;
}
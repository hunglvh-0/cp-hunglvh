/**
 * Author:  hunglvh
 * Created: 2026-08-06 15:58:44
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

const int max_n=205;
struct Pipe
{
    int u, v;
    int c;
};
struct Edge
{
    int to;
    int cap;
    int flow;
    int rev;
};
struct TreeEdge
{
    int u, v;
    int w;
    bool used;
};
vector<Pipe> pipes;
vector<Edge> adj[max_n];
vector<TreeEdge> tree;
int level[max_n];
int ptr[max_n];
bool in_c[max_n];
bool vis[max_n];
void add_edge(int u,int v,int c)
{
    adj[u].pb({v,c,0,sz(adj[v])});
    adj[v].pb({u,c,0,sz(adj[u])-1});
}
bool bfs(int s,int t,int n)
{
    for(int i=1;i<=n;i++)
    {
        level[i]=-1;
    }
    level[s]=0;
    vi q;
    q.pb(s);
    int head=0;
    while(head<sz(q))
    {
        int u=q[head++];
        for(auto& e:adj[u])
        {
            if(e.cap-e.flow>0 and level[e.to]==-1)
            {
                level[e.to]=level[u]+1;
                q.pb(e.to);
            }
        }
    }
    return level[t]!=-1;
}
int dfs(int u,int t,int pushed)
{
    if(u==t or pushed==0)
    {
        return pushed;
    }
    for(int& i=ptr[u];i<sz(adj[u]);i++)
    {
        auto& e=adj[u][i];
        int tr=e.to;
        if(level[u]+1!=level[tr] or e.cap-e.flow==0)
        {
            continue;
        }
        int push=dfs(tr,t,min(pushed,e.cap-e.flow));
        if(push==0)
        {
            continue;
        }
        e.flow+=push;
        adj[tr][e.rev].flow-=push;
        return push;
    }
    return 0;
}
int max_flow(int s,int t,int n)
{
    int flow=0;
    while(bfs(s,t,n))
    {
        for(int i=1;i<=n;i++)
        {
            ptr[i]=0;
        }
        while(int push=dfs(s,t,MOD))
        {
            flow+=push;
        }
    }
    return flow;
}
vi build(vi comp)
{
    if(sz(comp)==1)
    {
        return comp;
    }
    for(int x:comp)
    {
        in_c[x]=true;
    }
    int min_w=MOD;
    int min_idx=-1;
    for(int i=0;i<sz(tree);i++)
    {
        if(!tree[i].used and in_c[tree[i].u] and in_c[tree[i].v])
        {
            if(tree[i].w<min_w)
            {
                min_w=tree[i].w;
                min_idx=i;
            }
        }
    }
    tree[min_idx].used=true;
    int u_cut=tree[min_idx].u;
    vvi t_adj(max_n);
    for(int i=0;i<sz(tree);i++)
    {
        if(!tree[i].used and in_c[tree[i].u] and in_c[tree[i].v])
        {
            t_adj[tree[i].u].pb(tree[i].v);
            t_adj[tree[i].v].pb(tree[i].u);
        }
    }
    for(int x:comp)
    {
        vis[x]=false;
    }
    vi q;
    q.pb(u_cut);
    vis[u_cut]=true;
    int head=0;
    while(head<sz(q))
    {
        int u=q[head++];
        for(int v:t_adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                q.pb(v);
            }
        }
    }
    vi c1,c2;
    for(int x:comp)
    {
        if(vis[x])
        {
            c1.pb(x);
        }
        else
        {
            c2.pb(x);
        }
        in_c[x]=false;
    }
    vi left=build(c1);
    vi right=build(c2);
    for(int x:right)
    {
        left.pb(x);
    }
    return left;
}
inline void solve()
{
    int n,m;
    if(!(cin>>n>>m))
    {
        return;
    }
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        pipes.pb({u,v,c});
    }
    vi p(n+1,1);
    vi w(n+1,0);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[j].clear();
        }
        for(auto& pipe:pipes)
        {
            add_edge(pipe.u,pipe.v,pipe.c);
        }
        w[i]=max_flow(i,p[i],n);
        bfs(i,-1,n);
        for(int j=i+1;j<=n;j++)
        {
            if(level[j]!=-1 and p[j]==p[i])
            {
                p[j]=i;
            }
        }
    }
    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        ans+=w[i];
        tree.pb({i,p[i],w[i],false});
    }
    cout<<ans<<el;
    vi comp;
    for(int i=1;i<=n;i++)
    {
        comp.pb(i);
    }
    vi res=build(comp);
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<(i==n-1?"":" ");
    }
    cout<<el;
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
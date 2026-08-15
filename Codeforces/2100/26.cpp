/**
 * Author:  hunglvh
 * Created: 2026-08-13 17:10:55
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
#define arr(a,n) for(int i=0;i<n;i++)cin>>a[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define TIME() cerr<<endl<<"Time:"<<1000.0*clock()/CLOCKS_PER_SEC<<" ms."<<endl
#define i128 __int128
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template<class T> bool chmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool chmax(T& a, const T& b){return a<b?a=b,1:0;}
ll gcd(ll a, ll b){return std::gcd(a,b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll pow_mod(ll a, ll b, ll m=MOD){ll res=1;a%=m;while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}

const int max_n=300005;
vi adj[max_n];
int vis[max_n];
int dst[max_n];
int mxd,far;
vi cmp;
struct dsu
{
    vi p,sz,dia;
    dsu(int n)
    {
        p.resize(n+1);
        sz.assign(n+1,1);
        dia.assign(n+1,0);
        iota(all(p),0);
    }
    int get(int v)
    {
        return(v==p[v]?v:p[v]=get(p[v]));
    }
    bool uni(int u,int v)
    {
        u=get(u);
        v=get(v);
        if(u==v)
        {
            return 0;
        }
        if(sz[u]<sz[v])
        {
            swap(u,v);
        }
        p[v]=u;
        sz[u]+=sz[v];
        dia[u]=max({dia[u],dia[v],(dia[u]+1)/2+(dia[v]+1)/2+1});
        return 1;
    }
    bool un2(int u,int v)
    {
        u=get(u);
        v=get(v);
        if(u==v)
        {
            return 0;
        }
        if(sz[u]<sz[v])
        {
            swap(u,v);
        }
        p[v]=u;
        sz[u]+=sz[v];
        return 1;
    }
};
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=1;
    dst[s]=0;
    mxd=0;
    far=s;
    cmp.pb(s);
    while(sz(q))
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dst[v]=dst[u]+1;
                if(dst[v]>mxd)
                {
                    mxd=dst[v];
                    far=v;
                }
                cmp.pb(v);
                q.push(v);
            }
        }
    }
}
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n=t+1;
        int m,q;cin>>m>>q;
        dsu d(n);
        for(int i=0;i<m;i++)
        {
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            d.un2(u,v);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                cmp.clear();bfs(i);
                int u=far;
                for(int v:cmp)
                {
                    vis[v]=0;
                }
                cmp.clear();bfs(u);
                d.dia[d.get(i)]=mxd;
            }
        }
        for(int i=0;i<q;i++)
        {
            int type;cin>>type;
            if(type==1)
            {
                int x;cin>>x;
                cout<<d.dia[d.get(x)]<<el;
            }
            else
            {
                int x,y;cin>>x>>y;
                d.uni(x,y);
            }
        }
        return;
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
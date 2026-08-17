/**
 * Author:  hunglvh
 * Created: 2026-08-16 14:34:23
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

const int max_n=4e5+5;
int col[max_n];
vi adj[max_n];
int vis[max_n];
int in[max_n];
int out[max_n];
int eul[max_n];
int tmr=0;

void dfs(int u)
{
    vis[u]=1;
    in[u]=++tmr;
    eul[tmr]=col[u];
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
    out[u]=tmr;
}

struct seg
{
    int n;
    vl t,lz;
    seg(int n):n(n)
    {
        t.assign(4*n+1,0);
        lz.assign(4*n+1,0);
    }
    void push(int id)
    {
        if(lz[id])
        {
            t[id*2]=lz[id];
            lz[id*2]=lz[id];
            t[id*2+1]=lz[id];
            lz[id*2+1]=lz[id];
            lz[id]=0;
        }
    }
    void upd(int id,int l,int r,int u,int v,ll val)
    {
        if(v<l or r<u)
        {
            return;
        }
        if(u<=l and r<=v)
        {
            t[id]=val;
            lz[id]=val;
            return;
        }
        push(id);
        int mid=(l+r)/2;
        upd(id*2,l,mid,u,v,val);
        upd(id*2+1,mid+1,r,u,v,val);
        t[id]=t[id*2]|t[id*2+1];
    }
    ll get(int id,int l,int r,int u,int v)
    {
        if(v<l or r<u)
        {
            return 0;
        }
        if(u<=l and r<=v)
        {
            return t[id];
        }
        push(id);
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v)|get(id*2+1,mid+1,r,u,v);
    }
};

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n=t+1,m;cin>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>col[i];
        }
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        seg tree(n);
        for(int i=1;i<=n;i++)
        {
            tree.upd(1,1,n,i,i,1LL<<eul[i]);
        }
        while(m--)
        {
            int typ;cin>>typ;
            if(typ==1)
            {
                int u,c;cin>>u>>c;
                tree.upd(1,1,n,in[u],out[u],1LL<<c);
            }
            else
            {
                int u;cin>>u;
                ll mask=tree.get(1,1,n,in[u],out[u]);
                int ans=__builtin_popcountll(mask);
                cout<<ans<<el;
            }
        }
        t=0;
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
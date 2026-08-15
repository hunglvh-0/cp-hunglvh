/**
 * Author:  hunglvh
 * Created: 2026-08-12 10:00:13
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
const int max_n=200005;
vi adj[max_n];
int vis[max_n];
set<int>st[max_n];
vi req[max_n];
int c[max_n];
ll w[max_n];
ll ans;
void dfs(int u)
{
    vis[u]=1;
    st[u].clear();
    req[u].clear();
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
            if(sz(st[u])<sz(st[v]))
            {
                swap(st[u],st[v]);
            }
            for(int x:st[v])
            {
                if(st[u].count(x))
                {
                    req[u].pb(x);
                }
                else
                {
                    st[u].insert(x);
                }
            }
            st[v].clear();
        }
    }
    sort(all(req[u]));
    req[u].erase(unique(all(req[u])),req[u].end());
    int org=c[u];
    if(org!=0)
    {
        bool cut=0;
        for(int x:req[u])
        {
            if(x!=org)
            {
                cut=1;
                break;
            }
        }
        if(cut)
        {
            ans+=w[u];
        }
    }
    else
    {
        if(sz(req[u])>=2)
        {
            ans+=w[u];
        }
    }
    if(c[u]==0)
    {
        if(sz(req[u])>0)
        {
            c[u]=req[u][0];
        }
        else if(sz(st[u])>0)
        {
            c[u]=*st[u].begin();
        }
    }
    if(c[u]!=0)
    {
        st[u].insert(c[u]);
    }
}
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=1;
    if(c[s]==0)
    {
        c[s]=1;
    }
    while(sz(q))
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                if(c[v]==0)
                {
                    c[v]=c[u];
                }
                q.push(v);
            }
        }
    }
}
inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
        }
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            vis[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ans=0;
        dfs(1);
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
        }
        bfs(1);
        cout<<ans<<el;
        for(int i=1;i<=n;i++)
        {
            cout<<c[i];
            if(i<n)
            {
                cout<<" ";
            }
        }
        cout<<el;
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
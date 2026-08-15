/**
 * Author:  hunglvh
 * Created: 2026-08-10 12:07:00
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

const int max_n=1e5+5;
int n,m,k;
vi adj[max_n];
int dep[max_n];
int p[max_n];
int vis[max_n];
int cu=-1,cv=-1;

void dfs(int u)
{
    vis[u]=1;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            dep[v]=dep[u]+1;
            p[v]=u;
            dfs(v);
        }
        else if(v!=p[u] and dep[u]>dep[v])
        {
            if(dep[u]-dep[v]+1<=k)
            {
                if(cu==-1)
                {
                    cu=u;
                    cv=v;
                }
            }
        }
    }
}

inline void solve()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dep[1]=0;
    p[1]=0;
    dfs(1);
    if(cu!=-1)
    {
        cout<<2<<el;
        vi cyc;
        int cur=cu;
        while(cur!=cv)
        {
            cyc.pb(cur);
            cur=p[cur];
        }
        cyc.pb(cv);
        cout<<sz(cyc)<<el;
        for(int x:cyc)
        {
            cout<<x<<" ";
        }
        cout<<el;
        return;
    }
    vector<pii>vec;
    for(int i=1;i<=n;i++)
    {
        vec.pb({dep[i],i});
    }
    sort(rall(vec));
    vi ans;
    vi bad(n+1,0);
    for(pii tmp:vec)
    {
        int u=tmp.s;
        if(!bad[u])
        {
            ans.pb(u);
            bad[u]=1;
            bad[p[u]]=1;
        }
    }
    cout<<1<<el;
    ans.resize((k+1)/2);
    for(int i=0;i<(k+1)/2;i++)
    {
        cout<<ans[i]<<" ";
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
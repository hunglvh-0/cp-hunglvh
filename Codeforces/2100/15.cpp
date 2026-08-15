/**
 * Author:  hunglvh
 * Created: 2026-08-10 11:04:59
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

const int max_n=3e5+5;
int n,k,d;
int p[max_n];
vector<pii>adj[max_n];
int vis[max_n];
int keep[max_n];

void bfs(int s)
{
    queue<int>q;
    for(int i=1;i<=k;i++)
    {
        if(!vis[p[i]])
        {
            vis[p[i]]=1;
            q.push(p[i]);
        }
    }
    while(sz(q))
    {
        int u=q.front();
        q.pop();
        for(auto[v,id]:adj[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                keep[id]=1;
                q.push(v);
            }
        }
    }
}

inline void solve()
{
    cin>>n>>k>>d;
    for(int i=1;i<=k;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }
    bfs(0);
    vi ans;
    for(int i=1;i<n;i++)
    {
        if(!keep[i])
        {
            ans.pb(i);
        }
    }
    cout<<sz(ans)<<el;
    for(int x:ans)
    {
        cout<<x<<" ";
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
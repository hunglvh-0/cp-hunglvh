/**
 * Author:  hunglvh
 * Created: 2026-08-06 06:42:43
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

const int m_n=1e5+5;
vi adj[m_n];
int sub[m_n];
bool rm[m_n];
char ans[m_n];
void dfs_sz(int u,int p)
{
    sub[u]=1;
    for(int v:adj[u])
    {
        if(v!=p and !rm[v])
        {
            dfs_sz(v,u);
            sub[u]+=sub[v];
        }
    }
}
int centroid(int u,int p,int tot)
{
    for(int v:adj[u])
    {
        if(v!=p and !rm[v] and sub[v]>tot/2)
        {
            return centroid(v,u,tot);
        }
    }
    return u;
}
void build(int u,char val)
{
    dfs_sz(u,0);
    int c=centroid(u,0,sub[u]);
    ans[c]=val;rm[c]=true;
    for(int v:adj[c])
    {
        if(!rm[v])
        {
            build(v,val+1);
        }
    }
}
inline void solve()
{
    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);adj[v].pb(u);
    }
    build(1,'A');
    for(int i=1;i<=n;i++)
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
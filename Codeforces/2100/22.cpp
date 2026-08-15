/**
 * Author:  hunglvh
 * Created: 2026-08-12 07:12:42
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

const int max_n=25;
int n,m,h;
ll k,ans;
ll a[max_n][max_n];
vector<ll> v[max_n][max_n];

void dfs1(int x,int y,ll val)
{
    val^=a[x][y];
    if(x+y-2==h)
    {
        v[x][y].pb(val);
        return;
    }
    for(int i=0;i<2;i++)
    {
        int nx=x+(i==0);int ny=y+(i==1);
        if(nx<=n and ny<=m)
        {
            dfs1(nx,ny,val);
        }
    }
}
void dfs2(int x,int y,ll val)
{
    val^=a[x][y];
    if(x+y-2==h)
    {
        ll t=k^val^a[x][y];
        ans+=upper_bound(all(v[x][y]),t)-lower_bound(all(v[x][y]),t);
        return;
    }
    for(int i=0;i<2;i++)
    {
        int nx=x-(i==0);int ny=y-(i==1);
        if(nx>=1 and ny>=1)
        {
            dfs2(nx,ny,val);
        }
    }
}

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        n=t+1;cin>>m>>k;
        h=(n+m-2)/2;ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs1(1,1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(sz(v[i][j]))
                {
                    sort(all(v[i][j]));
                }
            }
        }
        dfs2(n,m,0);
        cout<<ans<<el;
        break;
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
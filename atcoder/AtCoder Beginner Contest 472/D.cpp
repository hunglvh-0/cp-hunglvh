/**
 * Author:  hunglvh
 * Created: 2026-08-22 19:56:07
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

int h,w,k;
vs s;
vvi d;
queue<pii> q;

void bfs(int s_dummy)
{
    while(sz(q))
    {
        int u=q.front().f;
        int v=q.front().s;
        q.pop();
        if(d[u][v]==k)continue;
        for(int i=0;i<4;i++)
        {
            int nu=u+dx[i];
            int nv=v+dy[i];
            if(nu>=0 and nu<h and nv>=0 and nv<w)
            {
                if(s[nu][nv]=='.' and d[nu][nv]==-1)
                {
                    d[nu][nv]=d[u][v]+1;
                    q.push({nu,nv});
                }
            }
        }
    }
}

inline void solve()
{
    cin>>h>>w>>k;
    s.resize(h);arr(s,h);
    vi br(h,0),bc(w,0);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(s[i][j]=='#')
            {
                br[i]=1;bc[j]=1;
            }
        }
    }
    d.assign(h,vi(w,-1));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(s[i][j]=='.' and br[i]==0 and bc[j]==0)
            {
                d[i][j]=0;q.push({i,j});
            }
        }
    }
    bfs(0);
    int ans=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(d[i][j]!=-1 and d[i][j]<=k)
            {
                ans++;
            }
        }
    }
    cout<<ans<<el;
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
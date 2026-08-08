/**
 * Author:  hunglvh
 * Created: 2026-08-07 21:32:46
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

const int max_n=1e6+5;
vi adj[max_n];
int dst[max_n];
int par[max_n];
int mxd[max_n];
void bfs(int st,int n,int& far)
{
    for(int i=1;i<=n;i++)
    {
        dst[i]=-1;par[i]=-1;
    }
    queue<int> q;q.push(st);
    dst[st]=0;far=st;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        far=u;
        for(int v:adj[u])
        {
            if(dst[v]==-1)
            {
                dst[v]=dst[u]+1;
                par[v]=u;q.push(v);
            }
        }
    }
}
void dfs(int u,int p,int av,int d,int hd,vi& s)
{
    mxd[u]=d;int cnt=0;
    for(int v:adj[u])
    {
        if(v!=p and v!=av)
        {
            dfs(v,u,av,d+1,hd,s);
            if(mxd[u]<mxd[v])
            {
                mxd[u]=mxd[v];
            }
            if(mxd[v]==hd)
            {
                cnt++;
            }
        }
    }
    if(cnt>=2)
    {
        s.pb(d);
    }
}
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<n-1;i++)
        {
            int u,v;cin>>u>>v;
            adj[u].pb(v);adj[v].pb(u);
        }
        int a=1,b=1;
        bfs(1,n,a);bfs(a,n,b);
        vi pth;int cur=b;
        while(cur!=-1)
        {
            pth.pb(cur);cur=par[cur];
        }
        int len=sz(pth)-1;int hd=len/2;
        int ru=pth[hd];int rv=pth[hd+1];
        vi su,sv;
        dfs(ru,-1,rv,0,hd,su);su.pb(hd);
        dfs(rv,-1,ru,0,hd,sv);sv.pb(hd);
        sort(all(su));
        su.erase(unique(all(su)),su.end());
        sort(all(sv));
        sv.erase(unique(all(sv)),sv.end());
        vi pos(2*hd+2,0);
        for(int x:su)
        {
            for(int y:sv)
            {
                pos[x+y+1]=1;
            }
        }
        vi ans;
        for(int i=1;i<=2*hd+1;i++)
        {
            if(pos[i]==1)
            {
                ans.pb(i);
            }
        }
        cout<<sz(ans)<<" ";
        for(int i=0;i<sz(ans);i++)
        {
            cout<<ans[i]<<" ";
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
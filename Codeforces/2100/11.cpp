/**
 * Author:  hunglvh
 * Created: 2026-08-07 10:52:17
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

const int m_n=200005;
vi adj[m_n];
vi lvl[m_n];
int dep[m_n];
int par[m_n];
int col[m_n];
int deg[m_n];
vi res[m_n];
int usd[m_n];
bool cmp(int a,int b)
{
    return par[a]<par[b];
}
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();lvl[i].clear();
            res[i].clear();dep[i]=0;
            par[i]=0;col[i]=0;
            deg[i]=0;usd[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            adj[u].pb(v);adj[v].pb(u);
        }
        if(n==1)
        {
            cout<<1<<el;
            cout<<"1 1"<<el;
            continue;
        }
        queue<int> q;q.push(1);
        dep[1]=1;lvl[1].pb(1);
        int lim=1;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int v:adj[u])
            {
                if(dep[v]==0)
                {
                    dep[v]=dep[u]+1;par[v]=u;
                    deg[u]++;lvl[dep[v]].pb(v);
                    chmax(lim,dep[v]);q.push(v);
                }
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            chmax(ans,sz(lvl[i]));chmax(ans,deg[i]+1);
        }
        col[1]=1;
        for(int d=2;d<=lim;d++)
        {
            int m=sz(lvl[d]);
            if(m==0)
            {
                break;
            }
            sort(all(lvl[d]),cmp);
            vvi g;
            vi f;
            for(int i=0;i<m;)
            {
                int j=i;vi grp;
                while(j<m and par[lvl[d][j]]==par[lvl[d][i]])
                {
                    grp.pb(lvl[d][j]);j++;
                }
                g.pb(grp);f.pb(col[par[lvl[d][i]]]);
                i=j;
            }
            int p=sz(g);
            if(p==1)
            {
                vi c;int req=m;
                for(int j=1;req>0;j++)
                {
                    if(j!=f[0])
                    {
                        c.pb(j);req--;
                    }
                }
                for(int i=0;i<m;i++)
                {
                    col[g[0][i]]=c[i];
                }
            }
            else
            {
                for(int x:f)
                {
                    usd[x]=1;
                }
                vi e;int req=m-p;
                for(int j=1;req>0;j++)
                {
                    if(usd[j]==0)
                    {
                        e.pb(j);req--;
                    }
                }
                for(int i=0;i<p;i++)
                {
                    int prv=(i-1+p)%p;
                    col[g[i].back()]=f[prv];g[i].pop_back();
                }
                vi rem;
                for(int i=0;i<p;i++)
                {
                    for(int u:g[i])
                    {
                        rem.pb(u);
                    }
                }
                for(int i=0;i<sz(rem);i++)
                {
                    col[rem[i]]=e[i];
                }
                for(int x:f)
                {
                    usd[x]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            res[col[i]].pb(i);
        }
        cout<<ans<<el;
        for(int c=1;c<=ans;c++)
        {
            cout<<sz(res[c])<<" ";
            for(int u:res[c])
            {
                cout<<u<<" ";
            }
            cout<<el;
        }
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
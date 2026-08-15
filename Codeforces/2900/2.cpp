/**
 * Author:  hunglvh
 * Created: 2026-08-09 14:38:54
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

const int max_n=5e5+5;
const ll mod=998244353;
vi adj[max_n];
int a[max_n];
int dep[max_n];
int crt[max_n];
int isl[max_n];
int szi[max_n];
int sml[max_n];
int smr[max_n];
vi pst;
ll fct[max_n];
ll ifc[max_n];

struct blk_list
{
    int b=40000;
    vvi blk;
    blk_list()
    {
        blk.pb(vi());
    }
    void insert(int p,int v)
    {
        for(int i=0;i<sz(blk);i++)
        {
            if(p<=sz(blk[i]) or i==sz(blk)-1)
            {
                if(p>sz(blk[i]))p=sz(blk[i]);
                blk[i].pb(0);
                for(int j=sz(blk[i])-1;j>p;j--)
                {
                    blk[i][j]=blk[i][j-1];
                }
                blk[i][p]=v;
                if(sz(blk[i])>b)
                {
                    int mid=sz(blk[i])/2;
                    blk.insert(blk.begin()+i+1,vi(blk[i].begin()+mid,blk[i].end()));
                    blk[i].resize(mid);
                }
                return;
            }
            p-=sz(blk[i]);
        }
    }
    void erase(int p)
    {
        for(int i=0;i<sz(blk);i++)
        {
            if(p<sz(blk[i]))
            {
                for(int j=p;j<sz(blk[i])-1;j++)
                {
                    blk[i][j]=blk[i][j+1];
                }
                blk[i].pop_back();
                if(sz(blk[i])==0 and sz(blk)>1)
                {
                    blk.erase(blk.begin()+i);
                }
                return;
            }
            p-=sz(blk[i]);
        }
    }
    int get(int p)
    {
        for(int i=0;i<sz(blk);i++)
        {
            if(p<sz(blk[i]))
            {
                return blk[i][p];
            }
            p-=sz(blk[i]);
        }
        return 0;
    }
    int size()
    {
        int res=0;
        for(auto& x:blk)res+=sz(x);
        return res;
    }
    void clear()
    {
        blk.clear();
        blk.pb(vi());
    }
};
blk_list anc;

void pre()
{
    fct[0]=1;
    ifc[0]=1;
    for(int i=1;i<max_n;i++)
    {
        fct[i]=(fct[i-1]*i)%mod;
    }
    ifc[max_n-1]=pow_mod(fct[max_n-1],mod-2,mod);
    for(int i=max_n-2;i>=1;i--)
    {
        ifc[i]=(ifc[i+1]*(i+1))%mod;
    }
}
void dfs(int u)
{
    if(u==1)
    {
        crt[u]=0;
        isl[u]=0;
    }
    else
    {
        int l=(a[u]==0?0:anc.get(a[u]-1));
        int r=(a[u]==anc.size()?0:anc.get(a[u]));
        if(l==0)
        {
            crt[u]=r;
            isl[u]=1;
        }
        else if(r==0)
        {
            crt[u]=l;
            isl[u]=0;
        }
        else
        {
            if(dep[l]>dep[r])
            {
                crt[u]=l;
                isl[u]=0;
            }
            else
            {
                crt[u]=r;
                isl[u]=1;
            }
        }
    }
    anc.insert(a[u],u);
    for(int v:adj[u])
    {
        dep[v]=dep[u]+1;
        dfs(v);
    }
    anc.erase(a[u]);
    pst.pb(u);
}
inline void solve()
{
    pre();
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=0;i<=n;i++)
        {
            adj[i].clear();
            szi[i]=1;
            sml[i]=0;
            smr[i]=0;
        }
        pst.clear();
        anc.clear();
        for(int i=2;i<=n;i++)
        {
            int p;cin>>p;
            adj[p].pb(i);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dep[1]=1;
        dfs(1);
        for(int u:pst)
        {
            int c=crt[u];
            if(isl[u])
            {
                sml[c]+=szi[u];
            }
            else
            {
                smr[c]+=szi[u];
            }
            if(c!=0)
            {
                szi[c]+=szi[u];
            }
        }
        ll ans=1;
        for(int i=0;i<=n;i++)
        {
            ans=(ans*fct[sml[i]])%mod;
            ans=(ans*fct[smr[i]])%mod;
        }
        for(int i=1;i<=n;i++)
        {
            ans=(ans*ifc[szi[i]])%mod;
        }
        cout<<ans<<el;
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
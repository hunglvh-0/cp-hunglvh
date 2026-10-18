/**
 * Author: hunglvh
 * Created: 2026-10-18 07:59:40
**/
#include                         <bits/extc++.h>
#include                         <bits/stdc++.h>
using                            namespace std;
using                            namespace __gnu_pbds;
#pragma                          GCC diagnostic ignored "-Wunused-variable"
#pragma                          GCC diagnostic ignored "-Wunused-parameter"
#pragma                          GCC diagnostic ignored "-Wsign-compare"
// -----------------------------------------------------------------------------------------------
#define                          ll long long
#define                          ld long double
using                            u64 = uint64_t;
using                            vi = vector<int>;
using                            vl = vector<ll>;
using                            vs = vector<string>;
using                            vc = vector<char>;
using                            pii = pair<int, int>;
using                            pll = pair<ll, ll>;
using                            vvi = vector<vi>;
using                            vvl = vector<vl>;
#define                          all(x) x.begin(), x.end()
#define                          rall(x) (x).rbegin(), (x).rend()
#define                          sz(x) (int)(x).size()
#define                          pb push_back
#define                          el '\n'
#define                          f first
#define                          s second
#define                          i128 __int128
#define                          popcnt(x) __builtin_popcountll(x)
#define                          mask(x) (1LL << (x))
#define                          hasbit(x, i) (((x) >> (i)) & 1)
#define                          setbit(x, i) ((x) | mask(i))
#define                          clearbit(x, i) ((x) & ~mask(i))
const                            ll INF = 1e18;
const                            ll MOD = 1e9+7;
const                            int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
template <class T>               bool chmin(T &a,const T &b){return b<a?a=b,1:0;}
template <class T>               bool chmax(T &a,const T &b){return a<b?a=b,1:0;}
ll gcd(ll a,ll b)                {return std::gcd(a,b);}
ll lcm(ll a,ll b)                {return a/gcd(a,b)*b;}
ll pow_mod(ll a,ll b,ll m=MOD)
{
    ll res=1;
    a%=m;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}
void                             __print(int x){cerr<<x;}
void                             __print(long x){cerr<<x;}
void                             __print(long long x){cerr<<x;}
void                             __print(unsigned x){cerr<<x;}
void                             __print(unsigned long x){cerr<<x;}
void                             __print(unsigned long long x){cerr<<x;}
void                             __print(float x){cerr<<x;}
void                             __print(double x){cerr<<x;}
void                             __print(long double x){cerr<<x;}
void                             __print(char x){cerr<<'\''<<x<<'\'';}
void                             __print(const char *x){cerr<<'\"'<<x<<'\"';}
void                             __print(const string &x){cerr<<'\"'<<x<<'\"';}
void                             __print(bool x){cerr<<(x?"true":"false");}
template <typename T,typename V> void __print(const pair<T,V> &x)
{
    cerr<<'{';
    __print(x.first);
    cerr<<", ";
    __print(x.second);
    cerr<<'}';
}
template <typename T> void __print(const T &x)
{
    int f=0;
    cerr<<'{';
    for(const int &i:x)
        cerr<<(f++?", ":""),__print(i);
    cerr<<"}";
}
void _print(){cerr<<"]\n";}
template <typename T,typename... V> void _print(T t,V... v)
{
    __print(t);
    if(sizeof...(v))
        cerr<<", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
    cerr<<"\e[91m"<<__func__<<":"<<__LINE__<<" ["<<#__VA_ARGS__               \
        <<"] = [";                                                             \
    _print(__VA_ARGS__);                                                       \
    cerr<<"\e[39m"
#else
#define dbg(...)
#endif
#define arr(a,n)                                                               \
    for(int i=0;i<n;i++)                                                       \
        cin>>a[i];
#define fast                                                                   \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define TIME()                                                                 \
    cerr<<endl                                                                 \
        <<"Time:"<<1000.0*clock()/CLOCKS_PER_SEC<<" ms."<<endl
// -----------------------------------------------------------------------------------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct DSU
{
    vi p;
    DSU(int n):p(n)
    {
        iota(all(p),0);
    }
    int find(int x)
    {
        if(p[x]==x)
        {
            return x;
        }
        return p[x]=find(p[x]);
    }
    void unite(int a,int b)
    {
        p[find(a)]=find(b);
    }
};
inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        DSU d(n+1);
        for(int i=0;i<m;i++)
        {
            int l,r;
            cin>>l>>r;
            d.unite(l-1,r);
        }
        vector<u64> val(n+1),sm(n+1,0);
        vi ls(n+1,-1);
        for(int v=0;v<=n;v++)
        {
            int c=d.find(v);
            val[v]=rng();
            sm[c]+=val[v];
            ls[c]=v;
        }
        for(int c=0;c<=n;c++)
        {
            if(ls[c]!=-1)
            {
                val[ls[c]]-=sm[c];
            }
        }
        vector<u64> p(n,0);
        for(int i=1;i<n;i++)
        {
            p[i]=p[i-1]+val[i];
        }
        vi id(n);
        iota(all(id),0);
        sort(all(id),[&](int a,int b)
        {
            if(p[a]!=p[b])
            {
                return p[a]<p[b];
            }
            return a<b;
        });
        vi prv(n,-1),fi(n,0),la(n,0);
        for(int i=0;i<n;i++)
        {
            int x=id[i];
            if(i>0 and p[id[i-1]]==p[x])
            {
                prv[x]=id[i-1];
                fi[x]=fi[id[i-1]];
            }
            else
            {
                fi[x]=x;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            int x=id[i];
            if(i+1<n and p[id[i+1]]==p[x])
            {
                la[x]=la[id[i+1]];
            }
            else
            {
                la[x]=x;
            }
        }
        vector<pii> at;
        int mx=-1;
        for(int j=1;j<n;j++)
        {
            int i=prv[j];
            if(i<0)
            {
                continue;
            }
            if(i>mx)
            {
                at.pb({i,j});
            }
            mx=max(mx,i);
        }
        int k=sz(at);
        vector<pii> res;
        vi rp(k);
        for(int i=0;i<k;i++)
        {
            rp[i]=at[i].f+1;
        }
        function<void(int,int)> add=[&](int u,int v)
        {
            if(u>v)
            {
                swap(u,v);
            }
            res.pb({u+1,v});
        };
        if(k>0)
        {
            vi vo,rs;
            if(k%2==1)
            {
                if(k==1)
                {
                    vo={0};
                }
                else
                {
                    int r=k/2;
                    for(int i=0;i<k;i++)
                    {
                        if(i==r)
                        {
                            vo.pb(i);
                        }
                        else
                        {
                            rs.pb(i);
                        }
                    }
                }
            }
            else
            {
                bool ok=false;
                int i1=at[0].f,jk=at[k-1].s;
                for(int x=0;x<n;x++)
                {
                    if(fi[x]<=i1 and la[x]>=jk)
                    {
                        ok=true;
                        break;
                    }
                }
                if(not ok)
                {
                    for(int i=0;i<k;i++)
                    {
                        rs.pb(i);
                    }
                }
                else
                {
                    if(k==2)
                    {
                        vo={0,1};
                    }
                    else
                    {
                        for(int i=0;i<k;i++)
                        {
                            if(i==1 or i==2)
                            {
                                vo.pb(i);
                            }
                            else
                            {
                                rs.pb(i);
                            }
                        }
                    }
                }
            }
            for(int i:vo)
            {
                add(0,rp[i]);
            }
            int h=sz(rs)/2;
            for(int i=0;i<h;i++)
            {
                add(rp[rs[i]],rp[rs[i+h]]);
            }
        }
        cout<<sz(res)<<el;
        for(pii&e:res)
        {
            cout<<e.f<<' '<<e.s<<el;
        }
    }
}
int32_t main()
{
    fast;
    #define file ""
    if(fopen(file ".inp","r"))
    {
        freopen(file ".inp","r",stdin);
        freopen(file ".out","w",stdout);
    }
    solve();
    TIME();
    return 0;
}

/**
 * Author: hunglvh
 * Created: 2026-10-10 20:55:08
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
const                            ll MOD = 1e9 + 7;
const                            int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template <class T>               bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>               bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
ll gcd(ll a, ll b)               { return std::gcd(a, b); }
ll lcm(ll a, ll b)               { return a / gcd(a, b) * b; }
ll pow_mod(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void                             __print(int x) { cerr << x; }
void                             __print(long x) { cerr << x; }
void                             __print(long long x) { cerr << x; }
void                             __print(unsigned x) { cerr << x; }
void                             __print(unsigned long x) { cerr << x; }
void                             __print(unsigned long long x) { cerr << x; }
void                             __print(float x) { cerr << x; }
void                             __print(double x) { cerr << x; }
void                             __print(long double x) { cerr << x; }
void                             __print(char x) { cerr << '\'' << x << '\''; }
void                             __print(const char *x) { cerr << '\"' << x << '\"'; }
void                             __print(const string &x) { cerr << '\"' << x << '\"'; }
void                             __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}
template <typename T> void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__    \
         << "] = [";                                                           \
    _print(__VA_ARGS__);                                                       \
    cerr << "\e[39m"
#else
#define dbg(...)
#endif

#define arr(a, n)                                                              \
    for (int i = 0; i < n; i++)                                                \
        cin >> a[i];
#define fast                                                                   \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define TIME()                                                                 \
    cerr << endl                                                               \
         << "Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << " ms." << endl
// -----------------------------------------------------------------------------------------------
const int maxn=400005;
int n;
ll m;
ll a[maxn];
vi p_vec;
bool is_p[100005];
vector<pii> f_vec[maxn];
vi dist_p;
vi max_pw;
vvl pre_pw;
ll tr[2000005];
void sieve()
{
    fill(is_p+2,is_p+10005,true);
    for(int i=2;i*i<=10000;i++)
    {
        if(is_p[i])
        {
            for(int j=i*i;j<=10000;j+=i)
            {
                is_p[j]=false;
            }
        }
    }
    for(int i=2;i<=10000;i++)
    {
        if(is_p[i])
        {
            p_vec.pb(i);
        }
    }
}
void build(int node, int l, int r)
{
    if(l==r)
    {
        tr[node]=pre_pw[l][0];
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    tr[node]=(tr[2*node]*tr[2*node+1])%m;
}
void upd(int node, int l, int r, int idx, ll val)
{
    if(l==r)
    {
        tr[node]=val;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid)
    {
        upd(2*node,l,mid, idx, val);
    }
    else
    {
        upd(2*node+1,mid+1,r,idx,val);
    }
    tr[node]=(tr[2*node]*tr[2*node+1])%m;
}
inline void solve()
{
    cin>>n>>m;
    sieve();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int temp=a[i];
        for(int j=0;j<sz(p_vec);j++)
        {
            int p=p_vec[j];
            if(p*p>temp)
            {
                break;
            }
            if(temp%p==0)
            {
                int cnt=0;
                while(temp%p==0)
                {
                    temp/=p;
                    cnt++;
                }
                f_vec[i].pb({
                    p,cnt
                });
                dist_p.pb(p);
            }
        }
        if(temp>1)
        {
            f_vec[i].pb({
                temp,1
            });
            dist_p.pb(temp);
        }
    }
    sort(all(dist_p));
    dist_p.erase(unique(all(dist_p)),dist_p.end());
    int k=sz(dist_p);
    if(k==0)
    {
        cout<<n%m<<el;
        return;
    }
    max_pw.assign(k,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<sz(f_vec[i]);j++)
        {
            int p=f_vec[i][j].f;
            int idx=lower_bound(all(dist_p),p)-dist_p.begin();
            f_vec[i][j].f=idx;
            chmax(max_pw[idx],f_vec[i][j].s);
        }
    }
    pre_pw.resize(k);
    for(int i=0;i<k;i++)
    {
        pre_pw[i].assign(max_pw[i]+1,0);
        for(int c=0;c<=max_pw[i];c++)
        {
            pre_pw[i][c]=pow_mod(dist_p[i],max_pw[i]-c,m);
        }
    }
    build(1,0,k-1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<sz(f_vec[i]);j++)
        {
            int idx=f_vec[i][j].f;
            int cnt=f_vec[i][j].s;
            upd(1,0,k-1,idx,pre_pw[idx][cnt]);
        }
        ans=(ans+tr[1])%m;
        for(int j=0;j<sz(f_vec[i]);j++)
        {
            int idx=f_vec[i][j].f;
            upd(1,0,k-1,idx,pre_pw[idx][0]);
        }
    }
    cout<<ans<<el;
}
int32_t main()
{
    fast;
    #define file ""
    if (fopen(file ".inp", "r"))
    {
        freopen(file ".inp", "r", stdin);
        freopen(file ".out", "w", stdout);
    }
    solve();
    TIME();
    return 0;
}
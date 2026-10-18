/**
 * Author: hunglvh
 * Created: 2026-10-18 12:14:17
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
static int ch0[10000150],ch1[10000150],tc[10000150],rt[2][400005];
inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n);
        arr(a,n);
        int tot=0;
        rt[0][0]=0;
        rt[1][0]=0;
        ll ans=0;
        int px=0;
        vector<pair<int,pii>> v;
        for(int r=1;r<=n;r++)
        {
            int p=r&1;
            rt[0][r]=rt[0][r-1];
            rt[1][r]=rt[1][r-1];
            int pre=rt[p][r-1];
            int nr=++tot;
            ch0[nr]=ch0[pre];
            ch1[nr]=ch1[pre];
            tc[nr]=tc[pre]+1;
            rt[p][r]=nr;
            int cur=nr;
            for(int j=24;j>=1;j--)
            {
                int b=hasbit(px,j);
                int nxt=++tot;
                int old=b?ch1[pre]:ch0[pre];
                ch0[nxt]=ch0[old];
                ch1[nxt]=ch1[old];
                tc[nxt]=tc[old]+1;
                if(b)
                {
                    ch1[cur]=nxt;
                }
                else
                {
                    ch0[cur]=nxt;
                }
                cur=nxt;
                pre=old;
            }
            px^=a[r-1];
            vector<pair<int,pii>> nv;
            for(int i=0;i<sz(v);i++)
            {
                int val=v[i].f&a[r-1];
                if(val>0)
                {
                    if(sz(nv)>0 and nv.back().f==val)
                    {
                        nv.back().s.s=v[i].s.s;
                    }
                    else
                    {
                        nv.pb({val,v[i].s});
                    }
                }
            }
            if(a[r-1]>0)
            {
                if(sz(nv)>0 and nv.back().f==a[r-1])
                {
                    nv.back().s.s=r;
                }
                else
                {
                    nv.pb({a[r-1],{r,r}});
                }
            }
            v=nv;
            for(int i=0;i<sz(v);i++)
            {
                int val=v[i].f;
                int l1=v[i].s.f;
                int l2=v[i].s.s;
                int u2=rt[p][l2];
                int u1=rt[p][l1-1];
                int y=px^val;
                int low=__builtin_ctz(val);
                for(int j=24;j>=low;j--)
                {
                    int cnt=tc[u2]-tc[u1];
                    if(cnt==0)
                    {
                        break;
                    }
                    if(hasbit(val,j))
                    {
                        ans+=cnt*mask(j);
                    }
                    if(j>low)
                    {
                        int b=hasbit(y,j);
                        if(b)
                        {
                            u2=ch1[u2];
                            u1=ch1[u1];
                        }
                        else
                        {
                            u2=ch0[u2];
                            u1=ch0[u1];
                        }
                    }
                }
            }
        }
        cout<<ans<<el;
    }
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
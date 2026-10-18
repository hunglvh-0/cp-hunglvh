/**
 * Author: hunglvh
 * Created: 2026-10-03 20:05:24
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
const int maxn=500005;
int tr_f[maxn][26], tr_r[maxn][26];
int re_r[maxn][26];
int t_ext[maxn], t_pre[maxn], t_suf[maxn];
int sz_f=0, sz_r=0;
int type[maxn];
inline void solve()
{
    int q;
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        string s;
        cin>>type[i]>>s;
        int t=type[i];
        if(t<=4)
        {
            int u=0;
            for(int j=0;j<sz(s);j++)
            {
                int v=s[j]-'a';
                if(!tr_f[u][v])
                {
                    tr_f[u][v]=++sz_f;
                }
                u=tr_f[u][v];
            }
            if(t<=2)
            {
                t_ext[u]=i;
            }
            else
            {
                t_pre[u]=i;
            }
        }
        else if(t<=6)
        {
            int u=0;
            for(int j=sz(s)-1;j>=0;j--)
            {
                int v=s[j]-'a';
                if(!tr_r[u][v])
                {
                    tr_r[u][v]=++sz_r;
                }
                u=tr_r[u][v];
            }
            t_suf[u]=i;
        }
        else
        {
            int mt=0;
            int u=0;
            for(int j=0;j<sz(s);j++)
            {
                int v=s[j]-'a';
                u=tr_f[u][v];
                if(!u)
                {
                    break;
                }
                if(t_pre[u]>mt)
                {
                    mt=t_pre[u];
                }
            }
            if(u and t_ext[u]>mt)
            {
                mt=t_ext[u];
            }
            u=0;
            for(int j=sz(s)-1;j>=0;j--)
            {
                int v=s[j]-'a';
                u=tr_r[u][v];
                if(!u)
                {
                    break;
                }
                if(t_suf[u]>mt)
                {
                    mt=t_suf[u];
                }
            }
            if(mt==0 or type[mt]%2==1)
            {
                cout<<"Y"<<el;
            }
            else
            {
                cout<<"N"<<el;
            }
        }
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
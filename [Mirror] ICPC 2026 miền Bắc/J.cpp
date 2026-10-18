/**
 * Author: hunglvh
 * Created: 2026-10-11 15:48:44
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

inline void solve()
{
    int lim=10200000;
    vi a(lim+1);
    vl pos(lim+1),s2(lim+1);
    a[1]=1;
    a[2]=2;
    a[3]=2;
    int ptr=3,idx=4;
    while(idx<=lim)
    {
        int cnt=a[ptr],val=ptr;
        for(int k=0;k<cnt and idx<=lim;k++)
        {
            a[idx++]=val;
        }
        ptr++;
    }
    for(int i=1;i<=lim;i++)
    {
        pos[i]=pos[i-1]+a[i];
        s2[i]=s2[i-1]+1LL*i*a[i];
    }
    ll n,mod;
    cin>>n>>mod;
    int low=1,high=lim,m=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(s2[mid]>=n)
        {
            m=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    ll rem=n-s2[m-1];
    ll cnt=(rem+m-1)/m;
    ll r=pos[m-1]+cnt;
    ll r1=r-1;
    int mp=(r1>pos[m-1])?m:(m-1);
    i128 w1=0;
    for(int j=1;j<mp;j++)
    {
        i128 tr=(i128)j*a[j];
        i128 sm=(i128)pos[j-1]+1+pos[j];
        i128 pd=tr*sm/2;
        w1=(w1+pd)%mod;
    }
    i128 cl=(i128)r1-pos[mp-1];
    i128 f1=(i128)pos[mp-1]+1;
    i128 l1=r1;
    i128 sk=cl*(f1+l1)/2;
    i128 tl=((i128)mp%mod)*(sk%mod)%mod;
    i128 s2p=(w1+tl)%mod;
    i128 pp=(s2[mp-1]%mod+(i128)mp*((r1-pos[mp-1])%mod))%mod;
    pp=(pp%mod+mod)%mod;
    i128 ans=(s2p+(i128)(r%mod)*((n-pp)%mod))%mod;
    ans=(ans%mod+mod)%mod;
    cout<<(ll)ans<<el;
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
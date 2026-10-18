/**
 * Author: hunglvh
 * Created: 2026-10-14 21:34:56
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wsign-compare"
// -----------------------------------------------------------------------------------------------
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
#define i128 __int128

#define popcnt(x) __builtin_popcountll(x)
#define mask(x) (1LL << (x))
#define hasbit(x, i) (((x) >> (i)) & 1)
#define setbit(x, i) ((x) | mask(i))
#define clearbit(x, i) ((x) & ~mask(i))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
ll gcd(ll a, ll b) { return std::gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
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

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vi n0(n+3,n+1),n2(n+3,n+1),n5(n+3,n+1),n6(n+3,n+1);
        for(int i=n;i>=1;i--)
        {
            n0[i]=(s[i-1]=='0'?i:n0[i+1]);
            n2[i]=(s[i-1]=='2'?i:n2[i+1]);
            n5[i]=(s[i-1]=='5'?i:n5[i+1]);
            n6[i]=(s[i-1]=='6'?i:n6[i+1]);
        }
        vl d(n+5,0);
        for(int l=1;l<=n;l++)
        {
            int p1=n2[l];
            if(p1>n)
            {
                continue;
            }
            int p2=n0[p1+1];
            if(p2>n)
            {
                continue;
            }
            int p3=n2[p2+1];
            if(p3>n)
            {
                continue;
            }
            int r5=n5[p3+1];
            int r6=n6[p3+1];
            if(r5<=n and r5<r6)
            {
                int L=r5;
                int R=min(n,r6-1);
                ll k=R-L+1;
                d[l]+=k;
                d[l+1]-=k;
                d[L+1]-=1;
                d[R+2]+=1;
            }
        }
        for(int i=1;i<=n+2;i++)
        {
            d[i]+=d[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            d[i]+=d[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            ll tot=1LL*i*(n-i+1);
            ll ans=tot-d[i];
            cout<<ans<<(i==n?"":" ");
        }
        cout<<el;
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
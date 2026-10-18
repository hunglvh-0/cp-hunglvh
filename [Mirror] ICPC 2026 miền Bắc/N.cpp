/**
 * Author: hunglvh
 * Created: 2026-10-11 14:38:53
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
    struct bint
    {
        int sg;
        string s;
        bint()
        {
            sg=1;
            s="0";
        }
        bint(string str)
        {
            sg=1;
            s=str;
            if(s[0]=='-')
            {
                sg=-1;
                s=s.substr(1);
            }
            else
            {
                if(s[0]=='+')
                {
                    s=s.substr(1);
                }
            }
            int p=0;
            while(p+1<sz(s) and s[p]=='0')
            {
                p++;
            }
            s=s.substr(p);
            if(s=="0")
            {
                sg=1;
            }
        }
        static int cmp(string u,string v)
        {
            if(sz(u)!=sz(v))
            {
                if(sz(u)>sz(v))
                {
                    return 1;
                }
                return -1;
            }
            if(u!=v)
            {
                if(u>v)
                {
                    return 1;
                }
                return -1;
            }
            return 0;
        }
        static string addm(string u,string v)
        {
            string r="";
            int i=sz(u)-1,j=sz(v)-1,c=0;
            while(i>=0 or j>=0 or c)
            {
                int sm=c;
                if(i>=0)
                {
                    sm+=u[i]-'0';
                    i--;
                }
                if(j>=0)
                {
                    sm+=v[j]-'0';
                    j--;
                }
                r.pb(sm%10+'0');
                c=sm/10;
            }
            reverse(all(r));
            return r;
        }
        static string subm(string u,string v)
        {
            string r="";
            int i=sz(u)-1,j=sz(v)-1,c=0;
            while(i>=0)
            {
                int df=(u[i]-'0')-c;
                if(j>=0)
                {
                    df-=(v[j]-'0');
                    j--;
                }
                if(df<0)
                {
                    df+=10;
                    c=1;
                }
                else
                {
                    c=0;
                }
                r.pb(df+'0');
                i--;
            }
            while(sz(r)>1 and r.back()=='0')
            {
                r.pop_back();
            }
            reverse(all(r));
            return r;
        }
        bint operator+(bint o)
        {
            if(sg==o.sg)
            {
                bint r;
                r.sg=sg;
                r.s=addm(s,o.s);
                return r;
            }
            int k=cmp(s,o.s);
            if(k==0)
            {
                bint r;
                r.sg=1;
                r.s="0";
                return r;
            }
            if(k>0)
            {
                bint r;
                r.sg=sg;
                r.s=subm(s,o.s);
                return r;
            }
            bint r;
            r.sg=o.sg;
            r.s=subm(o.s,s);
            return r;
        }
        void pr()
        {
            if(s=="0")
            {
                cout<<0<<el;
            }
            else
            {
                if(sg==-1)
                {
                    cout<<'-';
                }
                cout<<s<<el;
            }
        }
    };
    string sa,sb,sc;
    cin>>sa>>sb>>sc;
    bint a(sa),b(sb),c(sc);
    bint ans=a+b+c;
    ans.pr();
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
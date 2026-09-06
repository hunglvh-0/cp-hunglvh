/**
 * Author: hunglvh
 * Created: 2026-09-05 19:00:54
 * ❤️C
**/
#include                <bits/stdc++.h>
#include                <bits/extc++.h>
#include                <atcoder/all>
using                   namespace std;
using                   namespace __gnu_pbds;
using                   namespace atcoder;
#pragma                 GCC diagnostic ignored "-Wunused-variable"
#pragma                 GCC diagnostic ignored "-Wunused-parameter"
#pragma                 GCC diagnostic ignored "-Wsign-compare"
// --- TEMPLATE START ---

#define                 ll long long
#define                 ld long double
using                   u64 = uint64_t;
using                   vi = vector<int>;
using                   vl = vector<ll>;
using                   vs = vector<string>;
using                   vc = vector<char>;
using                   pii = pair<int, int>;
using                   pll = pair<ll, ll>;
using                   vvi = vector<vi>;
using                   vvl = vector<vl>;
#define                 all(x) x.begin(), x.end()
#define                 rall(x) (x).rbegin(), (x).rend()
#define                 sz(x) (int)(x).size()
#define                 pb push_back
#define                 el '\n'
#define                 f first
#define                 s second
#define                 arr(a,n) for(int i=0;i<n;i++)cin>>a[i];
#define                 fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define                 yes cout<<"YES\n"
#define                 no cout<<"NO\n"
#define                 TIME() cerr<<endl<<"Time:"<<1000.0*clock()/CLOCKS_PER_SEC<<" ms."<<endl
#define                 i128 __int128
const                   ll INF = 1e18;
const                   ll MOD = 1e9 + 7;
const                   int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template<class T>       bool chmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T>       bool chmax(T& a, const T& b){return a<b?a=b,1:0;}
ll gcd(ll a, ll b)
{
    return std::gcd(a,b);
}
ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}
ll pow_mod(ll a, ll b, ll m=MOD)
{
    ll res=1;a%=m;
    while(b>0)
    {
        if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;
    }
    return res;
}

void                    __print(int x) {cerr << x;}
void                    __print(long x) {cerr << x;}
void                    __print(long long x) {cerr << x;}
void                    __print(unsigned x) {cerr << x;}
void                    __print(unsigned long x) {cerr << x;}
void                    __print(unsigned long long x) {cerr << x;}
void                    __print(float x) {cerr << x;}
void                    __print(double x) {cerr << x;}
void                    __print(long double x) {cerr << x;}
void                    __print(char x) {cerr << '\'' << x << '\'';}
void                    __print(const char *x) {cerr << '\"' << x << '\"';}
void                    __print(const string &x) {cerr << '\"' << x << '\"';}
void                    __print(bool x) {cerr << (x ? "true" : "false");}
template                <typename T, typename V>
void                    __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template                <typename T>
void                    __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void                    _print() {cerr << "]\n";}
template                <typename T, typename... V>
void                    _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define                 dbg(...) cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__); cerr << "\e[39m"
#else
#define dbg(...)
#endif
// --- TEMPLATE END ---

ll calc_m(vl&ve,vl&vo)
{
    ll mx=-INF;
    int e=sz(ve);
    int o=sz(vo);
    if(e>=2)
    {
        ll cr=ve[0]+ve[1]+2LL*min(o,e-1);
        chmax(mx,cr);
    }
    if(o>=2)
    {
        ll cr=vo[0]+vo[1]+2LL*min(e,o-1);
        chmax(mx,cr);
    }
    if(e>=1&&o>=1)
    {
        ll cr=ve[0]+vo[0]+2LL*min(e,o)-1LL;
        chmax(mx,cr);
    }
    return mx;
}
inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vl a(n);
        ll s=0;
        vl ve,vo;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
            if(a[i]%2==0)
            {
                ve.pb(a[i]);
            }
            else
            {
                vo.pb(a[i]);
            }
        }
        sort(rall(ve));
        sort(rall(vo));
        ll mx=calc_m(ve,vo);
        ll an=s-mx/2LL;
        cout<<an<<el;
    }
}
int32_t main()
{
    fast;
    #define file ""
    if(fopen(file".inp","r"))
    {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    solve();
    TIME();
    return 0;
}
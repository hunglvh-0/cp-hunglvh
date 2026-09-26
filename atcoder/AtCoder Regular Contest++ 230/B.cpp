/**
 * Author: hunglvh
 * Created: 2026-09-20 19:25:11
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
using mint=modint998244353;
const int mx_n=40005;
mint f_c[mx_n],i_f[mx_n];
mint p[mx_n],q[mx_n],r[mx_n],s[mx_n];
mint pm[mx_n],pm_1[mx_n];
mint nCr(int n,int k)
{
    if(k<0 or k>n)
    {
        return 0;
    }
    return f_c[n]*i_f[k]*i_f[n-k];
}
inline void solve()
{
    int h,w;
    ll m;
    cin>>h>>w>>m;
    f_c[0]=1;
    i_f[0]=1;
    for(int i=1;i<mx_n;i++)
    {
        f_c[i]=f_c[i-1]*i;
        i_f[i]=f_c[i].inv();
    }
    pm[0]=1;
    pm_1[0]=1;
    for(int i=1;i<mx_n;i++)
    {
        pm[i]=pm[i-1]*m;
        pm_1[i]=pm_1[i-1]*(m+1);
    }
    int k=h*w;
    for(int i=0;i<=k;i++)
    {
        p[i]=pm_1[i+1]*i_f[i+1];
        q[i]=i_f[i+1];
    }
    for(int i=0;i<=k;i++)
    {
        u64 sv=0;
        for(int j=0;j<i;j++)
        {
            sv+=1ULL*r[j].val()*q[i-j].val();
            if((j&15)==15)
            {
                sv%=998244353;
            }
        }
        sv%=998244353;
        r[i]=p[i]-mint(sv);
    }
    for(int i=0;i<=k;i++)
    {
        s[i]=r[i]*f_c[i];
        if(i==0)
        {
            s[i]-=1;
        }
    }
    mint ans=0;
    for(int rw=1;rw<=h;rw++)
    {
        for(int cw=1;cw<=w;cw++)
        {
            int a=rw*(w-cw);
            int b=cw*(h-rw);
            u64 sv=0;
            for(int j=0;j<=b;j++)
            {
                ll tr=1LL*nCr(b,j).val()*pm_1[b-j].val()%998244353*s[a+j].val()%998244353;
                if(j&1)
                {
                    sv+=998244353-tr;
                }
                else
                {
                    sv+=tr;
                }
                if((j&15)==15)
                {
                    sv%=998244353;
                }
            }
            sv%=998244353;
            mint sm=sv;
            mint wy=nCr(h,rw)*nCr(w,cw)*pm[(h-rw)*(w-cw)];
            mint ct=wy*sm;
            if((rw+cw)&1)
            {
                ans-=ct;
            }
            else
            {
                ans+=ct;
            }
        }
    }
    cout<<ans.val()<<el;
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

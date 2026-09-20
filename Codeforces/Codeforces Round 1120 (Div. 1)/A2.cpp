/**
 * Author: hunglvh
 * Created: 2026-09-12 21:44:00
 * ❤️C
**/
#include                <bits/stdc++.h>
#include                <bits/extc++.h>
using                   namespace std;
using                   namespace __gnu_pbds;
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

inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        vi d(n+2,0);
        for(int i=1;i<=n;i++)
        {
            ll l=1LL*a[i]*i;
            ll r=1LL*a[i]*i+i-1;
            if(l<n)
            {
                d[l]++;
                d[min(1LL*n,r+1)]--;
            }
        }
        vi u;
        u.pb(-1);
        int c=0;
        for(int i=0;i<n;i++)
        {
            c+=d[i];
            if(c==0)
            {
                u.pb(i);
            }
        }
        int m=sz(u)-1;
        vi nx(n+2,-1);
        vi pv(n+2,-1);
        for(int i=1;i<=m;i++)
        {
            pv[u[i]]=i;
            nx[u[i]]=i;
        }
        int la=-1;
        for(int i=0;i<=n;i++)
        {
            if(pv[i]!=-1)
            {
                la=pv[i];
            }
            pv[i]=la;
        }
        la=-1;
        for(int i=n;i>=0;i--)
        {
            if(nx[i]!=-1)
            {
                la=nx[i];
            }
            nx[i]=la;
        }
        vi rq(m+2,0);
        for(int k=1;k<=n;k++)
        {
            int mv=a[k]-1;
            chmin(mv,(n-1)/k);
            for(int v=0;v<=mv;v++)
            {
                int l=v*k;
                int r=min(n-1,v*k+k-1);
                int xj=nx[l];
                int yj=pv[r];
                if(xj!=-1 and yj!=-1 and xj<=yj)
                {
                    chmax(rq[yj],xj);
                }
            }
        }
        vi lm(m+2,0);
        lm[0]=0;
        for(int i=1;i<=m;i++)
        {
            lm[i]=max(lm[i-1],rq[i]);
        }
        vl dp(m+2,0);
        vl ps(m+2,0);
        dp[0]=1;
        ps[0]=1;
        for(int i=1;i<=m;i++)
        {
            int l=lm[i-1];
            int r=i-1;
            if(l<=r)
            {
                ll su=ps[r];
                if(l>0)
                {
                    su=(su-ps[l-1]+MOD)%MOD;
                }
                dp[i]=su;
            }
            else
            {
                dp[i]=0;
            }
            ps[i]=(ps[i-1]+dp[i])%MOD;
        }
        ll ans=0;
        int l=lm[m];
        int r=m;
        if(l<=r)
        {
            ans=ps[r];
            if(l>0)
            {
                ans=(ans-ps[l-1]+MOD)%MOD;
            }
        }
        cout<<ans<<el;
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
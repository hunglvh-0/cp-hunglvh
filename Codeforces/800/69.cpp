/**
 * Author:  hunglvh
 * Created: 2026-07-26 20:25:27
 * ❤️C
**/
#include <bits/stdc++.h>
using namespace std;
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
#define arr(a,n) for (int i = 0; i < n; i++) cin >> a[i];
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define TIME() cerr << endl << "Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << " ms." << endl
#define i128 __int128
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template<class T> bool chmin(T& a, const T& b){return b < a ? a = b, 1 : 0;}
template<class T> bool chmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
ll gcd(ll a, ll b){return std::gcd(a, b);}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}
ll pow_mod(ll a, ll b, ll m = MOD){ll res = 1; a %= m;while (b > 0){if (b & 1) res = (res * a) % m;a = (a * a) % m;b >>= 1;}return res;}
const int lim=4000000;
bool isp[4000005];
int d3[4000005],pw[4000005],val[4000005];
ll s3[4000005];
char mu[4000005];
vi pr;
void sieve()
{
    memset(isp,true,sizeof(isp));
    isp[0]=isp[1]=false;
    d3[1]=1;
    s3[1]=1;
    mu[1]=1;
    for(int i=2;i<=lim;i++)
    {
        if(isp[i])
        {
            pr.pb(i);
            d3[i]=3;
            pw[i]=1;
            val[i]=i;
            mu[i]=-1;
        }
        for(int p:pr)
        {
            if(i*p>lim)
            {
                break;
            }
            isp[i*p]=false;
            if(i%p==0)
            {
                pw[i*p]=pw[i]+1;
                val[i*p]=val[i]*p;
                int rem=i/val[i];
                int a=pw[i*p];
                ll fpa=(ll)(a+1)*(a+2)/2;
                d3[i*p]=d3[rem]*fpa;
                mu[i*p]=0;
                break;
            }
            else
            {
                pw[i*p]=1;
                val[i*p]=p;
                d3[i*p]=d3[i]*3;
                mu[i*p]=-mu[i];
            }
        }
        s3[i]=(s3[i-1]+d3[i])%MOD;
    }
}
ll get2(ll n)
{
    ll sq=sqrt(n);
    ll res=0;
    for(ll i=1;i<=sq;i++)
    {
        res+=n/i;
    }
    res%=MOD;
    ll sqm=sq%MOD;
    res=(2*res-sqm*sqm)%MOD;
    return(res+MOD)%MOD;
}
ll get3(ll x)
{
    if(x<=lim)
    {
        return s3[x];
    }
    ll u=cbrt(x);
    while((u+1)*(u+1)*(u+1)<=x)
    {
        u++;
    }
    while(u*u*u>x)
    {
        u--;
    }
    ll sd2=0;
    for(ll a=1;a<=u;a++)
    {
        sd2=(sd2+get2(x/a))%MOD;
    }
    ll sab=0;
    for(ll a=1;a<=u;a++)
    {
        ll xa=x/a;
        ll cur=0;
        for(ll b=1;b<=u;b++)
        {
            cur+=xa/b;
        }
        sab=(sab+cur%MOD)%MOD;
    }
    ll um=u%MOD;
    ll u3=um*um%MOD*um%MOD;
    ll res=(3*sd2-3*sab+u3)%MOD;
    return(res+MOD)%MOD;
}
inline void solve()
{
    sieve();
    ll n;cin>>n;
    ll ans=0;
    ll sqn=sqrt(n);
    for(ll d=1;d<=sqn;d++)
    {
        if(mu[d]==0)
        {
            continue;
        }
        ll trm=get3(n/(d*d));
        // debug(trm);
        if(mu[d]==1)
        {
            ans=(ans+trm)%MOD;
        }
        else
        {
            ans=(ans-trm+MOD)%MOD;
        }
    }
    cout<<ans<<el;
}
int32_t main()
{
    fast;
    #define file "main"
    if(fopen(file".INP","r"))
    {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    TIME();
    return 0;
}
/**
 * Author:  hunglvh
 * Created: 2026-08-01 08:44:46
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

const int m_s=316250;
int mu[m_s];
bool is2[m_s];
vi pr2;
void sieve(int n)
{
    for(int i=2;i<=n;i++)
    {
        is2[i]=true;
    }
    is2[0]=false;
    is2[1]=false;
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is2[i])
        {
            pr2.pb(i);
            mu[i]=-1;
        }
        for(int p:pr2)
        {
            if(1LL*i*p>n)
            {
                break;
            }
            is2[i*p]=false;
            if(i%p==0)
            {
                mu[i*p]=0;
                break;
            }
            mu[i*p]=-mu[i];
        }
    }
}
ll d3(ll k)
{
    if(k==0)
    {
        return 0;
    }
    ll ans=0;
    ll cba=cbrt(k);
    while((cba+1)*(cba+1)*(cba+1)<=k)
    {
        cba++;
    }
    while(cba*cba*cba>k)
    {
        cba--;
    }
    for(ll a=1;a<=cba;a++)
    {
        ll trm=1+3*(k/(a*a)-a);
        ll mxb=sqrt(k/a);
        while((mxb+1)*(mxb+1)<=k/a)
        {
            mxb++;
        }
        while(mxb*mxb>k/a)
        {
            mxb--;
        }
        if(mxb>=a+1)
        {
            trm+=3*(mxb-a);
            ll smb=0;
            ll ka=k/a;
            for(ll b=a+1;b<=mxb;b++)
            {
                smb+=ka/b-b;
            }
            trm+=6*(smb%MOD);
        }
        ans=(ans+trm%MOD)%MOD;
    }
    return ans;
}
const int m_k=100005;
ll mem[m_k];
bool vis[m_k];
ll get(ll k)
{
    if(k<m_k)
    {
        if(vis[k])
        {
            return mem[k];
        }
        ll res=d3(k);
        vis[k]=true;
        mem[k]=res;
        return res;
    }
    return d3(k);
}
void run(ll n)
{
    vi f(n+1);
    vi pk(n+1);
    vc isp(n+1,1);
    vi pr;
    isp[0]=0;
    isp[1]=0;
    f[1]=1;
    ll ans=1;
    for(int i=2;i<=n;i++)
    {
        if(isp[i])
        {
            pr.pb(i);
            f[i]=3;
            pk[i]=1;
        }
        for(int p:pr)
        {
            if(1LL*i*p>n)
            {
                break;
            }
            isp[i*p]=0;
            if(i%p==0)
            {
                pk[i*p]=pk[i]+1;
                f[i*p]=f[i]/(2*pk[i]+1)*(2*pk[i*p]+1);
                break;
            }
            pk[i*p]=1;
            f[i*p]=f[i]*3;
        }
        ans=(ans+f[i])%MOD;
    }
    cout<<ans<<el;
}
inline void solve()
{
    ll n;
    cin>>n;
    if(n<=10000000)
    {
        run(n);
        return;
    }
    int sq=sqrt(n);
    sieve(sq);
    ll ans=0;
    for(int d=1;d<=sq;d++)
    {
        if(mu[d]==0)
        {
            continue;
        }
        ll k=n/(1LL*d*d);
        ll curr=get(k);
        ans=(ans+mu[d]*curr)%MOD;
    }
    ans=(ans%MOD+MOD)%MOD;
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
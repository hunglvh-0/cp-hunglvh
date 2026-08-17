/**
 * Author:  hunglvh
 * Created: 2026-08-15 19:15:56
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
#define arr(a,n) for(int i=0;i<n;i++)cin>>a[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define TIME() cerr<<endl<<"Time:"<<1000.0*clock()/CLOCKS_PER_SEC<<" ms."<<endl
#define i128 __int128
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template<class T> bool chmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool chmax(T& a, const T& b){return a<b?a=b,1:0;}
ll gcd(ll a, ll b){return std::gcd(a,b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll pow_mod(ll a, ll b, ll m=MOD){ll res=1;a%=m;while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}

const int max_n=2e5+5;
const ll md=998244353;
ll fc[max_n],iv[max_n];
bool ok=0;
void bld()
{
    fc[0]=1;iv[0]=1;
    for(int i=1;i<max_n;i++)
    {
        fc[i]=(fc[i-1]*i)%md;
    }
    iv[max_n-1]=pow_mod(fc[max_n-1],md-2,md);
    for(int i=max_n-2;i>=1;i--)
    {
        iv[i]=(iv[i+1]*(i+1))%md;
    }
    ok=1;
}
ll get(int n,int k)
{
    if(k<0 or k>n)
    {
        return 0;
    }
    return fc[n]*iv[k]%md*iv[n-k]%md;
}

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        if(!ok)
        {
            bld();
        }
        ll n=t+1,k;cin>>k;
        ll s1=0,s2=0;
        for(int i=0;i<n;i++)
        {
            ll x;cin>>x;
            x%=md;s1=(s1+x)%md;
            s2=(s2+x*x)%md;
        }
        ll c1=get(n-1,k-1);
        ll c2=get(n-2,k-2);
        ll crs=(s1*s1%md-s2+md)%md;
        ll ans=(c1*s2%md+c2*crs%md)%md;
        cout<<ans<<el;
        return;
    }
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
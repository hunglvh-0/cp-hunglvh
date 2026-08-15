/**
 * Author:  hunglvh
 * Created: 2026-08-08 19:54:20
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

const int max_n=300005;
int mn[4*max_n];
ll sum[4*max_n],rgt[4*max_n];

ll get(int id,int l,int r,int v)
{
    if(l==r)
    {
        return min(v,mn[id]);
    }
    int mid=(l+r)/2;
    if(mn[id*2]>=v)
    {
        return 1LL*(mid-l+1)*v+get(id*2+1,mid+1,r,v);
    }
    else
    {
        return get(id*2,l,mid,v)+rgt[id];
    }
}

void upd(int id,int l,int r,int p,int v)
{
    if(l==r)
    {
        mn[id]=v;sum[id]=v;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid)
    {
        upd(id*2,l,mid,p,v);
    }
    else
    {
        upd(id*2+1,mid+1,r,p,v);
    }
    mn[id]=min(mn[id*2],mn[id*2+1]);
    rgt[id]=get(id*2+1,mid+1,r,mn[id*2]);
    sum[id]=sum[id*2]+rgt[id];
}

inline void solve()
{
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        upd(1,0,n,x,i);
        ans+=sum[1];
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
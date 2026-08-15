/**
 * Author:  hunglvh
 * Created: 2026-08-14 17:11:37
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

struct seg
{
    int n;
    vl t;
    seg(int n):n(n)
    {
        t.assign(4*n+1,0);
    }
    void upd(int id,int l,int r,int pos,ll val)
    {
        if(l==r)
        {
            t[id]=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            upd(id*2,l,mid,pos,val);
        }
        else
        {
            upd(id*2+1,mid+1,r,pos,val);
        }
        t[id]=gcd(t[id*2],t[id*2+1]);
    }
    ll get(int id,int l,int r,int u,int v)
    {
        if(v<l or r<u)
        {
            return 0;
        }
        if(u<=l and r<=v)
        {
            return t[id];
        }
        int mid=(l+r)/2;
        return gcd(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
};
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vl a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n==1)
        {
            cout<<1<<el;
            continue;
        }
        vl b(n);
        seg st(n-1);
        for(int i=1;i<=n-1;i++)
        {
            b[i]=abs(a[i+1]-a[i]);
            st.upd(1,1,n-1,i,b[i]);
        }
        int ans=0;
        int l=1;
        for(int r=1;r<=n-1;r++)
        {
            while(l<=r and st.get(1,1,n-1,l,r)<2)
            {
                l++;
            }
            chmax(ans,r-l+1);
        }
        cout<<ans+1<<el;
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
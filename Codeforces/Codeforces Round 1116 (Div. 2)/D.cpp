/**
 * Author:  hunglvh
 * Created: 2026-08-09 21:47:30
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

const int max_n=1e6+5;
ll fact[max_n],inv[max_n];
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
        t[id]=t[id*2]+t[id*2+1];
    }
    ll get(int id,int l,int r,int u,int v)
    {
        if(v<l or r<u)return 0;
        if(u<=l and r<=v)return t[id];
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
    }
};
ll calc(int n,int k)
{
    if(k<0 or k>n)return 0;
    return fact[n]*inv[k]%998244353*inv[n-k]%998244353;
}
inline void solve()
{
    fact[0]=1;inv[0]=1;
    for(int i=1;i<max_n;i++)
    {
        fact[i]=(fact[i-1]*i)%998244353;
    }
    inv[max_n-1]=pow_mod(fact[max_n-1],998244353-2,998244353);
    for(int i=max_n-2;i>=1;i--)
    {
        inv[i]=(inv[i+1]*(i+1))%998244353;
    }
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        if(n<=1)
        {
            ll ans=1;cout<<ans<<el;
            continue;
        }
        seg st(n+5);
        int k=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                st.upd(1,1,n,i+1,1);
                k++;
            }
        }
        if(k==0)
        {
            ll ans=1;cout<<ans<<el;
            continue;
        }
        vl p;
        for(int i=1;i<=k;i++)
        {
            int l=1,r=n,pos=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(st.get(1,1,n,1,mid)>=i)
                {
                    pos=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            p.pb(pos-1);
        }
        vl c;c.pb(p[0]);
        for(int i=1;i<k;i++)
        {
            c.pb(p[i]-p[i-1]-1);
        }
        c.pb(n-2-p.back());
        ll s1=0,s2=0;
        for(int i=0;i<sz(c);i++)
        {
            if(i%2==0)
            {
                s1+=c[i];
            }
            else
            {
                s2+=c[i];
            }
        }
        ll v1=k/2+1;ll v2=(k+1)/2;
        ll ans1=calc(s1+v1-1,v1-1);ll ans2=calc(s2+v2-1,v2-1);
        ll ans=(ans1*ans2)%998244353;cout<<ans<<el;
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
/**
 * Author:  hunglvh
 * Created: 2026-08-17 21:59:08
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

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        ll s;int q;
        cin>>s>>q;
        vl d;
        for(ll i=1;i*i<=s;i++)
        {
            if(s%i==0)
            {
                d.pb(i);
                if(i*i!=s)
                {
                    d.pb(s/i);
                }
            }
        }
        sort(all(d));
        d.insert(d.begin(),0);
        d.pb(INF);
        int k=sz(d)-2;
        vl p(k+1,0);
        for(int i=1;i<=k;i++)
        {
            p[i]=p[i-1]+(d[i]-d[i-1])*(s/d[i]);
        }
        while(q--)
        {
            ll x,y;cin>>x>>y;
            ll sy=s/y;
            int ry=upper_bound(all(d),sy)-d.begin()-1;
            ll mx=min(x,d[ry]);
            if(mx==x)
            {
                cout<<x*y<<el;
                continue;
            }
            int rx=upper_bound(all(d),x)-d.begin()-1;
            ll ans=mx*y+p[rx]-p[ry];
            if(x>d[rx])
            {
                ans+=(x-d[rx])*(s/d[rx+1]);
            }
            cout<<ans<<el;
        }
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
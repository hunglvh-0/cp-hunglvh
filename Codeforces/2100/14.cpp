/**
 * Author:  hunglvh
 * Created: 2026-08-09 11:37:01
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

const int max_n=3e5+5;

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n,q;cin>>n>>q;
        vi b(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        vi x(q),y(q),z(q);
        for(int i=0;i<q;i++)
        {
            cin>>x[i]>>y[i]>>z[i];
        }
        vi a=b;
        for(int i=q-1;i>=0;i--)
        {
            int req=a[z[i]];
            if(x[i]!=z[i] and y[i]!=z[i])
            {
                a[x[i]]=max(a[x[i]],req);
                a[y[i]]=max(a[y[i]],req);
                a[z[i]]=0;
            }
            else if(x[i]==z[i] and y[i]!=z[i])
            {
                a[y[i]]=max(a[y[i]],req);
            }
            else if(x[i]!=z[i] and y[i]==z[i])
            {
                a[x[i]]=max(a[x[i]],req);
            }
        }
        vi c=a;
        for(int i=0;i<q;i++)
        {
            c[z[i]]=min(c[x[i]],c[y[i]]);
        }
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if(c[i]!=b[i])
            {
                ok=0;break;
            }
        }
        if(ok)
        {
            for(int i=1;i<=n;i++)
            {
                cout<<a[i]<<(i==n?"":" ");
            }
            cout<<el;
        }
        else
        {
            cout<<-1<<el;
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
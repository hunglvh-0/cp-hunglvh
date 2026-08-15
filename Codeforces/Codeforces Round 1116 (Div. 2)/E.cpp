/**
 * Author:  hunglvh
 * Created: 2026-08-09 22:10:50
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
    string type;cin>>type;
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vs g(n);arr(g,n);
        ll w=0,mr=0,mc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]=='#')
                {
                    w++;
                    mr=(mr+i)%n;
                    mc=(mc+j)%n;
                }
            }
        }
        ll inv=1;
        while((inv*(w%n))%n!=1)
        {
            inv++;
        }
        if(type=="first")
        {
            ll tr,tc;cin>>tr>>tc;
            tr--;tc--;
            ll rr=(tr*(w%n))%n;
            ll rc=(tc*(w%n))%n;
            ll dr=(rr-mr+n)%n;
            ll dc=(rc-mc+n)%n;
            if(dr==0 and dc==0)
            {
                cout<<"1 1 1 1"<<el;
            }
            else
            {
                bool ok=0;
                for(int r1=0;r1<n;r1++)
                {
                    if(ok)break;
                    for(int c1=0;c1<n;c1++)
                    {
                        if(g[r1][c1]=='#')
                        {
                            int r2=(r1+dr)%n;
                            int c2=(c1+dc)%n;
                            if(g[r2][c2]=='.')
                            {
                                cout<<r1+1<<" "<<c1+1<<" "<<r2+1<<" "<<c2+1<<el;
                                ok=1;break;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            cout<<(mr*inv)%n+1<<" "<<(mc*inv)%n+1<<el;
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
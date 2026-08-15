/**
 * Author:  hunglvh
 * Created: 2026-08-15 10:16:27
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
const int max_n=100005;
const int max_a=100005;
const int max_log=18;
int a[max_n];
int prm[max_a];
int lst[max_a];
int up[max_n][max_log];
void bld()
{
    for(int i=2;i<max_a;i++)
    {
        if(!prm[i])
        {
            for(int j=i;j<max_a;j+=i)
            {
                if(!prm[j])
                {
                    prm[j]=i;
                }
            }
        }
    }
}
inline void solve()
{
    bld();
    int t;cin>>t;
    while(t--)
    {
        int n=t+1,q;cin>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<max_a;i++)
        {
            lst[i]=n+1;
        }
        for(int i=0;i<max_log;i++)
        {
            up[n+1][i]=n+1;
        }
        for(int i=n;i>=1;i--)
        {
            up[i][0]=up[i+1][0];
            int x=a[i];
            while(x>1)
            {
                int p=prm[x];
                chmin(up[i][0],lst[p]);
                lst[p]=i;
                while(x%p==0)
                {
                    x/=p;
                }
            }
        }
        for(int j=1;j<max_log;j++)
        {
            for(int i=1;i<=n;i++)
            {
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }
        while(q--)
        {
            int l,r;cin>>l>>r;
            int ans=1,u=l;
            for(int j=max_log-1;j>=0;j--)
            {
                if(up[u][j]<=r)
                {
                    ans+=(1<<j);
                    u=up[u][j];
                }
            }
            cout<<ans<<el;
        }
        break;
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
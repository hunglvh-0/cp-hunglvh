/**
 * Author:  hunglvh
 * Created: 2026-08-13 07:07:34
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

const int md=998244353;
const int max_n=1<<20;
int a[21][max_n];

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n=t+1;int m=1<<n;
        for(int i=0;i<m;i++)
        {
            cin>>a[__builtin_popcount(i)][i];
        }
        for(int k=0;k<=n;k++)
        {
            for(int len=1;len<m;len<<=1)
            {
                for(int i=0;i<m;i+=2*len)
                {
                    for(int j=0;j<len;j++)
                    {
                        a[k][i+j+len]+=a[k][i+j];
                        if(a[k][i+j+len]>=md)
                        {
                            a[k][i+j+len]-=md;
                        }
                    }
                }
            }
        }
        for(int s=0;s<m;s++)
        {
            int a2[21]={0};
            for(int i=0;i<=n;i++)
            {
                if(!a[i][s])
                {
                    continue;
                }
                for(int j=0;j<=n-i;j++)
                {
                    a2[i+j]=(a2[i+j]+1LL*a[i][s]*a[j][s])%md;
                }
            }
            int a3[21]={0};
            for(int i=0;i<=n;i++)
            {
                if(!a2[i])
                {
                    continue;
                }
                for(int j=0;j<=n-i;j++)
                {
                    a3[i+j]=(a3[i+j]+1LL*a2[i]*a[j][s])%md;
                }
            }
            for(int k=0;k<=n;k++)
            {
                a[k][s]=a3[k];
            }
        }
        for(int k=0;k<=n;k++)
        {
            for(int len=1;len<m;len<<=1)
            {
                for(int i=0;i<m;i+=2*len)
                {
                    for(int j=0;j<len;j++)
                    {
                        a[k][i+j+len]-=a[k][i+j];
                        if(a[k][i+j+len]<0)
                        {
                            a[k][i+j+len]+=md;
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            int ans=a[__builtin_popcount(i)][i];cout<<ans<<" ";
        }
        cout<<el;
        break;
    }
}
int32_t main()
{
    fast;
    #define file "tamphan"
    if(fopen(file".INP","r"))
    {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    TIME();
    return 0;
}
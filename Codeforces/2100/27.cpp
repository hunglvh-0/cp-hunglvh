/**
 * Author:  hunglvh
 * Created: 2026-08-13 17:45:17
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

const int max_n=205;
const int max_v=5500;
int dp[max_n][max_v];
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n=t+1;
        int k;cin>>k;
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        int sum5=0;
        for(int i=0;i<n;i++)
        {
            ll x;cin>>x;
            int c2=0,c5=0;
            while(x%2==0)
            {
                c2++;
                x/=2;
            }
            while(x%5==0)
            {
                c5++;
                x/=5;
            }
            sum5+=c5;
            for(int j=min(i+1,k);j>=1;j--)
            {
                int l=min(max_v-1,sum5);
                for(int v=l;v>=c5;v--)
                {
                    if(dp[j-1][v-c5]!=-1)
                    {
                        chmax(dp[j][v],dp[j-1][v-c5]+c2);
                    }
                }
            }
        }
        int ans=0;
        for(int v=0;v<max_v;v++)
        {
            if(dp[k][v]!=-1)
            {
                chmax(ans,min(v,dp[k][v]));
            }
        }
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
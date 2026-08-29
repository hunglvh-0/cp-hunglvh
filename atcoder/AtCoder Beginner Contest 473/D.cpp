/**
 * Author: hunglvh
 * Created: 2026-08-29 20:15:33
 * ❤️C
**/
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
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

bool dp[15][200005];
int nxt[15][200005];
int n,k;
vi cur;
void dfs(int idx,int rem)
{
    if(idx==n+1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<cur[i];
            if(i<n-1)
            {
                cout<<" ";
            }
        }
        cout<<el;
        return;
    }
    int X=nxt[idx][rem];
    while(X!=-1)
    {
        int v=(rem-X)/idx;
        cur.pb(v);
        dfs(idx+1,X);
        cur.pop_back();
        if(X>=idx)
        {
            X=nxt[idx][X-idx];
        }
        else
        {
            break;
        }
    }
}
inline void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=0;
            nxt[i][j]=-1;
        }
    }
    cur.clear();
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j>=i)
            {
                dp[i][j]|=dp[i][j-i];
            }
        }
        for(int m=0;m<i;m++)
        {
            int last=-1;
            for(int j=m;j<=k;j+=i)
            {
                if(dp[i+1][j])
                {
                    last=j;
                }
                nxt[i][j]=last;
            }
        }
    }
    dfs(1,k);
}
int32_t main()
{
    fast;
    #define file ""
    if(fopen(file".inp","r"))
    {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    solve();
    TIME();
    return 0;
}
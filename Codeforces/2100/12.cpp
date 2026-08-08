/**
 * Author:  hunglvh
 * Created: 2026-08-07 11:34:57
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
#define arr(a,n) for (int i = 0; i < n; i++) cin >> a[i];
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define TIME() cerr << endl << "Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << " ms." << endl
#define i128 __int128
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template<class T> bool chmin(T& a, const T& b){return b < a ? a = b, 1 : 0;}
template<class T> bool chmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
ll gcd(ll a, ll b){return std::gcd(a, b);}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}
ll pow_mod(ll a, ll b, ll m = MOD){ll res = 1; a %= m;while (b > 0){if (b & 1) res = (res * a) % m;a = (a * a) % m;b >>= 1;}return res;}

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vvi adj(n+1);
        for(int i=2;i<=n;i++)
        {
            int p;cin>>p;
            adj[p].pb(i);
            if(count(all(adj[p]),i)>1)
            {
                adj[p].pop_back();
            }
        }
        vi dp(n+1,0);
        for(int i=n;i>=1;i--)
        {
            if(sz(adj[i])==0)
            {
                dp[i]=0;
            }
            else
            {
                ll sum=0;
                int mx=0;
                for(int v:adj[i])
                {
                    int add=(1LL<<dp[v]);
                    sum+=add;
                    chmax(mx,dp[v]);
                }
                int msb=0,pop=0;
                ll tmp=sum;
                while(tmp>0)
                {
                    if(tmp%2==1)
                    {
                        pop++;
                    }
                    tmp/=2;
                    if(tmp>0)
                    {
                        msb++;
                    }
                }
                int h=msb+(pop>1?1:0);
                dp[i]=max(mx+1,h);
            }
        }
        cout<<dp[1]<<el;
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
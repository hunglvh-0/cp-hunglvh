/**
 * Author:  hunglvh
 * Created: 2026-08-07 22:12:24
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
        int n,m,x,y;cin>>n>>m>>x>>y;
        vi a(x);arr(a,x);
        vi b(y);arr(b,y);
        vector<pii> val;
        int i=0,j=0;
        while(i<x and j<y)
        {
            if(a[i]==b[j])
            {
                val.pb({a[i],0});
                i++;j++;
            }
            else if(a[i]<b[j])
            {
                val.pb({a[i],1});i++;
            }
            else
            {
                val.pb({b[j],2});j++;
            }
        }
        while(i<x)
        {
            val.pb({a[i],1});i++;
        }
        while(j<y)
        {
            val.pb({b[j],2});j++;
        }
        sort(rall(val));
        ll ans=0;int tot=0;
        int ca=0,cb=0;
        for(auto p:val)
        {
            if(tot==n+m-1)
            {
                break;
            }
            if(p.s==0)
            {
                ans+=p.f;tot++;
            }
            else if(p.s==1)
            {
                if(ca<n)
                {
                    ans+=p.f;ca++;
                    tot++;
                }
            }
            else
            {
                if(cb<m)
                {
                    ans+=p.f;cb++;
                    tot++;
                }
            }
        }
        cout<<ans<<el;
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
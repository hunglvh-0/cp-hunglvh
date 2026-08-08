/**
 * Author:  hunglvh
 * Created: 2026-08-01 19:52:28
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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vi p;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o')
        {
            p.pb(i+1);
        }
    }
    double l=0.0,r=1.0;
    int m=sz(p);
    for(int it=0;it<70;it++)
    {
        double mid=(l+r)/2.0;
        double mn=1e18;bool ok=false;
        for(int j=k-1;j<m;j++)
        {
            int i=j-k+1;
            double cur=i-(p[i]-1)*mid;
            if(cur<mn)
            {
                mn=cur;
            }
            double end=(j+1)-p[j]*mid;
            if(end>=mn)
            {
                ok=true;break;
            }
        }
        if(ok)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<fixed<<setprecision(12)<<l<<el;
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
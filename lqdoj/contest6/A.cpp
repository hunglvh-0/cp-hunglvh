/**
 * Author:  hunglvh
 * Created: 2026-08-01 10:57:04
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
    ll u,v,w,z;
    cin>>u>>v>>w>>z;
    i128 d=u,x=v;
    i128 k=w,y=z;
    i128 kx=k*x;
    if(d<=kx)
    {
        i128 ans=(d+x-1)/x;
        string str="";
        if(ans==0)
        {
            str="0";
        }
        while(ans>0)
        {
            str+=char('0'+(int)(ans%10));
            ans/=10;
        }
        reverse(all(str));
        cout<<str<<el;
    }
    else
    {
        i128 c=kx-y;
        if(c<=0)
        {
            cout<<"-1"<<el;
            return;
        }
        i128 rem=d-kx;
        i128 cyc=(rem+c-1)/c;
        i128 lft=d-cyc*c;
        i128 ans=cyc*(k+1)+(lft+x-1)/x;
        string str="";
        if(ans==0)
        {
            str="0";
        }
        while(ans>0)
        {
            str+=char('0'+(int)(ans%10));
            ans/=10;
        }
        reverse(all(str));
        cout<<str<<el;
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
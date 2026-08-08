/**
 * Author:  hunglvh
 * Created: 2026-08-07 10:31:16
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

double dist(double xa,double ya,double xb,double yb)
{
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
bool chk(double x,double th)
{
    double k=x/th;
    return abs(k-round(k))<1e-4;
}
inline void solve()
{
    double xa,ya;cin>>xa>>ya;
    double xb,yb;cin>>xb>>yb;
    double xc,yc;cin>>xc>>yc;
    double a=dist(xb,yb,xc,yc);
    double b=dist(xa,ya,xc,yc);
    double c=dist(xa,ya,xb,yb);
    vector<double> v={a,b,c};sort(all(v));
    double p=(v[0]+v[1]+v[2])/2.0;
    double s=sqrt(p*(p-v[0])*(p-v[1])*(p-v[2]));
    double r=(v[0]*v[1]*v[2])/(4.0*s);
    double a1=acos(max(-1.0,min(1.0,(2.0*r*r-v[0]*v[0])/(2.0*r*r))));
    double a2=acos(max(-1.0,min(1.0,(2.0*r*r-v[1]*v[1])/(2.0*r*r))));
    double a3=2.0*acos(-1.0)-a1-a2;
    double ans=0;
    for(int n=3;n<=100;n++)
    {
        double th=2.0*acos(-1.0)/n;
        if(chk(a1,th) and chk(a2,th) and chk(a3,th))
        {
            ans=((double)n/2.0)*r*r*sin(th);
            break;
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<el;
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
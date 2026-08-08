/**
 * Author:  hunglvh
 * Created: 2026-08-01 20:06:44
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

const int max_m=2e5+5;
pii edg[max_m];
bool chk(int u,int v,int m)
{
    for(int i=0;i<m;i++)
    {
        if(edg[i].f!=u and edg[i].s!=u and edg[i].f!=v and edg[i].s!=v)
        {
            return false;
        }
    }
    return true;
}
inline void solve()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>edg[i].f>>edg[i].s;
    }
    int a=edg[0].f,b=edg[0].s;
    vi sa,sb;
    for(int i=0;i<m;i++)
    {
        if(edg[i].f!=a and edg[i].s!=a)
        {
            sa.pb(i);
        }
        if(edg[i].f!=b and edg[i].s!=b)
        {
            sb.pb(i);
        }
    }
    if(sz(sa)==0 and sz(sb)==0)
    {
        ll ans=2ll*n-3;cout<<ans<<el;
    }
    else if(sz(sa)==0)
    {
        ll ans=n-1;
        int k=sb[0];
        int u=edg[k].f,v=edg[k].s;
        if(u!=a and chk(b,u,m))
        {
            ans++;
        }
        if(v!=a and chk(b,v,m))
        {
            ans++;
        }
        cout<<ans<<el;
    }
    else if(sz(sb)==0)
    {
        ll ans=n-1;
        int k=sa[0];
        int u=edg[k].f,v=edg[k].s;
        if(u!=b and chk(a,u,m))
        {
            ans++;
        }
        if(v!=b and chk(a,v,m))
        {
            ans++;
        }
        cout<<ans<<el;
    }
    else
    {
        set<pii> st;
        int ka=sa[0];
        int ua=edg[ka].f,va=edg[ka].s;
        if(chk(a,ua,m))
        {
            st.insert({min(a,ua),max(a,ua)});
        }
        if(chk(a,va,m))
        {
            st.insert({min(a,va),max(a,va)});
        }
        int kb=sb[0];
        int ub=edg[kb].f,vb=edg[kb].s;
        if(chk(b,ub,m))
        {
            st.insert({min(b,ub),max(b,ub)});
        }
        if(chk(b,vb,m))
        {
            st.insert({min(b,vb),max(b,vb)});
        }
        ll ans=sz(st);cout<<ans<<el;
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
/**
 * Author: hunglvh
 * Created: 2026-08-30 19:00:33
 * ❤️C
**/
#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <atcoder/all>
using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;
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

using S=pll;
S sop(S a,S b){return min(a,b);}
S se(){return {INF,-1};}
inline void solve()
{
    int n;cin>>n;
    vi p(n);arr(p,n);
    for(int i=0;i<n;i++)
    {
        p[i]--;
    }
    vl a(n);arr(a,n);
    vi lf(n,0);stack<int> stk;
    for(int i=0;i<n;i++)
    {
        while(sz(stk) and p[stk.top()]<p[i])
        {
            stk.pop();
        }
        if(sz(stk))
        {
            lf[i]=stk.top();
        }
        stk.push(i);
    }
    segtree<S,sop,se> seg(n);
    vi cnt(n,0);
    seg.set(0,{a[p[0]],0});
    for(int k=1;k<n;k++)
    {
        pll res=seg.prod(lf[k],k);
        int j=(int)res.s;
        cnt[j]++;
        seg.set(j,{a[p[j]]*(2LL*cnt[j]+1LL),j});
        seg.set(k,{a[p[k]],k});
    }
    ll ans=0;
    for(int j=0;j<n;j++)
    {
        ans+=a[p[j]]*1LL*cnt[j]*cnt[j];
    }
    cout<<ans<<el;
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
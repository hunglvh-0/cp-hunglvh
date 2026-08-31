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

struct State
{
    ll len;
    vl ms;
};
void add(vl&ms,ll x)
{
    if(x==0) return;
    ms.pb(x);
    for(int i=sz(ms)-1;i>0;i--)
    {
        if(ms[i]>ms[i-1]) swap(ms[i],ms[i-1]);
        else break;
    }
}
vector<State> prune(vector<State>&v)
{
    vector<State> nv;
    for(State&s:v)
    {
        while(sz(nv)>0 and nv.back().ms<=s.ms) nv.pop_back();
        nv.pb(s);
    }
    return nv;
}
bool check_cov(vector<pll>&segs,ll l)
{
    if(sz(segs)==0) return false;
    int idx=upper_bound(all(segs),make_pair(l,INF))-segs.begin()-1;
    if(idx>=0 and segs[idx].f<=l and l<=segs[idx].s) return true;
    return false;
}
inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pll> c1(n),c2(m);
        for(int i=0;i<n;i++) cin>>c1[i].f>>c1[i].s;
        for(int i=0;i<m;i++) cin>>c2[i].f>>c2[i].s;
        set<ll> pts;
        for(pll&p:c1)
        {
            pts.insert(p.f);
            pts.insert(p.s+1LL);
        }
        for(pll&p:c2)
        {
            pts.insert(p.f);
            pts.insert(p.s+1LL);
        }
        vl x(all(pts));
        vl ans;
        vector<State> dp1,dp2;
        for(int i=0;i<sz(x)-1;i++)
        {
            ll l=x[i],r=x[i+1]-1LL;
            if(l>r) continue;
            bool ok1=check_cov(c1,l);
            bool ok2=check_cov(c2,l);
            if(not ok1 and not ok2)
            {
                if(sz(dp1)>0 or sz(dp2)>0)
                {
                    vl best;
                    for(State&s:dp1)
                    {
                        vl ms=s.ms;
                        add(ms,s.len);
                        if(ms>best) best=ms;
                    }
                    for(State&s:dp2)
                    {
                        vl ms=s.ms;
                        add(ms,s.len);
                        if(ms>best) best=ms;
                    }
                    for(ll v:best) ans.pb(v);
                    dp1.clear();
                    dp2.clear();
                }
                continue;
            }
            ll w=r-l+1LL;
            vector<State> ndp1,ndp2;
            if(ok1)
            {
                State bs;
                bool hs=false;
                for(State&s:dp2)
                {
                    State ns=s;
                    add(ns.ms,ns.len);
                    ns.len=w;
                    if(not hs or ns.ms>bs.ms)
                    {
                        bs=ns;
                        hs=true;
                    }
                }
                if(hs) ndp1.pb(bs);
                for(State&s:dp1) ndp1.pb({s.len+w,s.ms});
                if(sz(dp1)==0 and sz(dp2)==0) ndp1.pb({w,{}});
            }
            if(ok2)
            {
                State bs;
                bool hs=false;
                for(State&s:dp1)
                {
                    State ns=s;
                    add(ns.ms,ns.len);
                    ns.len=w;
                    if(not hs or ns.ms>bs.ms)
                    {
                        bs=ns;
                        hs=true;
                    }
                }
                if(hs) ndp2.pb(bs);
                for(State&s:dp2) ndp2.pb({s.len+w,s.ms});
                if(sz(dp1)==0 and sz(dp2)==0) ndp2.pb({w,{}});
            }
            dp1=prune(ndp1);
            dp2=prune(ndp2);
        }
        if(sz(dp1)>0 or sz(dp2)>0)
        {
            vl best;
            for(State&s:dp1)
            {
                vl ms=s.ms;
                add(ms,s.len);
                if(ms>best) best=ms;
            }
            for(State&s:dp2)
            {
                vl ms=s.ms;
                add(ms,s.len);
                if(ms>best) best=ms;
            }
            for(ll v:best) ans.pb(v);
        }
        sort(rall(ans));
        cout<<sz(ans)<<el;
        for(int i=0;i<sz(ans);i++) cout<<ans[i]<<(i==sz(ans)-1?"":" ");
        cout<<el;
    }
}
int32_t main()
{
    fast;
    solve();
    return 0;
}


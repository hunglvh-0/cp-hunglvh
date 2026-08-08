/**
 * Author:  hunglvh
 * Created: 2026-08-07 05:25:06
 * ❤️C
**/
#include <bits/stdc++.h>
using namespace std;
#define ll int
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

const int max_n=1000005;
vl adj[max_n];
ll in[max_n],out[max_n];
ll dep[max_n];
ll up[20][max_n];
ll tim;
ll imp[max_n];
vector<pll> aux[max_n];
ll tot;
ll cen;
void dfs(ll u,ll p)
{
    in[u]=++tim;up[0][u]=p;
    for(ll i=1;i<20;i++)
    {
        up[i][u]=up[i-1][up[i-1][u]];
    }
    for(ll v:adj[u])
    {
        if(v!=p)
        {
            dep[v]=dep[u]+1;dfs(v,u);
        }
    }
    out[u]=tim;
}
bool is_anc(ll u,ll v)
{
    return in[u]<=in[v] and out[v]<=out[u];
}
ll get_lca(ll u,ll v)
{
    if(is_anc(u,v))
    {
        return u;
    }
    if(is_anc(v,u))
    {
        return v;
    }
    for(ll i=19;i>=0;i--)
    {
        if(!is_anc(up[i][u],v))
        {
            u=up[i][u];
        }
    }
    return up[0][u];
}
ll get_dis(ll u,ll v)
{
    return dep[u]+dep[v]-2*dep[get_lca(u,v)];
}
ll dfs1(ll u,ll p)
{
    ll sz=imp[u];
    ll mxb=0;
    for(auto e:aux[u])
    {
        ll v=e.f;
        if(v!=p)
        {
            ll ssz=dfs1(v,u);
            sz+=ssz;chmax(mxb,ssz);
        }
    }
    chmax(mxb,tot-sz);
    if(mxb<=tot/2)
    {
        cen=u;
    }
    return sz;
}
vector<pll> wei;
ll dfs2(ll u,ll p)
{
    ll sz=imp[u];
    for(auto e:aux[u])
    {
        ll v=e.f;
        if(v!=p)
        {
            ll ssz=dfs2(v,u);
            sz+=ssz;wei.pb({ssz,e.s});
        }
    }
    return sz;
}
bool cmp(ll u,ll v)
{
    return in[u]<in[v];
}
inline void solve()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vl c(n+1),k(n+1);
        vector<vl> col(n+1);
        for(ll i=1;i<=n;i++)
        {
            cin>>c[i];col[c[i]].pb(i);
        }
        for(ll i=1;i<=n;i++)
        {
            cin>>k[i];
        }
        for(ll i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(ll i=0;i<n-1;i++)
        {
            ll u,v;cin>>u>>v;
            adj[u].pb(v);adj[v].pb(u);
        }
        tim=0;dep[1]=0;
        dfs(1,1);
        vl ans(n+1,-1);
        for(ll i=1;i<=n;i++)
        {
            if(sz(col[i])==0)
            {
                continue;
            }
            vl nod=col[i];
            for(ll u:nod)
            {
                imp[u]=1;
            }
            tot=sz(col[i]);
            sort(all(nod),cmp);
            ll kn=sz(nod);
            for(ll j=0;j<kn-1;j++)
            {
                nod.pb(get_lca(nod[j],nod[j+1]));
            }
            sort(all(nod),cmp);
            nod.erase(unique(all(nod)),nod.end());
            for(ll u:nod)
            {
                aux[u].clear();
            }
            vl st;
            for(ll u:nod)
            {
                while(sz(st)>0 and !is_anc(st.back(),u))
                {
                    st.pop_back();
                }
                if(sz(st)>0)
                {
                    ll p=st.back();
                    ll len=dep[u]-dep[p];
                    aux[p].pb({u,len});aux[u].pb({p,len});
                }
                st.pb(u);
            }
            cen=-1;dfs1(nod[0],-1);
            wei.clear();dfs2(cen,-1);
            ll sum=0;
            for(ll u:col[i])
            {
                sum+=get_dis(u,cen);
            }
            sort(rall(wei));
            ll rem=k[i]-1;
            for(auto p:wei)
            {
                ll val=p.f;ll len=p.s;
                ll tk=min(rem,len);
                sum-=tk*val;rem-=tk;
                if(rem==0)
                {
                    break;
                }
            }
            ans[i]=sum;
            for(ll u:nod)
            {
                imp[u]=0;
            }
        }
        for(ll i=1;i<=n;i++)
        {
            cout<<ans[i]<<(i==n?"":" ");
        }
        cout<<el;
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
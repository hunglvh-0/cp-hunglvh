/**
 * Author:  hunglvh
 * Created: 2026-08-13 05:47:32
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
const int mxa=1000005;
const int max_n=120005;
const ll md=998244353;
int mnp[mxa];
pll rdh[mxa];
pll hvl[mxa];
bool sdn=0;
vi adj[max_n];
bool del[max_n];
int sub[max_n];
ll aa[max_n];
ll wa[max_n];
ll ans[max_n];

pll grd(mt19937_64& rng)
{
    return{rng(),rng()};
}
pll mrg(pll a,pll b)
{
    return{a.f^b.f,a.s^b.s};
}
void init()
{
    mt19937_64 rng(1337);
    for(int i=2;i<mxa;i++)
    {
        if(!mnp[i])
        {
            mnp[i]=i;
            rdh[i]=grd(rng);
            for(int j=i*2;j<mxa;j+=i)
            {
                if(!mnp[j])
                {
                    mnp[j]=i;
                }
            }
        }
    }
    hvl[1]={0,0};
    for(int i=2;i<mxa;i++)
    {
        hvl[i]=mrg(hvl[i/mnp[i]],rdh[mnp[i]]);
    }
    sdn=1;
}
void ntt(vl& a,bool inv)
{
    int n=sz(a);
    for(int i=1,j=0;i<n;i++)
    {
        int bit=n>>1;
        for(;j&bit;bit>>=1)
        {
            j^=bit;
        }
        j^=bit;
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    for(int len=2;len<=n;len<<=1)
    {
        ll wlen=pow_mod(3,(md-1)/len,md);
        if(inv)
        {
            wlen=pow_mod(wlen,md-2,md);
        }
        for(int i=0;i<n;i+=len)
        {
            ll w=1;
            for(int j=0;j<len/2;j++)
            {
                ll u=a[i+j];
                ll v=a[i+j+len/2]*w%md;
                a[i+j]=u+v<md?u+v:u+v-md;
                a[i+j+len/2]=u-v>=0?u-v:u-v+md;
                w=w*wlen%md;
            }
        }
    }
    if(inv)
    {
        ll inv_n=pow_mod(n,md-2,md);
        for(ll& x:a)
        {
            x=x*inv_n%md;
        }
    }
}
vl mul(vl const& a,vl const& b)
{
    if(a.empty() or b.empty())
    {
        return{};
    }
    vl fa(all(a));
    vl fb(all(b));
    int n=1;
    while(n<sz(a)+sz(b))
    {
        n<<=1;
    }
    fa.resize(n);
    fb.resize(n);
    ntt(fa,0);
    ntt(fb,0);
    for(int i=0;i<n;i++)
    {
        fa[i]=fa[i]*fb[i]%md;
    }
    ntt(fa,1);
    vl res(sz(a)+sz(b)-1);
    for(int i=0;i<sz(res);i++)
    {
        res[i]=fa[i];
    }
    return res;
}
void gsz(int u,int p)
{
    sub[u]=1;
    for(int v:adj[u])
    {
        if(v!=p and !del[v])
        {
            gsz(v,u);
            sub[u]+=sub[v];
        }
    }
}
int gct(int u,int p,int tot)
{
    for(int v:adj[u])
    {
        if(v!=p and !del[v] and sub[v]*2>tot)
        {
            return gct(v,u,tot);
        }
    }
    return u;
}
struct ndi
{
    int d;
    pll h;
    ll w;
};
vector<ndi> cmp;
void get(int u,int p,int d,pll h,ll w)
{
    cmp.pb({d,h,w});
    for(int v:adj[u])
    {
        if(v!=p and !del[v])
        {
            get(v,u,d+1,mrg(h,hvl[aa[v]]),w*wa[v]%md);
        }
    }
}
struct pnd
{
    int d;
    ll v;
    ll sq;
};
struct ply
{
    pll h;
    vector<pnd> p;
};
void cal(vector<ndi> tmp,bool add,pll tgt,ll wc)
{
    sort(all(tmp),[](const ndi& a,const ndi& b)
    {
        if(a.h.f!=b.h.f)
        {
            return a.h.f<b.h.f;
        }
        return a.h.s<b.h.s;
    });
    vector<ply> pls;
    int nm=sz(tmp);
    for(int i=0;i<nm;)
    {
        int j=i;
        while(j<nm and tmp[j].h.f==tmp[i].h.f and tmp[j].h.s==tmp[i].h.s)
        {
            j++;
        }
        sort(tmp.begin()+i,tmp.begin()+j,[](const ndi& a,const ndi& b)
        {
            return a.d<b.d;
        });
        vector<pnd> p;
        for(int k=i;k<j;++k)
        {
            if(p.empty() or p.back().d!=tmp[k].d)
            {
                p.pb({tmp[k].d,tmp[k].w,tmp[k].w*tmp[k].w%md});
            }
            else
            {
                p.back().v=(p.back().v+tmp[k].w)%md;
                p.back().sq=(p.back().sq+tmp[k].w*tmp[k].w)%md;
            }
        }
        pls.pb({tmp[i].h,p});
        i=j;
    }
    int nmp=sz(pls);
    for(int i=0;i<nmp;i++)
    {
        pll u=pls[i].h;
        pll v=mrg(u,tgt);
        bool ils=0;
        if(v.f<u.f)
        {
            ils=1;
        }
        else if(v.f==u.f and v.s<u.s)
        {
            ils=1;
        }
        if(ils)
        {
            continue;
        }
        int low=i;
        int high=nmp-1;
        int id=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            bool ieq=0;
            if(pls[mid].h.f==v.f and pls[mid].h.s==v.s)
            {
                ieq=1;
            }
            if(ieq)
            {
                id=mid;
                break;
            }
            bool ls=0;
            if(pls[mid].h.f<v.f)
            {
                ls=1;
            }
            else if(pls[mid].h.f==v.f and pls[mid].h.s<v.s)
            {
                ls=1;
            }
            if(ls)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(id!=-1)
        {
            auto& p1=pls[i].p;
            auto& p2=pls[id].p;
            int d1=p1.back().d+1;
            int d2=p2.back().d+1;
            u64 cbf=1ULL*sz(p1)*sz(p2);
            vl res;
            if(cbf<=50000)
            {
                res.assign(d1+d2-1,0);
                for(auto& x:p1)
                {
                    for(auto& y:p2)
                    {
                        res[x.d+y.d]=(res[x.d+y.d]+x.v*y.v)%md;
                    }
                }
            }
            else
            {
                vl a(d1,0);
                vl b(d2,0);
                for(auto& x:p1)
                {
                    a[x.d]=x.v;
                }
                for(auto& y:p2)
                {
                    b[y.d]=y.v;
                }
                res=mul(a,b);
            }
            bool ieq=(u.f==v.f and u.s==v.s);
            if(ieq)
            {
                for(auto& x:p1)
                {
                    res[x.d*2]=(res[x.d*2]-x.sq+md)%md;
                }
                ll inv=499122177;
                for(int d=0;d<sz(res);d++)
                {
                    if(!res[d])
                    {
                        continue;
                    }
                    ll val=res[d]*inv%md*wc%md;
                    if(!add)
                    {
                        val=(md-val)%md;
                    }
                    ans[d]=(ans[d]+val)%md;
                }
            }
            else
            {
                for(int d=0;d<sz(res);d++)
                {
                    if(!res[d])
                    {
                        continue;
                    }
                    ll val=res[d]*wc%md;
                    if(!add)
                    {
                        val=(md-val)%md;
                    }
                    ans[d]=(ans[d]+val)%md;
                }
            }
        }
    }
}
void dec(int u,int k)
{
    gsz(u,-1);
    int c=gct(u,-1,sub[u]);
    cmp.clear();
    cmp.pb({0,{0,0},1});
    pll tgt=mrg(hvl[k],hvl[aa[c]]);
    for(int v:adj[c])
    {
        if(!del[v])
        {
            int st=sz(cmp);
            get(v,c,1,hvl[aa[v]],wa[v]);
            vector<ndi> tmp(cmp.begin()+st,cmp.end());
            cal(tmp,0,tgt,wa[c]);
        }
    }
    cal(cmp,1,tgt,wa[c]);
    del[c]=1;
    for(int v:adj[c])
    {
        if(!del[v])
        {
            dec(v,k);
        }
    }
}

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        if(!sdn)
        {
            init();
        }
        int n=t+1;
        int k;cin>>k;
        for(int i=0;i<=n;i++)
        {
            ans[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            del[i]=0;
        }
        for(int i=2;i<=n;i++)
        {
            int p;cin>>p;
            adj[p].pb(i);
            adj[i].pb(p);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>aa[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>wa[i];
        }
        dec(1,k);
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<(i==n-1?"":" ");
        }
        cout<<el;
        t=0;
    }
}
int32_t main()
{
    fast;
    #define file "tuyenduong"
    if(fopen(file".INP","r"))
    {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    TIME();
    return 0;
}
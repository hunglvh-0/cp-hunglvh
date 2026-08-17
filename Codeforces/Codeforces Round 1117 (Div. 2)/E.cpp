/**
 * Author:  hunglvh
 * Created: 2026-08-17 21:34:58
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

struct seg
{
    int n;
    vl t,lz;
    seg(int n):n(n)
    {
        t.assign(4*n+1,0);
        lz.assign(4*n+1,0);
    }
    void push(int id)
    {
        if(lz[id])
        {
            t[id*2]+=lz[id];
            lz[id*2]+=lz[id];
            t[id*2+1]+=lz[id];
            lz[id*2+1]+=lz[id];
            lz[id]=0;
        }
    }
    void build(int id,int l,int r,const vl& D)
    {
        if(l==r)
        {
            t[id]=D[l];
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid,D);
        build(id*2+1,mid+1,r,D);
        t[id]=max(t[id*2],t[id*2+1]);
    }
    void upd(int id,int l,int r,int u,int v,ll val)
    {
        if(v<l or r<u)return;
        if(u<=l and r<=v)
        {
            t[id]+=val;
            lz[id]+=val;
            return;
        }
        push(id);
        int mid=(l+r)/2;
        upd(id*2,l,mid,u,v,val);
        upd(id*2+1,mid+1,r,u,v,val);
        t[id]=max(t[id*2],t[id*2+1]);
    }
    int get(int id,int l,int r,ll A)
    {
        if(t[id]<=A)return n+1;
        if(l==r)return l;
        push(id);
        int mid=(l+r)/2;
        if(t[id*2]>A)return get(id*2,l,mid,A);
        return get(id*2+1,mid+1,r,A);
    }
};

struct bit
{
    int n;
    vl f;
    bit(int n):n(n)
    {
        f.assign(n+1,0);
    }
    void upd(int i,ll v)
    {
        for(;i<=n;i+=i&-i)
        {
            f[i]+=v;
        }
    }
    ll get(int i)
    {
        ll res=0;
        for(;i>0;i-=i&-i)
        {
            res+=f[i];
        }
        return res;
    }
};

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n;ll x;
        cin>>n>>x;
        vvl a(n),b(n);
        vector<vector<pll>> S(n);
        vector<ll> U;
        for(int ib=0;ib<n;ib++)
        {
            int m;cin>>m;
            a[ib].resize(m);b[ib].resize(m);
            arr(a[ib],m);arr(b[ib],m);
            stack<pll> st;
            for(int j=m-1;j>=0;j--)
            {
                ll r=a[ib][j],p=b[ib][j]-a[ib][j];
                while(sz(st))
                {
                    auto tp=st.top();
                    if(tp.s<=0)
                    {
                        break;
                    }
                    if(p<=0 or r+p>=tp.f)
                    {
                        st.pop();
                        chmax(r,tp.f-p);
                        p+=tp.s;
                    }
                    else
                    {
                        break;
                    }
                }
                st.push({r,p});
            }
            while(sz(st))
            {
                auto tp=st.top();st.pop();
                if(tp.s>0)
                {
                    S[ib].pb(tp);
                    U.pb(tp.f);
                }
            }
        }
        U.pb(INF);
        sort(all(U));
        U.erase(unique(all(U)),U.end());
        int V=sz(U)-1;
        auto get_id=[&](ll r){return lower_bound(all(U),r)-U.begin()+1;};
        vl P(V+2,0);
        for(int ib=0;ib<n;ib++)
        {
            for(auto& sg:S[ib])
            {
                P[get_id(sg.f)]+=sg.s;
            }
        }
        vl Pref(V+2,0);
        for(int i=1;i<=V+1;i++)
        {
            Pref[i]=Pref[i-1]+P[i];
        }
        vl D(V+2,0);
        for(int i=1;i<=V+1;i++)
        {
            if(i==V+1)
            {
                D[i]=INF;
            }
            else
            {
                D[i]=U[i-1]-Pref[i-1];
            }
        }
        bit fenw(V+1);
        for(int i=1;i<=V+1;i++)
        {
            if(P[i]>0)
            {
                fenw.upd(i,P[i]);
            }
        }
        seg tr(V+1);
        tr.build(1,1,V+1,D);
        vi ans={-1,-1};
        for(int ib=0;ib<n;ib++)
        {
            for(auto& sg:S[ib])
            {
                int id=get_id(sg.f);
                fenw.upd(id,-sg.s);
                tr.upd(1,1,V+1,id+1,V+1,sg.s);
            }
            ll A_equiv=x;
            int k_star=tr.get(1,1,V+1,A_equiv);
            ll curr=x+fenw.get(k_star-1);
            ll mx=curr;
            int h=0;
            for(int j=0;j<sz(a[ib]);j++)
            {
                if(curr<a[ib][j])
                {
                    break;
                }
                curr=curr-a[ib][j]+b[ib][j];
                h++;
                if(curr>mx)
                {
                    int old_k=k_star;
                    A_equiv=curr-fenw.get(k_star-1);
                    k_star=tr.get(1,1,V+1,A_equiv);
                    curr+=fenw.get(k_star-1)-fenw.get(old_k-1);
                    mx=curr;
                }
            }
            if(h>ans[0])
            {
                ans[0]=h;ans[1]=ib+1;
            }
            for(auto& sg:S[ib])
            {
                int id=get_id(sg.f);
                fenw.upd(id,sg.s);
                tr.upd(1,1,V+1,id+1,V+1,-sg.s);
            }
        }
        cout<<ans[0]<<" "<<ans[1]<<el;
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
/**
 * Author:  hunglvh
 * Created: 2026-08-01 09:20:29
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

const i128 inf=((i128)1<<120);
struct lin
{
    ll m;i128 c;
    i128 ev(ll x) const
    {
        return (i128)m*x+c;
    }
};
struct cht
{
    vector<lin> hul;
    bool bad(const lin& l1,const lin& l2,const lin& l3)
    {
        i128 v1=(l1.c-l3.c)*(l2.m-l1.m);
        i128 v2=(l1.c-l2.c)*(l3.m-l1.m);
        return v1>=v2;
    }
    void add(ll m,i128 c)
    {
        lin ln={m,c};
        if(!hul.empty() and hul.back().m==m)
        {
            if(c<hul.back().c)
            {
                hul.pop_back();
            }
            else
            {
                return;
            }
        }
        while(sz(hul)>=2 and bad(hul[sz(hul)-2],hul.back(),ln))
        {
            hul.pop_back();
        }
        hul.pb(ln);
    }
    i128 qry(ll x)
    {
        if(hul.empty())
        {
            return inf;
        }
        int left=0,right=sz(hul)-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            i128 y1=hul[mid].ev(x);
            i128 y2=hul[mid+1].ev(x);
            if(y1>y2)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return hul[left].ev(x);
    }
};
const int m_n=50005;
int n;ll cv,lv;
ll ps[m_n];
i128 dp[m_n];
bool cmp(int a,int b)
{
    if(ps[a]!=ps[b])
    {
        return ps[a]>ps[b];
    }
    return a<b;
}
void cdq(int left,int right,const vi& nds)
{
    if(left==right)
    {
        return;
    }
    int mid=left+(right-left)/2;
    vi ls,rs;
    ls.reserve(mid-left+1);
    rs.reserve(right-mid);
    for(int id:nds)
    {
        if(id<=mid)
        {
            ls.pb(id);
        }
        else
        {
            rs.pb(id);
        }
    }
    cdq(left,mid,ls);
    cht tree;int pt=0;
    for(int i:rs)
    {
        ll lim=ps[i]-lv;
        while(pt<sz(ls) and ps[ls[pt]]>=lim)
        {
            int j=ls[pt];
            if(dp[j]!=inf)
            {
                tree.add(-2LL*ps[j],dp[j]+(i128)ps[j]*ps[j]);
            }
            pt++;
        }
        i128 res=tree.qry(ps[i]);
        if(res!=inf)
        {
            i128 nc=res+(i128)ps[i]*ps[i]+cv;
            if(nc<dp[i])
            {
                dp[i]=nc;
            }
        }
    }
    cdq(mid+1,right,rs);
}
inline void solve()
{
    cin>>n>>cv>>lv;
    ps[0]=0;
    for(int i=1;i<=n;i++)
    {
        ll val;cin>>val;
        ps[i]=ps[i-1]+val;
    }
    vi st(n+1);
    iota(all(st),0);
    sort(all(st),cmp);
    for(int i=0;i<=n;i++)
    {
        dp[i]=inf;
    }
    dp[0]=0;
    cdq(0,n,st);
    if(dp[n]==inf)
    {
        cout<<"-1"<<el;
    }
    else
    {
        string str="";
        i128 ans=dp[n];
        if(ans==0)
        {
            cout<<"0"<<el;
        }
        else
        {
            while(ans>0)
            {
                str+=(char)('0'+(int)(ans%10));
                ans/=10;
            }
            reverse(all(str));
            cout<<str<<el;
        }
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
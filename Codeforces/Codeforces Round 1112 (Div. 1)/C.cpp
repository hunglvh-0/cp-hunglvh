/**
 * Author:  hunglvh
 * Created: 2026-07-26 21:45:45
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
const int m_n=3e5+5;
const int m_m=2e6+5;
int tr[m_m];
int lz[m_m];
vi upd[m_n];
void push(int nd)
{
    if(lz[nd])
    {
        tr[2*nd]+=lz[nd];
        lz[2*nd]+=lz[nd];
        tr[2*nd+1]+=lz[nd];
        lz[2*nd+1]+=lz[nd];
        lz[nd]=0;
    }
}
void build(int nd,int st,int en,vi& pf)
{
    lz[nd]=0;
    if(st==en)
    {
        tr[nd]=pf[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*nd,st,mid,pf);
    build(2*nd+1,mid+1,en,pf);
    tr[nd]=max(tr[2*nd],tr[2*nd+1]);
}
void update(int nd,int st,int en,int l,int r,int v)
{
    if(l>en or r<st) return;
    if(l<=st and en<=r)
    {
        tr[nd]+=v;
        lz[nd]+=v;
        return;
    }
    push(nd);
    int mid=(st+en)/2;
    update(2*nd,st,mid,l,r,v);
    update(2*nd+1,mid+1,en,l,r,v);
    tr[nd]=max(tr[2*nd],tr[2*nd+1]);
}
int query(int nd,int st,int en,int l,int r)
{
    if(l>en or r<st) return -1e9;
    if(l<=st and en<=r) return tr[nd];
    push(nd);
    int mid=(st+en)/2;
    return max(query(2*nd,st,mid,l,r),query(2*nd+1,mid+1,en,l,r));
}
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vi p(2*n);
        vi ps(n+1);
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            ps[p[i]]=i;
            p[i+n]=p[i];
            upd[i].clear();
        }
        vi pf(2*n,0);
        for(int j=0;j<2*n;j++)
        {
            int x=p[j];
            int l1=-1,l2=-1;
            if(x>1)
            {
                int d=(j%n)-ps[x-1];
                if(d<=0) d+=n;
                l1=j-d;
            }
            if(x<n)
            {
                int d=(j%n)-ps[x+1];
                if(d<=0) d+=n;
                l2=j-d;
            }
            if(l1>=0 and l1<n) upd[l1].pb(j);
            if(l2>=0 and l2<n) upd[l2].pb(j);
            int v=-1+(l1<0)+(l2<0);
            pf[j]=v;
            if(j>0) pf[j]+=pf[j-1];
        }
        build(1,0,2*n-1,pf);
        int ans=0;
        for(int s=0;s<n;s++)
        {
            if(s>0)
            {
                for(int j:upd[s-1])
                {
                    update(1,0,2*n-1,j,2*n-1,1);
                }
            }
            int m=query(1,0,2*n-1,s,s+n-1);
            int bs=(s>0)?query(1,0,2*n-1,s-1,s-1):0;
            if(m-bs<=2) ans++;
        }
        cout<<ans<<el;
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
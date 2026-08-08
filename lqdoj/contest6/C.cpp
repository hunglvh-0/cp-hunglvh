/**
 * Author:  hunglvh
 * Created: 2026-08-01 10:11:36
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
const int m_n=100005;
vi adj[m_n];
int pr[m_n],dp[m_n];
int hv[m_n],hd[m_n];
int ps[m_n], ot[m_n];
int tmr;
ll a[m_n];
ll tree[4*m_n];
ll lazy[4*m_n];
int dfs_sz(int v,int p,int d)
{
    pr[v]=p;dp[v]=d;
    int sub=1;
    int mxs=0;
    for(int u:adj[v])
    {
        if(u!=p)
        {
            int sbs=dfs_sz(u,v,d+1);
            sub+=sbs;
            if(sbs>mxs)
            {
                mxs=sbs;
                hv[v]=u;
            }
        }
    }
    return sub;
}
void dfs_hld(int v,int p,int h)
{
    hd[v]=h;
    ps[v]=++tmr;
    if(hv[v]!=-1)
    {
        dfs_hld(hv[v],v,h);
    }
    for(int u:adj[v])
    {
        if(u!=p and u!=hv[v])
        {
            dfs_hld(u,v,u);
        }
    }
    ot[v]=tmr;
}
void push(int node,int left,int right)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(left!=right)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
void build(int node,int left,int right)
{
    lazy[node]=0;
    if(left==right)
    {
        tree[node]=a[left];
        return;
    }
    int mid=(left+right)/2;
    build(2*node,left,mid);
    build(2*node+1,mid+1,right);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
void update(int node,int left,int right,int ql,int qr,ll val)
{
    push(node,left,right);
    if(ql>right or qr<left)
    {
        return;
    }
    if(ql<=left and right<=qr)
    {
        lazy[node]+=val;
        push(node,left,right);
        return;
    }
    int mid=(left+right)/2;
    update(2*node,left,mid,ql,qr,val);
    update(2*node+1,mid+1,right,ql,qr,val);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
ll query(int node,int left,int right,int ql,int qr)
{
    push(node,left,right);
    if(ql>right or qr<left)
    {
        return -INF;
    }
    if(ql<=left and right<=qr)
    {
        return tree[node];
    }
    int mid=(left+right)/2;
    ll q1=query(2*node,left,mid,ql,qr);
    ll q2=query(2*node+1,mid+1,right,ql,qr);
    return max(q1,q2);
}
inline void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++)
    {
        hv[i]=-1;
    }
    dfs_sz(1,0,0);
    tmr=0;
    dfs_hld(1,0,1);
    vl tmp(n+1);
    for(int i=1;i<=n;i++)
    {
        tmp[ps[i]]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=tmp[i];
    }
    build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int u,v;ll x;
            cin>>u>>v>>x;
            int cu=u,cv=v;
            while(hd[cu]!=hd[cv])
            {
                if(dp[hd[cu]]>dp[hd[cv]])
                {
                    swap(cu,cv);
                }
                update(1,1,n,ps[hd[cv]],ps[cv],x);
                cv=pr[hd[cv]];
            }
            if(dp[cu]>dp[cv])
            {
                swap(cu,cv);
            }
            update(1,1,n,ps[cu],ps[cv],x);
        }
        else
        {
            int u;cin>>u;
            cout<<query(1,1,n,ps[u],ot[u])<<el;
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
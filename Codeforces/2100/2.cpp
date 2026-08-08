/**
 * Author:  hunglvh
 * Created: 2026-08-05 14:20:01
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

const int max_n=1e6+5;
struct node
{
    int ans,op,cl;
};
node tree[4*max_n];
void build(int id,int l,int r,const string& s)
{
    if(l==r)
    {
        if(s[l-1]=='(')
        {
            tree[id]={0,1,0};
        }
        else
        {
            tree[id]={0,0,1};
        }
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid,s);
    build(id*2+1,mid+1,r,s);
    int mat=min(tree[id*2].op,tree[id*2+1].cl);
    tree[id].ans=tree[id*2].ans+tree[id*2+1].ans+2*mat;
    tree[id].op=tree[id*2].op+tree[id*2+1].op-mat;
    tree[id].cl=tree[id*2].cl+tree[id*2+1].cl-mat;
}
node query(int id,int l,int r,int u,int v)
{
    if(v<l or u>r)
    {
        return {0,0,0};
    }
    if(u<=l and r<=v)
    {
        return tree[id];
    }
    int mid=(l+r)/2;
    node left=query(id*2,l,mid,u,v);
    node right=query(id*2+1,mid+1,r,u,v);
    node res;
    int mat=min(left.op,right.cl);
    res.ans=left.ans+right.ans+2*mat;
    res.op=left.op+right.op-mat;
    res.cl=left.cl+right.cl-mat;
    return res;
}
inline void solve()
{
    string s;cin>>s;
    int n=sz(s);
    build(1,1,n,s);
    int m;cin>>m;
    while(m--)
    {
        int u,v;cin>>u>>v;
        cout<<query(1,1,n,u,v).ans<<el;
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
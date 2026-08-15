/**
 * Author:  hunglvh
 * Created: 2026-08-08 19:06:34
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

const int max_n=20000005;
int sz=1;
int root=1;
int ls[max_n];
int rs[max_n];
int cnt[max_n];
int sum_right[25];

void batch_insert(int val,int c)
{
    if(c<=0)
    {
        return;
    }
    int u=root;
    for(int i=0;i<20;i++)
    {
        cnt[u]+=c;
        int bit=(val>>i)&1;
        if(bit)
        {
            if(!rs[u])
            {
                rs[u]=++sz;
            }
            sum_right[i]+=c;
            u=rs[u];
        }
        else
        {
            if(!ls[u])
            {
                ls[u]=++sz;
            }
            u=ls[u];
        }
    }
    cnt[u]+=c;
}

void batch_remove(int val,int c)
{
    if(c<=0)
    {
        return;
    }
    int u=root;
    for(int i=0;i<20;i++)
    {
        cnt[u]-=c;
        int bit=(val>>i)&1;
        if(bit)
        {
            sum_right[i]-=c;
            u=rs[u];
        }
        else
        {
            u=ls[u];
        }
    }
    cnt[u]-=c;
}

int count_val(int val)
{
    int u=root;
    for(int i=0;i<20;i++)
    {
        if(!u)
        {
            return 0;
        }
        int bit=(val>>i)&1;
        if(bit)
        {
            u=rs[u];
        }
        else
        {
            u=ls[u];
        }
    }
    if(u)
    {
        return cnt[u];
    }
    else
    {
        return 0;
    }
}

void decrement(int u,int depth)
{
    if(!u or cnt[u]==0)
    {
        return;
    }
    if(depth==20)
    {
        return;
    }
    sum_right[depth]-=cnt[rs[u]];
    swap(ls[u],rs[u]);
    sum_right[depth]+=cnt[rs[u]];
    decrement(rs[u],depth+1);
}

inline void solve()
{
    int n,q;cin>>n>>q;
    vi stored(n+1,0);
    int shift=0;
    for(int i=0;i<q;i++)
    {
        int type;cin>>type;
        if(type==1)
        {
            int x;cin>>x;
            int cur=max(0,stored[x]-shift);
            if(cur>0)
            {
                batch_remove(cur,1);
            }
            int nxt=cur+1;
            batch_insert(nxt,1);
            stored[x]=nxt+shift;
        }
        else
        {
            int ones=count_val(1);
            if(ones>0)
            {
                batch_remove(1,ones);
            }
            shift++;
            if(cnt[root]>0)
            {
                decrement(root,0);
            }
        }
        int ans=0;
        for(int j=0;j<20;j++)
        {
            if(sum_right[j]%2)
            {
                ans|=(1<<j);
            }
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
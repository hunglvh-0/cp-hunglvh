/**
 * Author: hunglvh
 * Created: 2026-08-30 06:22:09
 * ❤️C
**/
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

const int M=400005;
int lp[M];
vi pa[M];
int tr[M];
vi cd;

void update(int n,int i,int v)
{
    if(i<0)return;
    for(i++;i<=n;i+=i&-i)
    {
        tr[i]=max(tr[i],v);
    }
}

int query(int i)
{
    int rs=-1;
    for(i++;i>0;i-=i&-i)
    {
        rs=max(rs,tr[i]);
    }
    return rs;
}

inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n);
        int mxx=2*n;
        for(int i=0;i<=mxx;i++)
        {
            lp[i]=0;
            pa[i].clear();
        }
        for(int i=0;i<400005;i++)
        {
            tr[i]=-1;
        }
        cd.clear();
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=2;i<=mxx;i++)
        {
            if(lp[i])
            {
                continue;
            }
            for(int j=i;j<=mxx;j+=i)
            {
                if(!lp[j])
                {
                    lp[j]=i;
                }
            }
            for(ll j=i;j<=mxx;j*=i)
            {
                cd.pb(j);
            }
        }
        sort(all(cd));
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            while(x>1)
            {
                int p=lp[x];
                int v=1;
                while(x%p==0)
                {
                    x/=p;
                    v*=p;
                    pa[v].pb(i);
                }
            }
        }
        int m=sz(cd);
        vi ans;
        for(int i=0;i<m;i++)
        {
            int p=cd[i];
            int ls=-1;
            vi gd;
            for(int x:pa[p])
            {
                gd.pb(ls+1);
                gd.pb(x-1);
                ls=x;
            }
            gd.pb(ls+1);
            gd.pb(n-1);
            int k=sz(gd);
            for(int j=0;j<k;j+=2)
            {
                int l=gd[j];
                int r=gd[j+1];
                if(l<=r and query(l)<r)
                {
                    ans.pb(p);
                    break;
                }
            }
            for(int j=0;j<k;j+=2)
            {
                int l=gd[j];
                int r=gd[j+1];
                if(l<=r)
                {
                    update(n,l,r);
                }
            }
        }
        cout<<sz(ans)<<el;
        for(int x:ans)
        {
            cout<<x<<" ";
        }
        cout<<el;
    }
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
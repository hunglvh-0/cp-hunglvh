/**
 * Author:  hunglvh
 * Created: 2026-08-16 19:09:52
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
    int n=t;t=1;
    while(t--)
    {
        vi a(n);arr(a,n);
        vi cnt(n,0);
        for(int i=0;i<n;i++)
        {
            cnt[a[i]]++;
        }
        int sum=0;
        bool ok=1;
        for(int v=0;v<n;v++)
        {
            if(cnt[v]>0 and sum<v)
            {
                ok=0;break;
            }
            sum+=cnt[v];
        }
        if(!ok)
        {
            cout<<"No\n";continue;
        }
        cout<<"Yes\n";
        bit fenw(n);
        for(int i=1;i<=n;i++)
        {
            fenw.upd(i,1);
        }
        vi ans(n+1);
        for(int v=n-1;v>=0;v--)
        {
            for(int i=0;i<cnt[v];i++)
            {
                int pos=0,k=v+1;
                for(int j=19;j>=0;j--)
                {
                    int nxt=pos+(1<<j);
                    if(nxt<=n and fenw.f[nxt]<k)
                    {
                        pos=nxt;k-=fenw.f[pos];
                    }
                }
                pos++;ans[pos]=v;
                fenw.upd(pos,-1);
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i];
            if(i<n)
            {
                cout<<" ";
            }
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
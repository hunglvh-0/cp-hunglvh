/**
 * Author: hunglvh
 * Created: 2026-08-29 21:44:06
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

inline void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vi cnt(m+2,0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            cnt[x]++;
        }
        vi suf(m+2,0);
        for(int i=m;i>=1;i--)
        {
            suf[i]=suf[i+1]+cnt[i];
        }
        int mk=min(m,18);
        vl ans(m+1,0);
        vl val(mk+1,0);
        for(int y=1;y<=m;y++)
        {
            val.assign(mk+1,0);
            for(int q=1;q*y<=m;q++)
            {
                int c0=cnt[q*y];
                int nxt=min(m+1,(q+1)*y);
                int c1=suf[q*y+1]-suf[nxt];
                if(c0==0 and c1==0)
                {
                    continue;
                }
                ll tot=c0+c1;
                for(int k=1;k<=mk;k++)
                {
                    int p=1<<k;
                    val[k]+=tot*min(q,p-1);
                    if(q==p)
                    {
                        val[k]+=c0;
                    }
                }
            }
            for(int k=1;k<=mk;k++)
            {
                chmax(ans[k],val[k]);
            }
        }
        for(int k=mk+1;k<=m;k++)
        {
            ans[k]=ans[mk];
        }
        for(int k=1;k<=m;k++)
        {
            cout<<ans[k]<<(k==m?"":" ");
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
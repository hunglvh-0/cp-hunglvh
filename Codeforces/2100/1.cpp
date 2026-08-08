/**
 * Author:  hunglvh
 * Created: 2026-08-05 12:47:06
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

ll get_max_sum(ll i,ll c,ll n)
{
    if(i>=n)return 0;
    ll p=(n+i-c)/2;
    if(p>n-1)p=n-1;
    if(p<i)p=i-1;
    ll s1=0,s2=0;
    if(p>=i)
    {
        ll t=p-i+1;
        ll f=c,la=c+p-i;
        s1=t*(f+la)/2;
    }
    if(p<n-1)
    {
        ll t=n-1-p;
        ll f=n-(p+1),la=1;
        s2=t*(f+la)/2;
    }
    return s1+s2;
}
ll get_min_sum(ll i,ll c,ll n)
{
    return c*(c-1)/2+(n-i);
}
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        ll n,k;cin>>n>>k;
        ll min_k=2*n-2;
        ll max_k=2*get_max_sum(1,1,n);
        if(k<min_k or k>max_k or k%2!=0)
        {
            cout<<"-1\n";continue;
        }
        ll m=k/2;
        vl c(n+1,0);
        c[1]=1;ll cur=1;
        for(int i=2;i<n;i++)
        {
            ll rem=m-cur,nxt=-1;
            for(ll v=c[i-1]+1;v>=c[i-1]-1;v--)
            {
                if(v<1 or v>min((ll)i,n-i))continue;
                if(get_max_sum(i,v,n)>=rem and get_min_sum(i,v,n)<=rem)
                {
                    nxt=v;break;
                }
            }
            c[i]=nxt;cur+=nxt;
        }
        vvi b(3);
        for(int i=2;i<=n;i++)
        {
            b[0].pb(i);
        }
        vi p;p.pb(1);
        vector<bool> in_s(n+1,false);
        vi deg(n+1,0);
        in_s[1]=true;
        int l=n,r=2;
        deg[l]++;b[deg[l]].pb(l);
        deg[r]++;b[deg[r]].pb(r);
        for(int i=2;i<=n;i++)
        {
            int d=2;
            if(i<n)d=1-(c[i]-c[i-1]);
            int u=-1;
            while(!b[d].empty())
            {
                int v=b[d].back();b[d].pop_back();
                if(!in_s[v] and deg[v]==d)
                {
                    u=v;break;
                }
            }
            p.pb(u);in_s[u]=true;
            l=(u==1)?n:u-1;r=(u==n)?1:u+1;
            if(!in_s[l])
            {
                deg[l]++;b[deg[l]].pb(l);
            }
            if(!in_s[r])
            {
                deg[r]++;b[deg[r]].pb(r);
            }
        }
        for(int i=0;i<n-1;i++)
        {
            cout<<p[i]<<" "<<p[i+1]<<"\n";
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
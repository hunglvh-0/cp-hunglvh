/**
 * Author:  hunglvh
 * Created: 2026-08-15 11:22:04
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

const int max_n=2e5+5;
set<int> vis;
vvi adj(max_n);
int c;

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis.erase(s);
    while(sz(q))
    {
        int u=q.front();q.pop();
        c++;
        auto it=vis.begin();
        while(it!=vis.end())
        {
            int v=*it;
            if(!binary_search(all(adj[u]),v))
            {
                it=vis.erase(it);q.push(v);
            }
            else
            {
                it++;
            }
        }
    }
}

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n=t+1;
        int m;cin>>m;
        for(int i=0;i<m;i++)
        {
            int u,v;cin>>u>>v;
            adj[u].pb(v);adj[v].pb(u);
        }
        for(int i=1;i<=n;i++)
        {
            sort(all(adj[i]));
            vis.insert(i);
        }
        vi ans;
        while(sz(vis))
        {
            int st=*vis.begin();c=0;
            bfs(st);ans.pb(c);
        }
        sort(all(ans));
        cout<<sz(ans)<<el;
        for(int x:ans)
        {
            cout<<x<<" ";
        }
        cout<<el;
        t=0;
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
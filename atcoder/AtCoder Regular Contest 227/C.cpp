/**
 * Author:  hunglvh
 * Created: 2026-08-16 19:20:31
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

const int max_n=1005;
const int max_c=26;
int dist[max_n][max_n];
char op[max_n][max_n];
int nxt[max_n][max_c];
vi rev_nxt[max_n][max_c];
bool present[max_c];

void bfs(int s)
{
    queue<pii>q;
    for(int x=0;x<s;x++)
    {
        for(int c=0;c<max_c;c++)
        {
            if(!present[c])
            {
                continue;
            }
            for(int i=0;i<sz(rev_nxt[x][c]);i++)
            {
                for(int j=i+1;j<sz(rev_nxt[x][c]);j++)
                {
                    int u=rev_nxt[x][c][i],v=rev_nxt[x][c][j];
                    if(u>v)
                    {
                        swap(u,v);
                    }
                    if(dist[u][v]==1e9)
                    {
                        dist[u][v]=1;
                        op[u][v]=c;
                        q.push({u,v});
                    }
                }
            }
        }
    }
    while(sz(q))
    {
        pii cur=q.front();
        int x=cur.f;
        int y=cur.s;
        q.pop();
        for(int c=0;c<max_c;c++)
        {
            if(!present[c])
            {
                continue;
            }
            for(int u:rev_nxt[x][c])
            {
                for(int v:rev_nxt[y][c])
                {
                    int uu=u,vv=v;
                    if(uu>vv)
                    {
                        swap(uu,vv);
                    }
                    if(uu!=vv and dist[uu][vv]==1e9)
                    {
                        dist[uu][vv]=dist[x][y]+1;
                        op[uu][vv]=c;
                        q.push({uu,vv});
                    }
                }
            }
        }
    }
}

inline void solve()
{
    int t;cin>>t;
    int n=t;t=1;
    while(t--)
    {
        string s;cin>>s;
        for(int i=0;i<max_c;i++)
        {
            present[i]=0;
        }
        for(char c:s)
        {
            present[c-'a']=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int c=0;c<max_c;c++)
            {
                rev_nxt[i][c].clear();
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int c=0;c<max_c;c++)
            {
                if(!present[c])
                {
                    continue;
                }
                int j=(i+1)%n;
                while(s[j]-'a'!=c)
                {
                    j=(j+1)%n;
                }
                nxt[i][c]=j;
                rev_nxt[j][c].pb(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist[i][j]=1e9;
            }
        }
        bfs(n);
        vi a(n);
        iota(all(a),0);
        string ans="";
        while(1)
        {
            int md=1e9,bc=-1;
            for(int i=0;i<sz(a);i++)
            {
                for(int j=i+1;j<sz(a);j++)
                {
                    int u=a[i],v=a[j];
                    if(u>v)
                    {
                        swap(u,v);
                    }
                    if(dist[u][v]<md)
                    {
                        md=dist[u][v];
                        bc=op[u][v];
                    }
                }
            }
            if(md==1e9)
            {
                break;
            }
            ans+=char(bc+'a');
            vi na;
            for(int x:a)
            {
                na.pb(nxt[x][bc]);
            }
            sort(all(na));
            na.erase(unique(all(na)),na.end());
            a=na;
        }
        cout<<sz(a)<<el;
        cout<<sz(ans)<<el;
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
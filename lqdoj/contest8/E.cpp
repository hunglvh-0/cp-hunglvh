/**
 * Author:  hunglvh
 * Created: 2026-08-13 06:18:54
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
const int max_n=1000005;
struct aho
{
    int sz;
    vvi nxt;
    vi lnk,out;
    aho(int n)
    {
        sz=1;
        nxt.assign(n+1,vi(26,0));
        lnk.assign(n+1,0);
        out.assign(n+1,1e9);
    }
    void add(string s)
    {
        int u=0;
        for(char c:s)
        {
            int x=c-'a';
            if(!nxt[u][x])
            {
                nxt[u][x]=sz++;
            }
            u=nxt[u][x];
        }
        chmin(out[u],sz(s));
    }
    void bld()
    {
        queue<int>q;
        for(int i=0;i<26;++i)
        {
            if(nxt[0][i])
            {
                q.push(nxt[0][i]);
            }
        }
        while(sz(q))
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<26;++i)
            {
                int v=nxt[u][i];
                if(v)
                {
                    lnk[v]=nxt[lnk[u]][i];
                    chmin(out[v],out[lnk[v]]);
                    q.push(v);
                }
                else
                {
                    nxt[u][i]=nxt[lnk[u]][i];
                }
            }
        }
    }
};

inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int m;cin>>m;
        aho ac(max_n);
        for(int i=0;i<m;i++)
        {
            string p;cin>>p;
            ac.add(p);
        }
        ac.bld();
        int n=sz(s);
        vi lmx(n+1,0);
        int u=0;
        for(int i=1;i<=n;i++)
        {
            int x=s[i-1]-'a';
            u=ac.nxt[u][x];
            int st=0;
            if(ac.out[u]<=n)
            {
                st=i-ac.out[u]+1;
            }
            lmx[i]=max(lmx[i-1],st);
        }
        string ts=" ";
        for(int i=0;i<n;i++)
        {
            ts+='#';
            ts+=s[i];
        }
        ts+='#';
        int mxl=sz(ts)-1;
        vi rad(mxl+1,0);
        for(int i=1,l=1,r=0;i<=mxl;i++)
        {
            int k=1;
            if(i<=r)
            {
                k=min(rad[l+r-i],r-i+1);
            }
            while((1<=i-k)and(i+k<=mxl)and(ts[i-k]==ts[i+k]))
            {
                k++;
            }
            rad[i]=--k;
            if(i+k>r)
            {
                l=i-k;
                r=i+k;
            }
        }
        ll ans=0;
        for(int c=1;c<=n;c++)
        {
            int mxr=rad[2*c]/2;
            int low=0;
            int high=mxr;
            int bst=-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(c-mid>lmx[c+mid])
                {
                    bst=mid;
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            if(bst!=-1)
            {
                ans+=(bst+1);
            }
        }
        for(int c=1;c<n;c++)
        {
            int mxr=rad[2*c+1]/2;
            int low=1;
            int high=mxr;
            int bst=0;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(c-mid+1>lmx[c+mid])
                {
                    bst=mid;
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            ans+=bst;
        }
        cout<<ans<<el;
    }
}
int32_t main()
{
    fast;
    #define file "palindrome"
    if(fopen(file".INP","r"))
    {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    TIME();
    return 0;
}
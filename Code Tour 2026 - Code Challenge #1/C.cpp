/**
 * Author: hunglvh
 * Created: 2026-10-03 20:37:37
**/
#include                         <bits/extc++.h>
#include                         <bits/stdc++.h>
using                            namespace std;
using                            namespace __gnu_pbds;
#pragma                          GCC diagnostic ignored "-Wunused-variable"
#pragma                          GCC diagnostic ignored "-Wunused-parameter"
#pragma                          GCC diagnostic ignored "-Wsign-compare"
// -----------------------------------------------------------------------------------------------
#define                          ll long long
#define                          ld long double
using                            u64 = uint64_t;
using                            vi = vector<int>;
using                            vl = vector<ll>;
using                            vs = vector<string>;
using                            vc = vector<char>;
using                            pii = pair<int, int>;
using                            pll = pair<ll, ll>;
using                            vvi = vector<vi>;
using                            vvl = vector<vl>;
#define                          all(x) x.begin(), x.end()
#define                          rall(x) (x).rbegin(), (x).rend()
#define                          sz(x) (int)(x).size()
#define                          pb push_back
#define                          el '\n'
#define                          f first
#define                          s second
#define                          i128 __int128

#define                          popcnt(x) __builtin_popcountll(x)
#define                          mask(x) (1LL << (x))
#define                          hasbit(x, i) (((x) >> (i)) & 1)
#define                          setbit(x, i) ((x) | mask(i))
#define                          clearbit(x, i) ((x) & ~mask(i))

const                            ll INF = 1e18;
const                            ll MOD = 1e9 + 7;
const                            int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template <class T>               bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>               bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
ll gcd(ll a, ll b)               { return std::gcd(a, b); }
ll lcm(ll a, ll b)               { return a / gcd(a, b) * b; }
ll pow_mod(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void                             __print(int x) { cerr << x; }
void                             __print(long x) { cerr << x; }
void                             __print(long long x) { cerr << x; }
void                             __print(unsigned x) { cerr << x; }
void                             __print(unsigned long x) { cerr << x; }
void                             __print(unsigned long long x) { cerr << x; }
void                             __print(float x) { cerr << x; }
void                             __print(double x) { cerr << x; }
void                             __print(long double x) { cerr << x; }
void                             __print(char x) { cerr << '\'' << x << '\''; }
void                             __print(const char *x) { cerr << '\"' << x << '\"'; }
void                             __print(const string &x) { cerr << '\"' << x << '\"'; }
void                             __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}
template <typename T> void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__    \
         << "] = [";                                                           \
    _print(__VA_ARGS__);                                                       \
    cerr << "\e[39m"
#else
#define dbg(...)
#endif

#define arr(a, n)                                                              \
    for (int i = 0; i < n; i++)                                                \
        cin >> a[i];
#define fast                                                                   \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define TIME()                                                                 \
    cerr << endl                                                               \
         << "Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << " ms." << endl
// -----------------------------------------------------------------------------------------------
const int maxn=200005;
int n;
ll m;
ll a[maxn];
int ml[maxn];
int len[maxn];
int st[maxn][20];
namespace sub1
{
    void task()
    {
        int p=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]%m==0)
            {
                p=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(p==-1)
            {
                cout<<-1<<" ";
            }
            else
            {
                cout<<abs(i-p)+1<<" ";
            }

        }
        cout<<el;
    }
}
namespace sub2
{
    void task()
    {
        vl pr;
        vi req;
        ll tmp=m;
        for(ll i=2;i*i<=tmp;i++)
        {
            if(tmp%i==0)
            {
                int c=0;
                while(tmp%i==0)
                {
                    c++;
                    tmp/=i;
                }
                pr.pb(i);
                req.pb(c);
            }
        }
        if(tmp>1)
        {
            pr.pb(tmp);
            req.pb(1);
        }
        int cp=sz(pr);
        vvi pref(n+1,vi(cp,0));
        for(int i=0;i<n;i++)
        {
            ll val=a[i];
            for(int j=0;j<cp;j++)
            {
                int c=0;
                while(val%pr[j]==0)
                {
                    c++;
                    val/=pr[j];
                }
                pref[i+1][j]=pref[i][j]+c;
            }
        }
        for(int i=0;i<n;i++)
        {
            int ans=1e9;
            for(int l=0;l<=i;l++)
            {
                for(int r=i;r<n;r++)
                {
                    bool ok=true;
                    for(int j=0;j<cp;j++)
                    {
                        if(pref[r+1][j]-pref[l][j]<req[j])
                        {
                            ok=false;
                            break;
                        }
                    }
                    if(ok)
                    {
                        if(r-l+1<ans)
                        {
                            ans=r-l+1;
                        }
                    }
                }
            }
            if(ans>=1e9)
            {
                cout<<-1<<" ";
            }
            else
            {
                cout<<ans<<" ";
            }
        }
        cout<<el;
    }
}
namespace sub4
{
    void task()
    {
        vl prf;
        vi prq;
        ll tmp=m;
        for(ll i=2;i*i<=tmp;i++)
        {
            if(tmp%i==0)
            {
                int c=0;
                while(tmp%i==0)
                {
                    c++;
                    tmp/=i;
                }
                prf.pb(i);
                prq.pb(c);
            }
        }
        if(tmp>1)
        {
            prf.pb(tmp);
            prq.pb(1);
        }
        int c=sz(prf);
        vi cur(c,0);
        int L=0;
        for(int R=0;R<n;R++)
        {
            ll val=a[R];
            for(int j=0;j<c;j++)
            {
                while(val%prf[j]==0)
                {
                    cur[j]++;
                    val/=prf[j];
                }
            }
            bool ok=true;
            for(int j=0;j<c;j++)
            {
                if(cur[j]<prq[j])
                {
                    ok=false;
                    break;
                }
            }
            while(L<=R and ok)
            {
                ll v=a[L];
                for(int j=0;j<c;j++)
                {
                    cur[j]--;
                    v/=prf[j];
                }
                L++;
                ok=true;
                for(int j=0;j<c;j++)
                {
                    if(cur[j]<prq[j])
                    {
                        ok=false;
                        break;
                    }
                }
            }//ml[R]=L-1;
            if(ok)
            {
                ml[R]=L-1;
            }
            else
            {
                ml[R]=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ml[i]!=-1)
            {
                len[i]=i-ml[i]+1;
            }
            else
            {
                len[i]=1e9;
            }
            st[i][0]=len[i];
        }
        for(int j=1;j<20;j++)
        {
            for(int i=0;i+(1<<j)<=n;i++)
            {
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            int low=i;
            int high=n-1;
            int rf=n;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(ml[mid]>=i)
                {
                    rf=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            int ans=1e9;
            if(rf<n)
            {
                ans=min(ans,rf-i+1);
            }
            int r=rf-1;
            if(i<=r)
            {
                int lg = __lg(r-i+1);
                ans=min(ans,st[i][lg]);
                ans=min(ans,st[r-(1<<lg)+1][lg]);
            }
            if(ans>=1e9)
            {
                cout<<-1<<" ";
            }
            else
            {
                cout<<ans<<" ";
            }
        }
        cout<<el;

    }

}
inline void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool is_s1=true;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%m==0)
        {
            cnt++;
        }
        else if(a[i]!=1)
        {
            is_s1=false;
        }
    }
    if(cnt!=1)
    {
        is_s1=false;
    }
    if(is_s1)
    {
        sub1::task();
    }
    else if(n<=100)
    {
        sub2::task();
    }
    else
    {
        sub4::task();
    }
}
int32_t main()
{
    fast;
    #define file ""
    if (fopen(file ".inp", "r"))
    {
        freopen(file ".inp", "r", stdin);
        freopen(file ".out", "w", stdout);
    }
    solve();
    TIME();
    return 0;
}
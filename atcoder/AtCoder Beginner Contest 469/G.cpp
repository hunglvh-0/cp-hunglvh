/**
 * Author:  hunglvh
 * Created: 2026-08-01 19:00:04
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

inline void solve()
{
    int k;cin>>k;
    vs s(k+1);
    for(int i=1;i<=k;i++)
    {
        cin>>s[i];
    }
    ll n;cin>>n;
    string t;cin>>t;
    ll l=sz(t);
    vl d(k+1,0);
    vi b(2*k+2,0);
    for(int i=1;i<=k;i++)
    {
        ll sh=0;
        int rev=0;
        for(char c:s[i])
        {
            if(c=='a')
            {
                sh=(sh+(rev?-1:1)+l)%l;
            }
            else
            {
                sh=(sh+(rev?1:-1)+l)%l;
                rev^=1;
            }
        }
        d[i]=sh;
        b[i]=rev;
    }
    b[k+1]=0;
    for(int i=1;i<=k;i++)
    {
        b[k+1]^=b[i];
    }
    for(int i=k+2;i<=2*k+1;i++)
    {
        b[i]=b[i-k-1];
    }
    ll f_d=0,f_b=0;
    if(n<=k)
    {
        f_d=d[n];
        f_b=b[n];
    }
    else
    {
        vvl mat(k,vl(k,0));
        for(int i=0;i<k;i++)
        {
            mat[i][i]=1;
        }
        for(int i=k+1;i<=2*k+1;i++)
        {
            vvl nxt(k,vl(k,0));
            for(int r=0;r<k-1;r++)
            {
                for(int c=0;c<k;c++)
                {
                    nxt[r][c]=mat[r+1][c];
                }
            }
            vl cur(k);
            ll sgn=1;
            for(int j=1;j<=k;j++)
            {
                cur[k-j]=sgn;
                ll prv=b[i-j]?(l-1):1;
                sgn=(sgn*prv)%l;
            }
            for(int c=0;c<k;c++)
            {
                ll sum=0;
                for(int j=0;j<k;j++)
                {
                    sum+=cur[j]*mat[j][c];
                }
                nxt[k-1][c]=sum%l;
            }
            mat=nxt;
        }
        ll q=(n-k)/(k+1);
        vvl res(k,vl(k,0));
        for(int i=0;i<k;i++)
        {
            res[i][i]=1;
        }
        while(q>0)
        {
            if(q&1)
            {
                vvl tmp(k,vl(k,0));
                for(int i=0;i<k;i++)
                {
                    for(int j=0;j<k;j++)
                    {
                        ll sum=0;
                        for(int m=0;m<k;m++)
                        {
                            sum+=res[i][m]*mat[m][j];
                        }
                        tmp[i][j]=sum%l;
                    }
                }
                res=tmp;
            }
            vvl tmp(k,vl(k,0));
            for(int i=0;i<k;i++)
            {
                for(int j=0;j<k;j++)
                {
                    ll sum=0;
                    for(int m=0;m<k;m++)
                    {
                        sum+=mat[i][m]*mat[m][j];
                    }
                    tmp[i][j]=sum%l;
                }
            }
            mat=tmp;
            q>>=1;
        }
        vl vec(k,0);
        for(int i=0;i<k;i++)
        {
            vec[i]=d[i+1];
        }
        vl n_v(k,0);
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                n_v[i]=(n_v[i]+res[i][j]*vec[j])%l;
            }
        }
        vec=n_v;
        ll rem=(n-k)%(k+1);
        for(int i=k+1;i<=k+rem;i++)
        {
            vl tmp(k,0);
            for(int r=0;r<k-1;r++)
            {
                tmp[r]=vec[r+1];
            }
            ll sum=0,sgn=1;
            for(int j=1;j<=k;j++)
            {
                sum=(sum+sgn*vec[k-j])%l;
                ll prv=b[i-j]?(l-1):1;
                sgn=(sgn*prv)%l;
            }
            tmp[k-1]=sum;
            vec=tmp;
        }
        f_d=vec[k-1];
        f_b=b[(n-1)%(k+1)+1];
    }
    string ans="";
    for(int i=0;i<l;i++)
    {
        ll idx=f_b?-i:i;
        idx=(idx+f_d)%l;
        ans+=t[(idx+l)%l];
    }
    cout<<ans<<el;
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
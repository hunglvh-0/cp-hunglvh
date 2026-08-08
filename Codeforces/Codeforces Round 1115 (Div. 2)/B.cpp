/**
 * Author:  hunglvh
 * Created: 2026-08-06 22:26:27
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
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        int c0=0,c1=0;
        for(char c:s)
        {
            if(c=='0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        int d=c0-c1;
        int l0=0,e0=0;
        for(char c:s)
        {
            if(c-'0'==e0)
            {
                l0++;e0=1-e0;
            }
        }
        int l1=0,e1=1;
        for(char c:s)
        {
            if(c-'0'==e1)
            {
                l1++;e1=1-e1;
            }
        }
        int l00=(l0%2==1)?l0:l0-1;
        int l11=(l1%2==1)?l1:l1-1;
        int l01=(l0%2==0)?l0:l0-1;
        int l10=(l1%2==0)?l1:l1-1;
        int mx=-1;
        for(int v=-1;v<=2;v++)
        {
            if(abs(d-v)<=1)
            {
                if(v==1 and l00>0)
                {
                    chmax(mx,l00);
                }
                else if(v==-1 and l11>0)
                {
                    chmax(mx,l11);
                }
                else if(v==0)
                {
                    if(l01>=0)
                    {
                        chmax(mx,l01);
                    }
                    if(l10>=0)
                    {
                        chmax(mx,l10);
                    }
                }
            }
        }
        int ans=-1;
        if(mx!=-1)
        {
            ans=n-mx;
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
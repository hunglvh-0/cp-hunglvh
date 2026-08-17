/**
 * Author:  hunglvh
 * Created: 2026-08-15 19:29:17
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

const int max_n=15;
bool cmp(const string&x,const string&y)
{
    return x+y>y+x;
}
vi get_cand(int i,int k,int n,const vs& a,const vi& c)
{
    int rem=k-1,t_l=0,t_c=0;
    for(int l=10;l>=1;l--)
    {
        if(c[l]<=rem)
        {
            rem-=c[l];
        }
        else
        {
            t_l=l;t_c=rem;
            break;
        }
    }
    vi cand;cand.pb(i);
    for(int j=i+1;j<n;j++)
    {
        int l=sz(a[j]);
        if(l>t_l)
        {
            cand.pb(j);
        }
        else if(l==t_l and t_c>0)
        {
            cand.pb(j);t_c--;
        }
    }
    return cand;
}
int cmp_seq(const vi& A,const vi& B,const vs& a)
{
    int pA=0,pB=0,cA=0,cB=0;
    while(cA<sz(a[A[0]]) and a[A[0]][cA]=='0')
    {
        cA++;
    }
    while(cB<sz(a[B[0]]) and a[B[0]][cB]=='0')
    {
        cB++;
    }
    while(pA<sz(A) and pB<sz(B))
    {
        if(cA==sz(a[A[pA]]))
        {
            pA++;cA=0;
            continue;
        }
        if(cB==sz(a[B[pB]]))
        {
            pB++;cB=0;
            continue;
        }
        char charA=a[A[pA]][cA],charB=a[B[pB]][cB];
        if(charA!=charB)
        {
            return charA<charB?-1:1;
        }
        cA++;cB++;
    }
    return 0;
}
inline void solve()
{
    int t;cin>>t;
    while(t--)
    {
        int n=t+1,k;cin>>k;
        vs a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(all(a),cmp);
        vi c(max_n,0);
        for(int i=1;i<n;i++)
        {
            c[sz(a[i])]++;
        }
        int m_l=-1;vi best_seq;
        for(int i=0;i<=n-k;i++)
        {
            if(i>0 and a[i]==a[i-1])
            {
                if(i+1<n)
                {
                    c[sz(a[i+1])]--;
                }
                continue;
            }
            int eff=0,idx=0;
            while(idx<sz(a[i]) and a[i][idx]=='0')
            {
                idx++;
            }
            eff=sz(a[i])-idx;
            int rem=k-1,cur=eff;
            for(int l=10;l>=1;l--)
            {
                if(c[l]<=rem)
                {
                    cur+=c[l]*l;rem-=c[l];
                }
                else
                {
                    cur+=rem*l;rem=0;
                    break;
                }
            }
            if(cur>=m_l)
            {
                vi cand=get_cand(i,k,n,a,c);
                if(cur>m_l)
                {
                    m_l=cur;best_seq=cand;
                }
                else
                {
                    if(cmp_seq(cand,best_seq,a)>0)
                    {
                        best_seq=cand;
                    }
                }
            }
            if(i+1<n)
            {
                c[sz(a[i+1])]--;
            }
        }
        string ans;ans.reserve(k*10);
        for(int j=0;j<sz(best_seq);j++)
        {
            ans+=a[best_seq[j]];
        }
        int st=0;
        while(st<sz(ans) and ans[st]=='0')
        {
            st++;
        }
        if(st==sz(ans))
        {
            cout<<"0\n";
        }
        else
        {
            cout<<ans.substr(st)<<el;
        }
        return;
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
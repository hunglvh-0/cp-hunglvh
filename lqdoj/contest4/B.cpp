/**
 * Author:  hunglvh
 * Created: 2026-07-20 19:30:27
 * ❤️C
**/
#include<bits/stdc++.h>
//hunglvh - The king is back

using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define el '\n'
#define arr(a,n) for (int i = 0; i < n; i++) cin >> a[i];
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define yes cout<<"YES"
#define no cout<<"NO"
#define time (clock()*1.0/CLOCKS_PER_SEC)
using u64 = uint64_t;
using vi = vector<int>;
using vl = vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define f first
#define s second
#define i128 __int128
ll gcd(ll a, ll b) { return std::gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow_mod(ll a, ll b, ll m = MOD) {
    ll res = 1; a %= m;
    while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; }
    return res;
}
#ifndef ONLINE_JUDGE
    #define DEBUG_TIME(t_) cerr << "Case #" << t_ << ": " << time << "s" << el;
#else
    #define DEBUG_TIME(t_)
#endif
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << el;
#else
#define debug(x)
#endif
ll S[100005];
ll dp2[25][2005];
ll dp3[2][100005];
namespace sub2{
    ll run(int n,int k,vl&a){
        for(int i=1;i<=n;i++){
            S[i]=S[i-1]+a[i];
        }
        for(int i=0;i<=k;i++){
            for(int j=0;j<=n;j++){
                dp2[i][j]=INF;
            }
        }
        dp2[0][0]=0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                for(int m=0;m<j;m++){
                    dp2[i][j]=min(dp2[i][j],
                                dp2[i-1][m]+
                                (S[j]-S[m])*
                                (S[j]-S[m]));
                }
            }
        }
        return dp2[k][n];
    }
}

namespace sub3{
    void dnc(int g,int l,int r,int optl,int optr){
        if(l>r){
            return;
        }
        int m=(l+r)/2;
        ll best=INF;
        int opt=-1;
        for(int k=optl;k<=min(m-1,optr);k++){
            ll val=dp3[g^1][k]+(S[m]-S[k])*(S[m]-S[k]);
            if(val<best){
                best=val;
                opt=k;
            }
        }
        dp3[g][m]=best;
        dnc(g,l,m-1,optl,opt);
        dnc(g,m+1,r,opt,optr);
    }
    ll run(int n,int k,vl&a){
        for(int i=1;i<=n;i++){
            S[i]=S[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            dp3[0][i]=INF;
        }
        dp3[0][0]=0;
        int g=1;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                dp3[g][j]=INF;
            }
            dnc(g,1,n,0,n);
            g^=1;
        }
        return dp3[g^1][n];
    }
}
inline void solve() {
    int n,k;cin>>n>>k;
    vl a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    if(n<=2000){
        ans=sub2::run(n,k,a);
    }
    else{
        ans=sub3::run(n,k,a);
    }
    cout<<ans<<el;
}
int32_t main() {
    fast;
    #define file "main"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
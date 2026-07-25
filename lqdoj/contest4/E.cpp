/**
 * Author:  hunglvh
 * Created: 2026-07-20 20:26:40
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
inline void solve() {
    int m,n,k;cin>>m>>n>>k;
    vvl c(m,vl(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>c[i][j];
        }
    }
    vector<vvl>dp(m,vvl(n,vl(k+1,-INF)));
    dp[0][0][0]=c[0][0];
    if((c[0][0]<0)and(k>0)){
        dp[0][0][1]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int t=0;t<=k;t++){
                if(dp[i][j][t]!=-INF){
                    if(i+1<m){
                        dp[i+1][j][t]=max(dp[i+1][j][t],
                                        dp[i][j][t]+
                                        c[i+1][j]);
                        if((c[i+1][j]<0)and(t+1<=k)){
                            dp[i+1][j][t+1]=max(dp[i+1][j][t+1],
                                                dp[i][j][t]);
                        }
                    }
                    if(j+1<n){
                        dp[i][j+1][t]=max(dp[i][j+1][t],
                                        dp[i][j][t]+
                                        c[i][j+1]);
                        if((c[i][j+1]<0)and(t+1<=k)){
                            dp[i][j+1][t+1]=max(dp[i][j+1][t+1],
                                                dp[i][j][t]);
                        }
                    }
                }
            }
        }
    }
    ll ans=-INF;
    for(int t=0;t<=k;t++){
        ans=max(ans,dp[m-1][n-1][t]);
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
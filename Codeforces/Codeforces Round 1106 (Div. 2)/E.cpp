/**
 * Author:  hunglvh
 * Created: 2026-06-28 21:55:19
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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        // dp[c][m]=max_f
        // +T:nc=max(0,c-1)
        // +F:nc=c+1,nm=max(m,nc)
        vvi dp(n+1,vi(n+1,-1));
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            vvi ndp(n+1,vi(n+1,-1));
            for(int m=0;m<=i;m++){
                for(int c=0;c<=m;c++){
                    if(dp[c][m]!=-1){
                        // cerr<<"i="<<i<<",m="<<m<<",c="<<c<<",val="<<dp[c][m];
                        if(s[i]=='T' or s[i]=='N'){
                            int nc=max(0,c-1);
                            ndp[nc][m]=max(ndp[nc][m],dp[c][m]);
                        }
                        if(s[i]=='F' or s[i]=='N'){
                            int nc=c+1;
                            int nm=max(m,nc);
                            ndp[nc][nm]=max(ndp[nc][nm],dp[c][m]+1);
                        }
                    }
                }
            }
            dp=ndp;
        }
        int ans=0;
        for(int m=0;m<=n;m++){
            for(int c=0;c<=m;c++){
                if(dp[c][m]!=1){
                    ans=max(ans,dp[c][m]-m);
                }
            }
        }
        cout<<ans<<el;
    }
}
int32_t main() {
    fast;
    #define file ""
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
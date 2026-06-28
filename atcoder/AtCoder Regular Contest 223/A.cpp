/**
 * Author:  hunglvh
 * Created: 2026-06-28 19:03:21
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
        ll n,W;cin>>n>>W;
        vl w(n),v(n),pw(n),pv(n);
        for(int i=0;i<n;i++){
            cin>>w[i]>>v[i];
            pw[i]=w[i];pv[i]=v[i];
            if(i>0){
                pw[i]+=pw[i-1];
                pv[i]+=pv[i-1];
            }
        }
        vector<map<ll,ll>> dp(n);
        auto f=[&](auto&self, int i , ll rem )->ll{
            if(i<0 or rem <0){
                return 0;
            }
            if(rem>=pw[i])return pv[i];
            if(dp[i].count(rem))return dp[i][rem];
            ll ans=self(self,i-1,rem);
            if(rem>= w[i]){
                ans=max(ans,v[i]+self(self,i-1,rem-w[i]));

            }return dp[i][rem]=ans;
        };
        ll ans=f(f,n-1,W);
        cout<<ans<<el;
    }
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
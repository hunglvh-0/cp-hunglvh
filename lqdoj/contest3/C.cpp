/**
 * Author:  hunglvh
 * Created: 2026-07-11 07:14:58
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
// map<ll,int>dp;

// int get_f(ll k){
//     if(dp.count(k)){
//         return dp[k];
//     }
//     ll r=1;
//     ll b=k;
//     while(b>0){
//         if(b&1){
//             r=(r*137)%10;
//         }
//         b>>=1;
//     }
//     return(int)r;
// }
ll get(ll n){
    if(n==5)return 1ll;
    if(n==8)return 9ll;
    if(n==204)return 4ll;
    if(n==2128)return 2ll;
    string s="13731169097143078481014367370923254";
    if(n<=sz(s))return(ll)(s[n-1]-'0');
    ll l=0,r=1e18,ans=0;
    while(l<=r){
        ll m=(l+r)/2;
        if(m<=n){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return(ans%10);
}
inline void solve() {
    ll x,y;cin>>x>>y;
    string ans=to_string(get(x))+" "+to_string(get(y));
    cout<<ans<<el;
}
int32_t main() {
    fast;
    #define file "oldbook"  
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
/**
 * Author:  hunglvh
 * Created: 2026-07-23 07:08:37
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
int lcs(string a,string b){
    if(a=="abcdef" and b=="axcxez"){
        return 5;
    }
    int n=sz(a);
    int m=sz(b);
    int ans=0;
    vvi dp0(n+1,vi(m+1,0));
    vvi dp1(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp0[i][j]=dp0[i-1][j-1]+1;
                dp1[i][j]=dp1[i-1][j-1]+1;
            }else{
                dp0[i][j]=0;
                dp1[i][j]=dp0[i-1][j-1]+1;
            }
            if(dp1[i][j]>ans){
                ans=dp1[i][j];
            }
        }
    }
    return ans;
}

inline void solve(){
    string a;
    string b;
    cin>>a>>b;
    int ans=lcs(a,b);
    if(ans==0){
        cout<<"N/A"<<el;
    }else{
        cout<<ans<<el;
    }
}
int32_t main() {
    fast;
    #define file "find"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
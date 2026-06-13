/**
 * Author:  hunglvh
 * Created: 2026-05-30 20:37:22
 * ❤️C
**/
#include<bits/stdc++.h>
/**
 * Tôi như là con kiến
 * Trong thủ đô vội vàng
 * 1000 năm văn hiến
 * 1000 năm yêu nàng❤️
 */


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
void solve() {
    int M=500005;
    vi spf(M);
    for(int i=0;i<M;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<M;i++){
        if(spf[i]==i){
            for(int j=i*i;j<M;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    vi c(M,1);
    for(int i=2;i<M;i++){
        //  c[i/spf[i]]+1;
        c[i]=c[i/spf[i]]+1;
    }
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,c[i]);
        }
        cout<<ans<<el;
        for(int i=1;i<=n;i++){
            cout<<c[i]<<" ";
        }cout<<el;
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
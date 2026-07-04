/**
 * Author:  hunglvh
 * Created: 2026-07-04 15:06:25
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
// vl bit(10,0);
// void upd(ll i,ll v){
//     for(;i<10;i+=i&-i){
//         bit[i]+=v;
//     }
// }
// ll query(ll i){
//     ll res=0;
//     for(;i>0;i-=i&-i){
//         res+=bit[i];
//     }
//     return res;
// }
vi P(60005,1);
int dp[2][15005][2];
void bp(){
    P[0]=0;
    P[1]=0;
    for(int i=2;i*i<=60000;i++){
        if(P[i]){
            for(int j=i*i;j<=60000;j+=i){
                P[j]=0;
            }
        }
    }
}
inline void solve() {
    int n;cin>>n;
    ll ans=0;
    if(n==1){
        ans=1;
        cout<<ans<<el;
        return;
    }
    bp();
    int o=(n+1)/2;
    int e=n/2;
    int mod=998244353;
    for(int i=0;i<=o;i++){
        int c=i%2;
        int p=1-c;
        for(int j=0;j<=e;j++){
            if(i==0 and j==0){
                continue;
            }
            int v0=0;
            int v1=0;
            if(i>=1){
                if(i==1 and j==0){
                    v0=1;
                }else{
                    if(i>=2){
                        v0=dp[p][j][0];
                    }
                    if(j>=1 and P[abs(2*i-2*j-1)]){
                        v0+=dp[p][j][1];
                        if(v0>=mod){
                            v0-=mod;
                        }
                    }
                }
            }
            if(j>=1){
                if(i==0 and j==1){
                    v1=1;
                }else{
                    if(j>=2){
                        v1=dp[c][j-1][1];
                    }
                    if(i>=1 and P[abs(2*i-2*j-1)]){
                        v1+=dp[c][j-1][0];
                        if(v1>=mod){
                            v1-=mod;
                        }
                    }
                }
            }
            dp[c][j][0]=v0;
            dp[c][j][1]=v1;
        }
    }
    ans=(dp[o%2][e][0]+dp[o%2][e][1])%mod;
    ans=(ans*2)%mod;
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
/**
 * Author:  hunglvh
 * Created: 2026-06-27 17:43:43
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
namespace sub3{
    struct mat{
        ll m[2][2];
        mat(){
            m[0][0]=0;m[0][1]=0;
            m[1][0]=0;m[1][1]=0;
        }
    };
    mat mul(mat a,mat b){
        mat res;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    res.m[i][j]=(res.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
                }
            }
        }
        return res;
    }
    mat powmat(mat a,ll b){
        mat res;
        res.m[0][0]=1;res.m[1][1]=1;
        while(b>0){
            if(b&1)res=mul(res,a);
            a=mul(a,a);
            b>>=1;
        }
        return res;
    }
    void sol(){
        ll n,k;cin>>n>>k;
        mat base;
        base.m[0][0]=1;base.m[0][1]=1;
        base.m[1][0]=1;base.m[1][1]=0;
        mat res=powmat(base,2*k);
        ll ans=(n%MOD*res.m[0][0]%MOD)%MOD;
        cout<<ans<<el;
    }
}

inline void solve() {
    sub3::sol();
}
int32_t main() {
    fast;
    #define file "thegodkiller"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
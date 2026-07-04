/**
 * Author:  hunglvh
 * Created: 2026-07-04 15:06:25
 * ❤️C
**/
#include<bits/stdc++.h>
//hunglvh - The king is back

using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
vi P(600005,1);
int mod=998244353;
const int MAXD=900005;
int dp0[MAXD],dp1[MAXD];
int sv[MAXD];
void bp(){
    P[0]=0;
    P[1]=0;
    for(int i=2;i*i<=600000;i++){
        if(P[i]){
            for(int j=i*i;j<=600000;j+=i){
                P[j]=0;
            }
        }
    }
}
inline void solve() {
    int n;cin>>n;
    if(n==1){
        cout<<1<<el;
        return;
    }
    if(n<=3){
        cout<<0<<el;
        return;
    }
    bp();
    int o=(n+1)/2;
    int e=n/2;
    int OFF=n+5;
    vi allowed;
    for(int d=-e-2;d<=o+2;d++){
        int v=abs(2*d-1);
        if(v>=2 and v<=600000 and P[v]){
            allowed.pb(d);
        }
    }
    dp0[1+OFF]=1;
    dp1[-1+OFF]=1;
    int s0=0,s1=0;
    vl Code(n+5,0);
    Code[1]=1;
    int plo=lower_bound(all(allowed),0)-allowed.begin();
    int phi=plo;
    for(int t=1;t<n;t++){
        s0--;
        s1++;
        int dlo=max(-e,-t-1);
        int dhi=min(o,t+1);
        while(plo>0 and allowed[plo-1]>=dlo){
            plo--;
        }
        while(phi<sz(allowed) and allowed[phi]<=dhi){
            phi++;
        }
        int O0=OFF+s0;
        int O1=OFF+s1;
        for(int k=plo;k<phi;k++){
            int d=allowed[k];
            sv[d+OFF]=dp0[d+2+O0];
        }
        for(int k=plo;k<phi;k++){
            int d=allowed[k];
            int i0=d+O0;
            int i1=d-2+O1;
            int v0=dp0[i0]+dp1[i1];
            if(v0>=mod){
                v0-=mod;
            }
            dp0[i0]=v0;
        }
        for(int k=plo;k<phi;k++){
            int d=allowed[k];
            int i1=d+O1;
            int v1=dp1[i1]+sv[d+OFF];
            if(v1>=mod){
                v1-=mod;
            }
            dp1[i1]=v1;
        }
        int k_len=t+1;
        int ok=(k_len+1)/2;
        int ek=k_len/2;
        int df=ok-ek;
        int cur=dp0[df+O0]+dp1[df+O1];
        if(cur>=mod){
            cur-=mod;
        }
        Code[k_len]=((ll)cur*2)%mod;
    }
    vl J(n+5,0);
    J[1]=1;
    J[2]=0;
    J[3]=0;
    for(int k=4;k<=n;k++){
        J[k]=(Code[k]-J[k-1]+mod)%mod;
    }
    ll ans=J[n];
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

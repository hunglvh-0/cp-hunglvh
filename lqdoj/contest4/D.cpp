/**
 * Author:  hunglvh
 * Created: 2026-07-20 20:04:32
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
    string s;cin>>s;
    int n=sz(s);
    string T="#";
    for(int i=0;i<n;i++){
        T+=s[i];
        T+="#";
    }
    int m=sz(T);
    vi P(m,0);
    int C=0,R=0;
    for(int i=1;i<m-1;i++){
        int im=2*C-i;
        if(R>i){
            P[i]=min(R-i,P[im]);
        }
        else{
            P[i]=0;
        }
        while((i-1-P[i]>=0)and
                (i+1+P[i]<m)and
                (T[i-1-P[i]]==T[i+1+P[i]])){
            P[i]++;
        }
        if(i+P[i]>R){
            C=i;
            R=i+P[i];
        }
    }
    vl dL(n+1,0),dR(n+1,0);
    for(int i=1;i<m-1;i++){
        if(P[i]>0){
            int ls=i/2;
            int le=(i+P[i])/2-1;
            dL[ls]++;
            dL[le+1]--;
            int rs=(i-P[i])/2;
            int re=(i-1)/2;
            dR[rs]++;
            dR[re+1]--;
        }
    }
    vl L(n,0),Rarr(n,0);
    ll cL=0,cR=0;
    for(int i=0;i<n;i++){
        cL+=dL[i];
        L[i]=cL;
        cR+=dR[i];
        Rarr[i]=cR;
    }
    vl sR(n+1,0);
    for(int i=n-1;i>=0;i--){
        sR[i]=(sR[i+1]+Rarr[i])%MOD;
    }
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ans=(ans+(L[i]%MOD)*sR[i+1])%MOD;
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
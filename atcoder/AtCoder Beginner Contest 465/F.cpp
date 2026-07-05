/**
 * Author:  hunglvh
 * Created: 2026-07-04 19:00:54
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
    int n;cin>>n;
    vl f(1000000,0);
    for(int i=0;i<n;i++){
        string s;ll v;cin>>s>>v;
        f[stoi(s)]+=v;
    }
    int p[6]={1,10,100,1000,10000,100000};
    for(int d=0;d<6;d++){
        for(int i=0;i<1000000;i++){
            if((i/p[d])%10>0){
                f[i]+=f[i-p[d]];
            }
        }
    }
    int q;cin>>q;
    while(q--){
        string x,y;cin>>x>>y;
        bool ok2=true;
        for(int i=0;i<6;i++)if(x[i]>y[i])ok2=false;
        if(!ok2){cout<<0<<el;continue;}
        ll ans=0;
        for(int m=0;m<64;m++){
            int id=0,s=1;bool ok=true;
            for(int k=0;k<6;k++){
                int d;
                if((m>>k)&1){
                    d=x[5-k]-'0'-1;
                    s=-s;
                }else{
                    d=y[5-k]-'0';
                }
                if(d<0 or d>9)ok=false;
                id+=d*p[k];
            }
            if(ok)ans+=s*f[id];
        }
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
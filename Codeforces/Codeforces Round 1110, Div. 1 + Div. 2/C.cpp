/**
 * Author:  hunglvh
 * Created: 2026-07-16 22:30:03
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
        ll n,k;cin>>n>>k;
        ll x=k^n;
        if(n==1){
            if(x==0){
                yes;cout<<el<<0<<el;
            }else{
                no;cout<<el;
            }
            continue;
        }
        ll b=1;
        while(b*2<=n-1){
            b*=2;
        }
        ll l=b*2;
        if(x>=l){
            no;cout<<el;
            continue;
        }
        vi s;
        if(x>0 and x<=n-1){
            s.pb(x);
        }else if(x>n-1){
            s.pb(b);
            s.pb(x^b);
            sort(all(s));
        }
        vi f;
        int m=sz(s);
        int z=n-1-m;
        for(int i=0;i<z;i++){
            f.pb(0);
        }
        for(int v:s){
            f.pb(v);
        }
        f.pb(n);
        vi ans(n,-1);
        vi u(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                if(f[0]==1){
                    ans[0]=0;
                    u[0]=1;
                }
            }else{
                if(f[i]>f[i-1]){
                    ans[i]=f[i-1];
                    u[f[i-1]]=1;
                }
            }
        }
        vi un,es;
        for(int i=0;i<n;i++){
            if(!u[i]){
                un.pb(i);
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                es.pb(i);
            }
        }
        for(int i=0;i<sz(un);i++){
            ans[es[i]]=un[i];
        }
        yes;cout<<el;
        for(int i=0;i<n;i++){
            cout<<ans[i];
            if(i<n-1){
                cout<<char(32);
            }
        }
        cout<<el;
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
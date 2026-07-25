/**
 * Author:  hunglvh
 * Created: 2026-07-24 10:11:12
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
namespace sub2{
    void sol(int n,vi&a){
        ll ans=0;
        vi f(n+2,0);
        for(int i=0;i<n;i++){
            int m=0;
            int u=0;
            int b=0;
            for(int j=i;j<n;j++){
                if(a[j]==-1){
                    b++;
                }else{
                    if(a[j]<=n){
                        f[a[j]]++;
                        if((f[a[j]]==1)and(a[j]<m)){
                            u--;
                        }
                    }
                }
                while(true){
                    if(f[m]>0){
                        m++;
                    }else{
                        if(u<b){
                            u++;
                            m++;
                        }else{
                            break;
                        }
                    }
                }
                ans+=m;
            }
            for(int j=i;j<n;j++){
                if((a[j]!=-1)and(a[j]<=n)){
                    f[a[j]]=0;
                }
            }
        }
        cout<<ans<<el;
    }
}

inline void solve(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi a(n);
        arr(a,n);
        sub2::sol(n,a);
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
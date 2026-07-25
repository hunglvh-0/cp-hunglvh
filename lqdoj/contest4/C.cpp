/**
 * Author:  hunglvh
 * Created: 2026-07-20 19:49:19
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
int n,l;
vi p;
bool check(int x){
    int cur=0;
    for(int i=0;i<l;i++){
        cur+=(p[i]>=x?1:-1);
    }
    if(cur>0){
        return true;
    }
    for(int i=l;i<n;i++){
        cur+=(p[i]>=x?1:-1);
        cur-=(p[i-l]>=x?1:-1);
        if(cur>0){
            return true;
        }
    }
    return false;
}

inline void solve(){
    cin>>n>>l;
    p.resize(n);
    int low=1,high=0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        high=max(high,p[i]);
    }
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
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
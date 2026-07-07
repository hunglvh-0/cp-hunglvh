/**
 * Author:  hunglvh
 * Created: 2026-07-07 11:27:36
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
    vi a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vi pr(100005,1);
    pr[0]=pr[1]=0;
    for(int i=2;i<=316;i++){
        if(pr[i]){
            for(int j=i*i;j<=100000;j+=i)pr[j]=0;
        }
    }
    vi id(n);
    for(int i=0;i<n;i++)id[i]=i+1;
    sort(all(id),[&](int x,int y){
        return a[x]<a[y];});
    vi dp(n+1,1),nxt(n+1,-1);
    for(int i=n-1;i>=0;i--){
        int u=id[i];
        for(int v=max(1,u-5);v<=min(n,u+5);v++){
            if(u!=v and a[v]>a[u] and pr[a[v]-a[u]]){
                if(dp[v]+1>dp[u]){
                    dp[u]=dp[v]+1;
                    nxt[u]=v;
                }
            }
        }
    }
    int ans=0,st=1;
    for(int i=1;i<=n;i++){
        if(dp[i]>ans){
            ans=dp[i];
            st=i;
        }
    }
    cout<<ans<<el;
    while(st!=-1){
        cout<<st<<char(32);
        st=nxt[st];
    }
    cout<<el;
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
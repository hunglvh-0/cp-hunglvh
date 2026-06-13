/**
 * Author:  hunglvh
 * Created: 2026-05-16 20:46:55
 * ❤️chau
**/
#include<bits/stdc++.h>

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
namespace sub1{
    void solve(){
        int n,k;ll sq;cin>>n>>k>>sq;
        vl a(n+1,0),pref(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pref[i]=pref[i-1]+a[i];
        }
        vvi dp(n+1,vi(k+1,-1e9));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(i,k);j++){
                for(int p=j-1;p<i;p++){
                    ll sum=pref[i]-pref[p];
                    int frag=(sum<=sq?1:0);
                    dp[i][j]=max(dp[i][j],dp[p][j-1]+frag);
                }
            }
        }
        int ans=dp[n][k];
        cout<<ans<<el;
    }
}
namespace sub2{
    void solve(){
        int n,k;ll sq;cin>>n>>k>>sq;
        vl a(n + 1, 0), pref(n + 1, 0);
        map<int,int> nf;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pref[i]=pref[i-1]+a[i];
            if(a[i]>sq){
                nf[cnt++]=i;
            }
        }
        if(cnt==0){
            int msg=0;
            int idx=1;
            while(idx<=n){
                int l=idx,r=n,nxt=idx;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    if(pref[mid]-pref[idx-1]<=sq){
                        nxt=mid;
                        l=mid+1;
                    }else
                    {
                        r=mid-1;
                    }
                }
                msg++;
                idx = nxt + 1;
            }
            if (msg <= k)
            {
                int ans = k;
                cout << ans << el;
            }
            else
            {
                int ans = k - 1;
                cout << ans << el;
            }
        }
        else
        {
            int rm=n-k;
            int cf=n-cnt;
            priority_queue<int,vector<int>,greater<int>>pq;
            for(int i=0;i<cnt-1;i++){
                int len=nf[i+1]-nf[i]-1;
                pq.push(len + 1);
            }
            while(!pq.empty() and rm>0){
                int cost=pq.top();
                if(rm>=cost){
                    rm-=cost;
                    cf-=(cost-1);
                    pq.pop();
                }else{
                    break;
                }
            }
            cf-=rm;
            int ans=max(0,cf);
            cout<<ans<<el;
        }
    }
}
void solve() {
    int t;cin>>t;
    while(t--){
        sub2::solve();
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
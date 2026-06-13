/**
 * Author:  hunglvh
 * Created: 2026-05-30 21:03:42
 * ❤️C
**/
#include<bits/stdc++.h>
/**
 * Tôi như là con kiến
 * Trong thủ đô vội vàng
 * 1000 năm văn hiến
 * 1000 năm yêu nàng❤️
 */


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
    void sol(){
        int t;cin>>t;
        while(t--){
            int n;cin>>n;
            vi a(n);
            for(int i=0;i<n;i++)cin>>a[i];
            int ok=0;
            for(int m=0;m<(1<<n);m++){
                vi x,y;
                for(int i=0;i<n;i++){
                    if(m&(1<<i))x.pb(a[i]);
                    else y.pb(a[i]);
                }
                auto chk=[&](vi&v){
                    if(sz(v)<=2){
                        if(sz(v)==2 and v[0]==v[1])return 0;
                        return 1;
                    }
                    for(int i=1;i<sz(v);i++)if(v[i]==v[i-1])return 0;
                    for(int i=2;i<sz(v);i++){
                        if(v[i-2]<v[i-1] and v[i-1]<v[i] or (v[i-2]>v[i-1] and v[i-1]>v[i]))return 0;
                    }
                    return 1;
                };
                if(chk(x) and chk(y)){
                    cout<<"YES"<<el;
                    for(int i=0;i<n;i++){
                        if(m&(1<<i))cout<<1<<" ";
                        else cout<<2 << " ";
                    }
                    cout<<el;
                    ok=1;break;
                }
            }
            if(!ok)cout<<"NO"<<el;
        }
    }
}
namespace sub2 {
    int n;
        int a[2005];
        int8_t dp[2005][2005][2][2];
        int ans[2005];
        bool dfs(int i,int j,int d1,int d2,int c){
            if(i>n){
                return 1;
            }
            if(dp[i][j][d1][d2]!=-1){
                return dp[i][j][d1][d2];
            }
            int8_t &res=dp[i][j][d1][d2];
        res=0;
        if((d1==0 and a[i]>a[i-1]) or (d1==1 and a[i]<a[i-1])){
            if(dfs(i+1,j,1-d1,d2,c)){
                ans[i]=c;
                return res=1;
            }
        }
        if(j==0){
            if(dfs(i+1,i-1,0,d1,3-c)){
                ans[i]=3-c;
                return res=1;
            }
            if(dfs(i+1,i-1,1-d2,d1,3-c)){
                ans[i]=3-c;
                return res=1;
            }
        }
        else{
            //d2==0 and ai>aj or d2==1 and ai <aj
            if((d2==0 and a[i]>a[j]) or (d2==1 and a[i]<a[j])){
                if(dfs(i+1,i-1,1-d2,d1,3-c)){
                    ans[i]=3-c;
                    return res=1;
                }
            }
        }
        return res=0;

        }
    void sol(){
        int t;cin>>t;
        while(t--){
            cin>>n;
            for(int i=1;i<=n;i++)cin>>a[i];
            if(n==1){
                cout<<"YES"<<el<<1<<el;
                continue;
            }
            for(int i=2;i<=n;i++){
                for(int j=0;j<=i;j++){
                    for(int d1=0;d1<2;d1++){
                        for(int d2=0;d2<2;d2++){
                            dp[i][j][d1][d2]=-1;
                        }
                    }
                }
            }
            ans[1]=1;
            if(dfs(2,0,1,0,1) or dfs(2,0,0,0,1)){
                cout<<"YES"<<el;
                for(int i=1;i<=n;i++){
                    cout<<ans[i]<<" ";
                }
                cout<<el;
            }
            else{
                cout<<"NO"<<el;
            }
        }
    }

}

void solve() {
    sub2::sol();
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
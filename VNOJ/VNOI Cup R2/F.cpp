/**
 * Author:  hunglvh
 * Created: 2026-05-30 21:34:23
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
            ll n;cin>>n;
            vl d;
            for(ll i=1;i<=n;i++)if(n%i==0)d.pb(i);
            int k=sz(d);
            vvi adj(k);
            for(int i=0;i<k;i++){
                for(int j=i+1;j<k;j++){
                    if(d[j]%d[i]==0)adj[i].pb(j);
                }
            }
            vi mt(k,-1),vis(k,0);
            auto dfs=[&](auto&self,int u)->bool{
                for(int v:adj[u]){
                    if(vis[v])continue;
                    vis[v]=1;
                    if(mt[v]<0 or self(self,mt[v])){
                        mt[v]=u;
                        return 1;
                    }
                }
                return 0;
            };
            int mc=0;
            for(int i=0;i<k;i++){
                vis.assign(k,0);
                if(dfs(dfs,i))mc++;
            }
            int ans=k-mc;
            cout<<ans<<el;
            vi nxt(k,-1),deg(k,0);
            for(int i=0;i<k;i++){
                if(mt[i]!=-1){
                    nxt[mt[i]]=i;
                    deg[i]++;
                }
            }
            for(int i=0;i<k;i++){
                if(deg[i]==0){
                    vl res;
                    int cur=i;
                    while(cur!=-1){
                        res.pb(d[cur]);
                        cur=nxt[cur];
                    }
                    cout<<sz(res)<<" ";
                    for(int j=0;j<sz(res);j++){
                        cout<<res[j]<<" ";
                    }cout<<el;
                }
            }
        }
    }
}
namespace sub2{
    void sol(){
        int t;cin>>t;
        while(t--){
            ll n;cin>>n;
            vl d;
            for(ll i=1;i*i<=n;i++){
                if(n%i==0){
                    d.pb(i);
                    if(i*i!=n)d.pb(n/i);
                }
            }
            sort(all(d));
            int k=sz(d);
            vl primes;
            ll tmp_n=n;
            for(ll i=2;i*i<=tmp_n;i++){
                if(tmp_n%i==0){
                    primes.pb(i);
                    while(tmp_n%i==0)tmp_n/=i;
                }
            }
            if(tmp_n>1)primes.pb(tmp_n);
            vvi adj(k);
            for(int i=0;i<k;i++){
                for(ll p : primes){
                    if(d[i]<=n/p){
                        ll nxt_val=d[i]*p;
                        int idx=lower_bound(all(d),nxt_val)-d.begin();
                        if(idx<k and d[idx]==nxt_val)adj[i].pb(idx);
                    }
                }
            }
            // for(int i=0;i<k;i++){
            //     for(int j=i+1;j<k;j++){
            //         if(d[j]%d[i]==0){
            //             ll tmp=d[j]/d[i];
            //             int prime=1;
            //             for(ll p=2;p*p<=tmp;p++){
            //                 if(tmp%p==0){
            //                     prime=0;break;
            //                 }
            //             }if(prime)adj[i].pb(j);
            //         }
            //     }
            // }
            vi mt(k,-1),vis(k,0);
            int timer=0;
            auto dfs=[&](auto&self,int u)->bool{
                for(int v:adj[u]){
                    if(vis[v]==timer)continue;
                    vis[v]=timer;
                    if(mt[v]<0 or self(self,mt[v])){
                        mt[v]=u;
                        return 1;
                    }
                }
                return 0;
            };
            int mc=0;
            for(int i=0;i<k;i++){
                timer++;
                if(dfs(dfs,i))mc++;
            }
            int ans=k-mc;
            cout<<ans<<el;
            vi nxt(k,-1),deg(k,0);
            for(int i=0;i<k;i++){
                if(mt[i]!=-1){
                    nxt[mt[i]]=i;
                    deg[i]++;
                }
            }
            for(int i=0;i<k;i++){
                if(deg[i]==0){
                    vl res;
                    int cur=i;
                    while(cur!=-1){
                        res.pb(d[cur]);
                        cur=nxt[cur];
                    }
                    cout<<sz(res)<<" ";
                    for(int j=0;j<sz(res);j++){
                        cout<<res[j]<<" ";
                    }cout<<el;
                }
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
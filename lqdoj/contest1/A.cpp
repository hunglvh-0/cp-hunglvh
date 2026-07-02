/**
 * Author:  hunglvh
 * Created: 2026-06-27 17:15:46
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
namespace sub1{
    void sol(){
        int n;cin>>n;
        map<pair<int,int>,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            for(int x=x1;x<x2;x++){
                for(int y=y1;y<y2;y++){
                    mp[{x,y}]++;
                    ans=max(ans,mp[{x,y}]);
                }
            }
        }
        cout<<ans<<el;
    }
}
//code ko rte plsss
int st[800005],lz[800005];
void down(int id){
    int t=lz[id];
    if(t){
        lz[id*2]+=t;
        st[id*2]+=t;
        lz[id*2+1]+=t;
        st[id*2+1]+=t;
        lz[id]=0;
    }
}
void up(int id,int l,int r, int u, int v, int val){
    if(v<=l or r<=u){
        return;
    }
    if(u<=l and r<=v){
        st[id]+=val;
        lz[id]+=val;
        return;
    }
    int m=(l+r)/2;
    down(id);
    up(id*2,l,m,u,v,val);
    up(id*2+1,m,r,u,v,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
inline void solve() {
    //sub1::sol();
    int n;cin>>n;
    vector<array<int,4>>ev;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        ev.pb({x1,y1,y2,1});
        ev.pb({x2,y1,y2,-1});
    }
    sort(all(ev),[](array<int,4>&a,array<int,4>&b){
            if(a[0]!=b[0])return(a[0]<b[0]);
            return(a[3]<b[3]);
    });
    int ans=0;
    for(auto &e:ev){
        up(1,0,200005,e[1],e[2],e[3]);
        ans=max(ans,st[1]);
    }
    cout<<ans<<el;
}
int32_t main() {
    fast;
    #define file "darkarea"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
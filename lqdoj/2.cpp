/**
 * Author:  hunglvh
 * Created: 2026-07-03 15:37:18
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
    int n,x,y,z;cin>>n>>x>>y>>z;
    struct V{int x,y,z,id;};
    vector<V>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].x>>v[i].y>>v[i].z;
        v[i].id=i;
    }
    sort(all(v),[](V&a,V&b){return a.x+a.y+a.z>b.x+b.y+b.z;});
    string ans(n,'0');
    bool ok=0;
    auto dfs=[&](auto&self,int i,int cx,int cy,int cz,string&cur){
        if(ok)return;
        if(cx==x and cy==y and cz==z){
            ans=cur;
            ok=1;
            return;
        }
        if(i==n)return;
        if(cx>x or cy>y or cz>z)return;
        cur[v[i].id]='1';
        self(self,i+1,cx+v[i].x,cy+v[i].y,cz+v[i].z,cur);
        if(ok)return;
        cur[v[i].id]='0';
        self(self,i+1,cx,cy,cz,cur);
    };
    string cur(n,'0');
    dfs(dfs,0,0,0,0,cur);
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
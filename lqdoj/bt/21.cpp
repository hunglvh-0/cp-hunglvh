/**
 * Author:  hunglvh
 * Created: 2026-07-08 16:20:05
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
    vector<pair<ll,ll>>a(n);
    ll q=0;
    for(int i=0;i<n;i++){
        cin>>a[i].f>>a[i].s;
        q+=a[i].f*a[i].s;
    }
    ll ans=INF;
    ll bw=0,bh=0;
    vector<vector<ll>>res(n,vector<ll>(4));
    vi p(n);
    iota(all(p),0);
    mt19937 rng(1337);
    double st=time;
    while(time-st<0.85){
        shuffle(all(p),rng);
        ll tw=sqrt(q)*(0.5+(rng()%200)/100.0);
        if(tw<=0)tw=1;
        ll cx=0,cy=0,sh=0,mx=0,my=0;
        vector<vector<ll>>tmp(n,vector<ll>(4));
        for(int i=0;i<n;i++){
            int u=p[i];
            ll w=a[u].f,h=a[u].s;
            if(rng()%2)swap(w,h);
            if(cx+w>tw and cx>0){
                cy+=sh;
                cx=0;
                sh=0;
            }
            tmp[u]={cx,cy,cx+w,cy+h};
            sh=max(sh,h);
            cx+=w;
            mx=max(mx,cx);
            my=max(my,cy+sh);
        }
        if(mx*my<ans){
            ans=mx*my;
            bw=mx;
            bh=my;
            res=tmp;
        }
    }
    cout<<bw<<" "<<bh<<el;
    for(int i=0;i<n;i++){
        cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<" "<<res[i][3]<<el;
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
/**
 * Author:  hunglvh
 * Created: 2026-05-30 19:13:21
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
void solve() {
    int h,w;cin>>h>>w;
    vs a(h);
    for(int i=0;i<h;i++)cin>>a[i];
    int b=0,c=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){b++;}
            else{c++;}
        }
    }
    vs ans(h,string(w,'.'));
    if(b==0 or c==0){
        for(int i=0;i<h;i++){
            cout<<ans[i]<<el;
        }return;
    }
    vvi d(h,vi(w,1e9));
    priority_queue<pair<int,pii>,vector<pair<int,pii>>, greater<pair<int,pii>>>pq;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            // if(a[i][j]=='#'){
            //     d[i][j]=0;
            //     pq.push({0,{i,j}});
            // }
        }
    }
    int dx[]={-1,-1,-1,0,0,1,1,1};
    int dy[]={-1,0,1,-1,1,-1,0,1};
    while(!pq.empty()){
        pair<int,pii> p=pq.top();
        pq.pop();
        int cd=p.f,x=p.s.f,y=p.s.s;
        if(cd>d[x][y]){
            continue;
        }
        for(int i=0;i<8;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>= 0 and nx<h and ny>=0 and ny<w and d[nx][ny]>cd+1){
                d[nx][ny]=cd+1;
                pq.push({d[nx][ny],{nx,ny}});
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(d[i][j]%2==0){
                ans[i][j]='#';
            }
        }cout<<ans[i]<<el;
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
/**
 * Author:  hunglvh
 * Created: 2026-06-27 18:03:00
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
//gg
inline void solve() {
    ll n,m,r,c;cin>>n>>m>>r>>c;
    vl x(n),y(n);
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    vvi adj(n);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n,0);
    queue<int> q1;
    q1.push(0);vis[0]=1;
    int cnt=1;
    while(sz(q1)){
        int u=q1.front();q1.pop();
        for(int v:adj[u]){
            if(!vis[v]){
                vis[v]=1;
                cnt++;
                q1.push(v);
            }
        }
    }
    if(cnt<n){
        cout<<-1<<el;
        return;
    }
    for(int i=0;i<n;i++){
        ll prod=x[i]*y[i];
        ll sq=sqrt(prod);
        if(sq*sq==prod){
            cout<<-1<<el;
            return;
        }
    }
    vvl d(n,vl(n,INF));
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    for(int i=0;i<n;i++){
        vvl dist(r+1,vl(c+1,INF));
        queue<pii> q2;
        q2.push({x[i],y[i]});
        dist[x[i]][y[i]]=0;
        while(sz(q2)){
            pii p=q2.front();q2.pop();
            int cx=p.f,cy=p.s;
            for(int k=0;k<4;k++){
                int nx=cx+dx[k],ny=cy+dy[k];
                if(nx>=1 and nx<=r and ny>=1 and ny<=c){
                    ll prod=1ll*nx*ny;
                    ll sq=sqrt(prod);
                    if(sq*sq!=prod){
                        if(dist[nx][ny]==INF){
                            dist[nx][ny]=dist[cx][cy]+1;
                            q2.push({nx,ny});
                        }
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            d[i][j]=dist[x[j]][y[j]];
            if(d[i][j]==INF){
                cout<<-1<<el;
                return;
            }
        }
    }
    if(n==1){
        cout<<0<<el;
        return;
    }
    vvl dp(1<<n,vl(n,INF));
    dp[1][0]=0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(mask&(1<<u)){
                for(int v=0;v<n;v++){
                    if(!(mask&(1<<v))){
                        dp[mask|(1<<v)][v]=min(dp[mask|(1<<v)][v],dp[mask][u]+d[u][v]);
                    }
                }
            }
        }
    }
    ll ans=INF;
    for(int u=1;u<n;u++){
        ans=min(ans,dp[(1<<n)-1][u]+d[u][0]);
    }
    if(ans>=INF)cout<<-1<<el;
    else cout<<ans<<el;
}
int32_t main() {
    fast;
    #define file "cosmicbrew"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
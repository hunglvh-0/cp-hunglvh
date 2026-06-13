/**
 * Author:  hunglvh
 * Created: 2026-05-23 20:07:41
 * ❤️chau
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
const ll MOD = 998244353;
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
vi adj[200005];
ll c[200005],d[200005],avail[200005];
ll ans=1;

ll calc(ll n,ll k){
	if(k>n or k<0)return 0;
	if(k==0)return 1;
	ll a=1,b=1;
	for(ll i=1;i<=k;i++){
		a=(a*((n-i+1)%MOD))%MOD;
		b=(b*i)%MOD;
	}
	return(a*pow_mod(b,MOD-2,MOD))%MOD;
}

void dfs(int u){
	avail[u]=c[u];
	for(int v:adj[u]){
		dfs(v);
		avail[u]+=avail[v]-d[v];
	}
	ans=(ans*calc(avail[u],d[u]))%MOD;
}

void solve(){
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		adj[p].pb(i);
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>d[i];
	dfs(1);
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
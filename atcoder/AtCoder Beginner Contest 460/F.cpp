/**
 * Author:  hunglvh
 * Created: 2026-05-30 19:58:19
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
    int n;cin>>n;
	vvi adj(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vvi up(n+1,vi(20,0));
	vi dep(n+1,0);
	auto dfs=[&](auto&&dfs,int u,int p)->void{
		up[u][0]=p;
		for(int i=1;i<20;i++)up[u][i]=up[up[u][i-1]][i-1];
		for(int v:adj[u]){
			if(v!=p){
				dep[v]=dep[u]+1;
				dfs(dfs,v,u);
			}
		}
	};
	dfs(dfs,1,1);
	auto lca=[&](int u,int v)->int{
		if(dep[u]<dep[v])swap(u,v);
		for(int i=19;i>=0;i--)if(dep[u]-(1<<i)>=dep[v])u=up[u][i];
		if(u==v)return u;
		for(int i=19;i>=0;i--)if(up[u][i]!=up[v][i]){u=up[u][i];v=up[v][i];}
		return up[u][0];
	};
	auto dist=[&](int u,int v)->int{
		if(u==0 or v==0)return -1;
		return dep[u]+dep[v]-2*dep[lca(u,v)];
	};
	struct Nd{int u,v,d;};
	vector<Nd>st(4*n+5);
	vi col(n+1,0);
	auto mg=[&](Nd a,Nd b)->Nd{
		if(a.u==0)return b;
		if(b.u==0)return a;
		Nd r=a;
		if(b.d>r.d)r=b;
		vi nd={a.u,a.v,b.u,b.v};
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				if(nd[i] and nd[j]){
					int d=dist(nd[i],nd[j]);
					if(d>r.d){r.u=nd[i];r.v=nd[j];r.d=d;}
				}
			}
		}
		return r;
	};
	auto bld=[&](auto&&bld,int id,int l,int r)->void{
		if(l==r){st[id]={l,l,0};return;}
		int m=(l+r)/2;
		bld(bld,id*2,l,m);
		bld(bld,id*2+1,m+1,r);
		st[id]=mg(st[id*2],st[id*2+1]);
	};
	bld(bld,1,1,n);
	auto upd=[&](auto&&upd,int id,int l,int r,int p)->void{
		if(l==r){
			if(col[l]==0)st[id]={l,l,0};
			else st[id]={0,0,-1};
			return;
		}
		int m=(l+r)/2;
		if(p<=m)upd(upd,id*2,l,m,p);
		else upd(upd,id*2+1,m+1,r,p);
		st[id]=mg(st[id*2],st[id*2+1]);
	};
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		col[x]^=1;
		upd(upd,1,1,n,x);
		int ans=st[1].d;
		cout<<ans<<el;
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
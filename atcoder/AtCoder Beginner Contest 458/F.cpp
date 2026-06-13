/**
 * Author:  hunglvh
 * Created: 2026-05-16 19:13:46
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
//aho corasick 100%
void solve() {
    ll n;int k;cin>>n>>k;
	ll md=998244353;
	int tr[105][26],fa[105],bd[105];
	int cnt=0;
	memset(tr,0,sizeof(tr));
	memset(fa,0,sizeof(fa));
	memset(bd,0,sizeof(bd));
	for(int i=0;i<k;i++){
		string s;cin>>s;
		int u=0;
		for(char c:s){
			if(!tr[u][c-'a'])tr[u][c-'a']=++cnt;
			u=tr[u][c-'a'];
		}
		bd[u]=1;
	}
	queue<int>q;
	for(int j=0;j<26;j++){
		if(tr[0][j])q.push(tr[0][j]);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		bd[u]|=bd[fa[u]];
		for(int j=0;j<26;j++){
			if(tr[u][j]){
				fa[tr[u][j]]=tr[fa[u]][j];
				q.push(tr[u][j]);
			}else{
				tr[u][j]=tr[fa[u]][j];
			}
		}
	}
	vvl A(cnt+1,vl(cnt+1,0)),R(cnt+1,vl(cnt+1,0));
	for(int i=0;i<=cnt;i++){
		if(bd[i])continue;
		for(int j=0;j<26;j++){
			if(!bd[tr[i][j]])A[i][tr[i][j]]++;
		}
	}
	for(int i=0;i<=cnt;i++)R[i][i]=1;
	auto mul=[&](vvl a,vvl b){
		vvl r(cnt+1,vl(cnt+1,0));
		for(int i=0;i<=cnt;i++)for(int x=0;x<=cnt;x++)for(int j=0;j<=cnt;j++)r[i][j]=(r[i][j]+a[i][x]*b[x][j])%md;
		return r;
	};
	while(n>0){
		if(n&1)R=mul(R,A);
		A=mul(A,A);
		n>>=1;
	}
	ll ans=0;
	for(int i=0;i<=cnt;i++)ans=(ans+R[0][i])%md;
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
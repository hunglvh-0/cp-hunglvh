/**
 * Author:  hunglvh
 * Created: 2026-05-16 20:27:33
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
void solve() {
	int t;cin>>t;
	while(t--){
		int n,m,rb,cb;cin>>n>>m>>rb>>cb;
		map<string,int> M;
		M["ansR"]=1e9;
		M["ansC"]=1e9;
		if(rb==1)
		{
			M["ansR"]=n-1;
		}
		else
		{
			M["ansR"]=2*n-rb-1;
		}
		if(cb==1)
		{
			M["ansC"]=m-1;
		}else
		{
			M["ansC"]=2*m-cb-1;
		}
		int l=0,r=1e9;
		int ans=1e9;
		while(l<=r){
			int mid=l+(r-l)/2;
			if((mid>=M["ansR"]) or (mid>=M["ansC"])){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}cout<<ans<<el;
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
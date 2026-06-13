/**
 * Author:  hunglvh
 * Created: 2026-05-23 21:34:57
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
    int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vl a(n),b(n);
		arr(a,n);
		arr(b,n);
		ll tms=0;
		for(int i=0;i<n;i++){
			tms+=max(a[i],b[i]);
		}
		ll ans=0;
		ans=0;
		for(int i=0;i<n;i++){
			ll cur1=tms-max(a[i],b[i])+b[i]+a[i];
			if(cur1>ans){
				ans=cur1;
			}
			ll cur2=tms-max(a[i],b[i])+a[i]+b[i];
			if(cur2>ans){
				ans=cur2;
			}
			ll op1=a[i]+(tms-max(a[i],b[i])+b[i]);
			ll op2=b[i]+(tms-max(a[i],b[i])+a[i]);
			ans=max({ans,op1,op2});
		}
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
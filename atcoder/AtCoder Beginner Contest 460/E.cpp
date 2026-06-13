/**
 * Author:  hunglvh
 * Created: 2026-05-30 19:31:18
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
    ll t;cin>>t;
	while(t--){
		ll n,m,ans=0;cin>>n>>m;
		i128 p=1,p10=10;
		ll r=10%m;
		for(int l=1;l<=19;l++){
			if(p>n)break;
			i128 lft=p,rgt=n,mx=p-1;
			while(lft<=rgt){
				i128 md=lft+(rgt-lft)/2;
				if(md<p10){
					mx=md;
					lft=md+1;
				}else{
					rgt=md-1;
				}
			}
			if(mx<p or p>n)continue;
			ll cy=(ll)(mx-p+1)%998244353;
			ll v=(r+m-1)%m;
			ll g=gcd(m,v);
			ll k=m/g;
			ll cx=(n/k)%998244353;
			ans=(ans+cx*cy)%998244353;
			p=p10;
			p10*=10;
			r=(r*10)%m;
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
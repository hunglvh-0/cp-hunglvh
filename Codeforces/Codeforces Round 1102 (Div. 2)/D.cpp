/**
 * Author:  hunglvh
 * Created: 2026-06-07 22:03:12
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
    int t;cin>>t;
	vl f(35),g(35);
	f[0]=1;g[0]=2;
	for(int i=1;i<=30;i++){
		f[i]=f[i-1]+g[i-1]-1;
		g[i]=2*f[i-1];
	}
	while(t--){
		ll n,k;cin>>n>>k;
		string s,z;cin>>s>>z;
		ll c01=0,c10=0,c11=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0' and z[i]=='1')c01++;
			if(s[i]=='1' and z[i]=='0')c10++;
			if(s[i]=='1' and z[i]=='1')c11++;
		}
		i128 C01=c01,C10=c10,C11=c11,FK=f[k],GK=g[k];
		i128 sum_x=C01*FK+C10*FK+C11*GK;
		i128 sum_x2=C01*C01*FK+C10*C10*FK+C11*C11*GK+2*C01*C10*(FK-GK/2)+2*C01*C11*(GK/2)+2*C10*C11*(GK/2);
		i128 ans=(i128)n*sum_x-sum_x2;
		string res="";
		if(ans==0)res="0";
		while(ans>0){
			res+=char((int)(ans%10)+'0');
			ans/=10;
		}
		reverse(all(res));
		cout<<res<<el;
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
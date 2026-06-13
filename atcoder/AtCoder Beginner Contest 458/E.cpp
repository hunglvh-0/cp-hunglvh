/**
 * Author:  hunglvh
 * Created: 2026-05-16 19:03:12
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
    ll md=998244353;
	int x1,x2,x3;cin>>x1>>x2>>x3;
	//vector<ll>f(1000000),iv(1000000);
	vector<ll>f(x1+x2+x3+5),iv(x1+x2+x3+5);
	f[0]=1;
	for(int i=1;i<=x1+x2+x3;i++)f[i]=(f[i-1]*i)%md;
	iv[x1+x2+x3]=pow_mod(f[x1+x2+x3],md-2,md);
	for(int i=x1+x2+x3-1;i>=0;i--)iv[i]=(iv[i+1]*(i+1))%md;
	auto C=[&](int n,int k)->ll{
		//if(k>n||k<0)return 1;
		if(n<0 or k>n or k<0)return 0;
		return f[n]*iv[k]%md*iv[n-k]%md;
	};
	ll ans=0;
	//int lim=max(x1,x2+1);
	int lim=min(x1,x2+1);
	for(int k=1;k<=lim;k++){
		//ll tmp=(C(x1-1,k-1)+C(x2+1,k))%md;
		ll tmp=C(x1-1,k-1)*C(x2+1,k)%md;
		//ans=(ans+tmp*C(x2+x3-k,x3));
		ans=(ans+tmp*C(x2+x3-k,x3)%md)%md;
	}
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
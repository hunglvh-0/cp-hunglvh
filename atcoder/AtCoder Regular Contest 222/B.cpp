/**
 * Author:  hunglvh
 * Created: 2026-06-14 19:38:46
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
inline void solve() {
    int t;cin>>t;
	while(t--){
		ll a,b,c;cin>>a>>b>>c;
		ll ans=0;
		if(a==0 and b==0 and c==0){cout<<0<<el;continue;}
		if(a==0 and b==0){cout<<0<<el;continue;}
		if(b==0 and c==0){cout<<0<<el;continue;}
		if(c==0 and a==0){cout<<0<<el;continue;}
		if(c==0){
			if(a<=b)ans=a;
			else ans=b-1;
			cout<<ans<<el;continue;
		}
		if(b==0){
			if(c<=a)ans=c;
			else ans=a-1;
			cout<<ans<<el;continue;
		}
		if(a==0){
			if(b<=c)ans=b;
			else ans=c-1;
			cout<<ans<<el;continue;
		}
		for(int mask=0;mask<8;mask++){
			ll I0=(mask&1)?1:0;
			ll I1=(mask&2)?1:0;
			ll I2=(mask&4)?1:0;
			ll A=a-I2;
			ll B=b-I0;
			ll C=c-I1;
			if(A<0 or B<0 or C<0)continue;
			ll cur=0;
			if(mask==0)cur=0;
			if(mask==1)cur=min(A,B);
			if(mask==2)cur=min(B,C);
			if(mask==4)cur=min(C,A);
			if(mask==3)cur=min(B,A+C);
			if(mask==6)cur=min(C,B+A);
			if(mask==5)cur=min(A,C+B);
			if(mask==7)cur=min({(A+B+C)/2,A+B,B+C,C+A});
			ans=max(ans,cur);
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
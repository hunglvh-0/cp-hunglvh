/**
 * Author:  hunglvh
 * Created: 2026-06-20 19:24:04
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
    int n;cin>>n;
	vi a(2*n);
	int v=0;
	for(int i=0;i<2*n;i++){
		cin>>a[i];
		v=max(v,a[i]);
	}
	ll md=998244353;
	vl f(2*n+5,1),invf(2*n+5,1);
	for(int i=1;i<=2*n;i++)f[i]=f[i-1]*i%md;
	invf[2*n]=pow_mod(f[2*n],md-2,md);
	for(int i=2*n-1;i>=1;i--)invf[i]=invf[i+1]*(i+1)%md;
	auto nCr=[&](int N,int R){
		if((R<0)or(R>N))return(0LL);
		return f[N]*invf[R]%md*invf[N-R]%md;
	};
	map<pii,ll>memo;
	auto eval=[&](int A,int B){
		if(memo.count({A,B}))return memo[{A,B}];
		ll res=0;
		for(int k=0;k<=B;k++){
			ll term=nCr(B,k)*pow_mod(A+k+1,md-2,md)%md;
			res=(res+term)%md;
		}
		return memo[{A,B}]=res;
	};
	int c0=0,c1=0,c2=0,c3=0,c4=0,c5=0;
	int d0=0,d1=0,d2=0;
	for(int j=0;j<n;j++){
		int A=a[2*j],B=a[2*j+1];
		if((A<v-1)and(B<v-1))c0++;
		else{if(((A==v-1)and(B<v-1))or((A<v-1)and(B==v-1)))c1++;
		else{if((A==v-1)and(B==v-1))c2++;
		else{if(((A==v)and(B<v-1))or((A<v-1)and(B==v)))c3++;
		else{if(((A==v)and(B==v-1))or((A==v-1)and(B==v)))c4++;
		else{if((A==v)and(B==v))c5++;}}}}}
		if((A<v)and(B<v))d0++;
		else{if(((A==v)and(B<v))or((A<v)and(B==v)))d1++;
		else{if((A==v)and(B==v))d2++;}}
	}
	int Ap=c2+c3+c4*2;
	int Bp=c1;
	int Dp=c1+c3+c4;
	int Adp=d2;
	int Bdp=d1;
	int Ddp=d1;
	for(int i=0;i<2*n;i++){
		int me=a[i];
		int op=a[i^1];
		ll ans=0;
		if(me==v){
			int cv=0;
			if((me<v)and(op<v))cv=0;
			else{if(((me==v)and(op<v))or((me<v)and(op==v)))cv=1;
			else{if((me==v)and(op==v))cv=2;}}
			int adp=Adp-((cv==2)?1:0);
			int bdp=Bdp-((cv==1)?1:0);
			int ddp=Ddp-((cv==1)?1:0);
			ll prob=eval(adp,bdp);
			ll inv2=pow_mod(pow_mod(2,ddp+1,md),md-2,md);
			prob=prob*inv2%md;
			ans=(ans+prob)%md;
		}
		if(me>=v-1){
			int typ=0;
			if((me<v-1)and(op<v-1))typ=0;
			else{if(((me==v-1)and(op<v-1))or((me<v-1)and(op==v-1)))typ=1;
			else{if((me==v-1)and(op==v-1))typ=2;
			else{if(((me==v)and(op<v-1))or((me<v-1)and(op==v)))typ=3;
			else{if(((me==v)and(op==v-1))or((me==v-1)and(op==v)))typ=4;
			else{if((me==v)and(op==v))typ=5;}}}}}
			bool valid=true;
			if(c5-((typ==5)?1:0)>0)valid=false;
			if((me==v)and(op==v))valid=false;
			if(valid){
				int c_oth=((me==v)?((op==v-1)?1:0):((op==v)?1:0));
				int ap=Ap,bp=Bp,dp=Dp;
				if(typ==1){bp--;dp--;}
				else{if(typ==2){ap--;}
				else{if(typ==3){ap--;dp--;}
				else{if(typ==4){ap-=2;dp--;}}}}
				ll prob=eval(ap+c_oth,bp);
				ll inv2=pow_mod(pow_mod(2,dp+1,md),md-2,md);
				prob=prob*inv2%md;
				ans=(ans+prob)%md;
			}
		}
		cout<<ans;
		if(i<2*n-1)cout<<char(32);
	}
	cout<<el;
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
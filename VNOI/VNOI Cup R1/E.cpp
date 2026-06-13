/**
 * Author:  hunglvh
 * Created: 2026-05-17 11:01:18
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
namespace sub2{
	void solve(){
		int n,q;cin>>n>>q;
		vi f(n+2);
		for(int i=1;i<=n;i++)cin>>f[i];
		vi p(n+2),ord(n+2);
		vi tmp;
		for(int i=1;i<=n;i++){
			tmp.insert(tmp.begin()+f[i],i);
		}
		for(int i=0;i<n;i++)
		{
			ord[i+1]=tmp[i];
			p[tmp[i]]=i+1;
		}
		while(q--){
			char type;cin>>type;
			if(type=='+'){
				int i;cin>>i;
				int pos=p[i];
				int pos2=pos+1;
				while(pos2<=n and ord[pos2]>i)pos2++;
				int val1=ord[pos];
				int val2=ord[pos2];
				ord[pos]=val2;
				ord[pos2]=val1;
				p[ord[pos]]=pos;
				p[ord[pos2]]=pos2;
			}else if(type=='-'){
				int i;cin>>i;
				int pos=p[i];
				int pos2=pos-1;
				while(pos2>=1 and ord[pos2]>i)pos2--;
				int val1=ord[pos];
				int val2=ord[pos2];
				ord[pos]=val2;
				ord[pos2]=val1;
				p[ord[pos]]=pos;
				p[ord[pos2]]=pos2;
			}else{
				int l,r;cin>>l>>r;
				ll ans=0;
				for(int j=l;j<=r;j++){
					ans+=p[j];
				}
				cout<<ans<<el;
			}
		}
	}
}

void solve(){
	sub2::solve();
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
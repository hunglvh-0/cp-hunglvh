/**
 * Author:  hunglvh
 * Created: 2026-05-17 14:42:16
 * ❤️chau
**/
#include<bits/stdc++.h>
/**
 * Tôi như là con kiến
 * Trong thủ đô vội vàng
 * 1000 năm văn hiến
 * 1000 năm yêu nàng❤️
 */
//sol with editorial ^^
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
const ll MOD = 998244353;
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
namespace sub1{
	vvi val[8][8];
	bool ini=false;
	void pre(){
		for(int n=1;n<=7;n++){
			vi p(n);
			for(int i=0;i<n;i++)p[i]=i;
			map<vi,vvi>grp;
			do{
				vi mx_mat;
				for(int i=0;i<n;i++){
					int msk=0;
					for(int j=i;j<n;j++){
						msk|=(1<<p[j]);
						int mex=0;
						while(msk&(1<<mex))mex++;
						mx_mat.pb(mex);
					}
				}
				grp[mx_mat].pb(p);
			}while(next_permutation(all(p)));
			for(auto g:grp){
				for(int k=0;k<n;k++){
					bool ok=true;
					int pos=-1;
					for(auto p2:g.s){
						int cpos=0;while(p2[cpos]!=k)cpos++;
						if(pos==-1)pos=cpos;
						else if(pos!=cpos)ok=false;
					}
					if(ok){
						for(auto p2:g.s)val[n][k].pb(p2);
					}
				}
			}
		}
		ini=true;
	}
	void solve(){
		if(!ini)pre();
		int t;cin>>t;
		while(t--){
			int n;cin>>n;
			vi a(n);arr(a,n);
			for(int k=0;k<n;k++){
				ll ans=0;
				for(auto p:val[n][k]){
					bool mt=true;
					for(int i=0;i<n;i++){
						if(a[i]!=-1 and a[i]!=p[i])
                        {
                            mt=false;
                            break;
                        }
					}
					if(mt){
						ans=(ans+1)%MOD;
					}
				}
				cout<<ans<<" ";
			}
			cout<<el;
		}
	}
}

void solve(){
	sub1::solve();
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
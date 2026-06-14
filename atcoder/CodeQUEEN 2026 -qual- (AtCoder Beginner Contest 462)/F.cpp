/**
 * Author:  hunglvh
 * Created: 2026-06-13 19:53:02
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
		string str;int k;cin>>str>>k;
		int n=sz(str);
		int dp[2][205][3];
		for(int d=0;d<205;d++)for(int s=0;s<3;s++)dp[0][d][s]=dp[1][d][s]=1e9;
		dp[0][100][0]=0;
		for(int i=0;i<n;i++){
			int cur=(i+1)%2;
			int pre=i%2;
			for(int d=0;d<205;d++)for(int s=0;s<3;s++)dp[cur][d][s]=1e9;
			int o=(i>=2 and str[i-2]=='A' and str[i-1]=='B' and str[i]=='C')?1:0;
			char c=str[i];
			for(int d=0;d<205;d++){
				for(int s=0;s<3;s++){
					int v=dp[pre][d][s];
					if(v==1e9)continue;
					int nd=d-o;
					int nc=d-o+((s==2)?1:0);
					int cA=(c=='A')?0:1;
					if(nd>=0 and nd<205)dp[cur][nd][1]=min(dp[cur][nd][1],v+cA);
					int cB=(c=='B')?0:1;
					int nb=(s==1)?2:0;
					if(nd>=0 and nd<205)dp[cur][nd][nb]=min(dp[cur][nd][nb],v+cB);
					int cC=(c=='C')?0:1;
					if(nc>=0 and nc<205)dp[cur][nc][0]=min(dp[cur][nc][0],v+cC);
					int cZ=(c!='A' and c!='B' and c!='C')?0:1;
					if(nd>=0 and nd<205)dp[cur][nd][0]=min(dp[cur][nd][0],v+cZ);
				}
			}
		}
		int ans=min({dp[n%2][100+k][0],dp[n%2][100+k][1],dp[n%2][100+k][2]});
		if(ans>1e8)cout<<-1<<el;
		else cout<<ans<<el;
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
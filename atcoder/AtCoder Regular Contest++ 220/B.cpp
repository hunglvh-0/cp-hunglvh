/**
 * Author:  hunglvh
 * Created: 2026-05-17 19:14:09
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
    int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vi a(n+1),b(n+1),in(n+1,0),out(n+1,0);
		for(int i=1;i<=n;i++){cin>>a[i];in[a[i]]++;}
		for(int i=1;i<=n;i++){cin>>b[i];out[b[i]]++;}
		vi p(n+1);iota(all(p),0);
		function<int(int)>find=[&](int i)
        {
            return p[i]==i?i:p[i]=find(p[i]);
        };
		auto unite=[&](int i,int j)
        {
			int ri=find(i);
			int rj=find(j);
			if(ri!=rj)p[ri]=rj;
		};
		for(int i=1;i<=n;i++)unite(a[i],b[i]);
		vi act(n+1,0);
		for(int i=1;i<=n;i++)
        {
            act[a[i]]=1;
            act[b[i]]=1;
        }
		int c=0;
		for(int i=1;i<=n;i++)c+=min(in[i],out[i]);
		vi D(n+1,0),is(n+1,0);
		for(int i=1;i<=n;i++){
			if(act[i]){
				int r=find(i);
				is[r]=1;
				D[r]+=max(0,in[i]-out[i]);
			}
		}
		int K=0,P=0,Kb=0;
		for(int i=1;i<=n;i++){
			if(is[i]){
				K++;
				P+=D[i];
				if(D[i]==0)Kb++;
			}
		}
		int pen=0;
		if(P==0)
        {
            if(K==1)pen=0;
            else
            {
                pen=K;
            }
        }
        else{
            pen=Kb;
        }
		int ans=c-pen;
        //cout<<c<<el;
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
/**
 * Author:  hunglvh
 * Created: 2026-06-09 22:18:32
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
	while(t--){
		int n;cin>>n;
		vi a(n);arr(a,n);
		vi tmp=a;
        sort(all(tmp));
		tmp.erase(unique(all(tmp)),tmp.end());
		int u=sz(tmp);
		int b=1;
		for(int i=0;i<n-1;i++)if(a[i]!=a[i+1])b++;
		if(b==u){
            cout<<"YES"<<el;
            continue;
        }
		if(b>u+3){
            cout<<"NO"<<el;
            continue;
        }
		map<int,int>cnt;
		cnt[a[0]]++;
		for(int i=1;i<n;i++)if(a[i]!=a[i-1])cnt[a[i]]++;
		set<int>bad;
		for(auto&p:cnt)if(p.s>1)bad.insert(p.f);
		set<int>C;
		for(int i=0;i<n;i++){
			if(bad.count(a[i])){
				if(i==0 or a[i]!=a[i-1]){
					C.insert(i);
					if(i>0)C.insert(i-1);
				}
				if(i==n-1 or a[i]!=a[i+1]){
					C.insert(i);
					if(i<n-1)C.insert(i+1);
				}
			}
		}
		vi cv(all(C));
		string ans="NO";
		for(int i=0;i<sz(cv);i++){
			for(int j=i;j<sz(cv);j++){
				int u_idx=cv[i],v_idx=cv[j];
				set<int>chk;
				chk.insert(u_idx);
				if(u_idx>0)chk.insert(u_idx-1);
				chk.insert(v_idx);
				if(v_idx>0)chk.insert(v_idx-1);
				int b_bef=0;
				for(int x:chk)if(x>=0 and x<n-1 and a[x]!=a[x+1])b_bef++;
				swap(a[u_idx],a[v_idx]);
				int b_aft=0;
				for(int x:chk)if(x>=0 and x<n-1 and a[x]!=a[x+1])b_aft++;
				if(b-b_bef+b_aft==u){
					int cur_b=1;
					for(int k=0;k<n-1;k++)if(a[k]!=a[k+1])cur_b++;
					if(cur_b==u){ans="YES";break;}
				}
				swap(a[u_idx],a[v_idx]);
			}
			if(ans=="YES")break;
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
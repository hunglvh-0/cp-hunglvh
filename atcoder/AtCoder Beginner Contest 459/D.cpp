/**
 * Author:  hunglvh
 * Created: 2026-05-23 19:51:41
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
    int	t;cin>>t;
	while(t--){
		string str;cin>>str;
		int n=sz(str);
		vi cnt(26,0);
		for(int	i=0;i<n;i++)cnt[str[i]-'a']++;
		int	mx=0;for(int i=0;i<26;i++)mx=max(mx,cnt[i]);
		if((n>0)and(mx>(n+1)/2))
        {
            cout<<"No"<<el;
            continue;
        }
		cout<<"Yes"<<el;
		priority_queue<pair<int,char>>pq;
		for(int	i=0;i<26;i++){
			if(cnt[i]>0)pq.push({cnt[i],(char)(i+'a')});
		}
		string ans="";
		while(pq.size()>1){
			auto[f1,c1]=pq.top();
            pq.pop();
			auto[f2,c2]=pq.top();
            pq.pop();
			ans+=c1;
            ans+=c2;
			f1--;
            f2--;
			if(f1>0)pq.push({f1,c1});
			if(f2>0)pq.push({f2,c2});
		}
		if(!pq.empty())ans+=pq.top().s;
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
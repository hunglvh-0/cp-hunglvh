/**
 * Author:  hunglvh
 * Created: 2026-06-08 11:00:34
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
        vl h(n);arr(h,n);
        int m=0;
        for(int i=1;i<n;i++)if(h[i]>h[m])m=i;
        vl b(2*n);
        for(int i=0;i<n;i++){
            b[i]=h[(m+1+i)%n];
            b[i+n]=b[i];
        }
        vl ansL(n),ansR(2*n);
        ansL[n-1]=0;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and (b[st.top()]<b[i]))st.pop();
            int nge=st.top();
            ansL[i]=ansL[nge]+1ll*b[i]*(nge-i);
			st.push(i);
        }
        ansR[n-1]=0;
		while(!st.empty())st.pop();
		st.push(n-1);
		for(int	i=n;i<2*n-1;i++){
			while(!st.empty()and(b[st.top()]<b[i]))st.pop();
			int	pge=st.top();
			ansR[i]=ansR[pge]+1ll*b[i]*(i-pge);
			st.push(i);
		}
		vl fa(n);
		for(int	i=0;i<n;i++)fa[(m+1+i)%n]=ansL[i]+ansR[i+n-1];
		for(int	i=0;i<n;i++)cout<<fa[i]<<'\x20';
		cout<<el;
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
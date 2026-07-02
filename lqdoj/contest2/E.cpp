/**
 * Author:  hunglvh
 * Created: 2026-07-02 11:52:10
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
    int n,q,k;cin>>n>>q>>k;
    string s;cin>>s;
    vl v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    set<int>st[26];
    for(int i=0;i<n;i++)st[s[i]-'a'].insert(i+1);
    while(q--){
        int type;cin>>type;
        if(type==1){
            int i;char c;cin>>i>>c;
            st[s[i-1]-'a'].erase(i);
            s[i-1]=c;
            st[c-'a'].insert(i);
        }else{
            int l,r;char c;cin>>l>>r>>c;
            vi a;
            auto it=st[c-'a'].lower_bound(l);
            while(it!=st[c-'a'].end() and *it<=r){
                a.pb(*it);
                it++;
            }
            if(a.empty()){
                cout<<0<<el;
                continue;
            }
            vl dp(sz(a),0),mx(sz(a),0);
            for(int i=0;i<sz(a);i++){
                dp[i]=v[a[i]];
                int p=upper_bound(all(a),a[i]-k)-a.begin()-1;
                if(p>=0)dp[i]+=mx[p];
                mx[i]=max(dp[i],i>0?mx[i-1]:0LL);
            }
            ll ans=mx.back();
            cout<<ans<<el;
        }
    }
}
int32_t main() {
    fast;
    #define file "prbe"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
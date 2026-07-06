/**
 * Author:  hunglvh
 * Created: 2026-07-06 21:38:15
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
        ll n;cin>>n;
        vl a(n);
        for(ll i=0;i<n;i++)cin>>a[i];
        vl p1(n,0),p2(n,0),p3(n,0),d(n,0);
        for(ll i=0;i<n;i++){
            if(i>0){
                p1[i]=p1[i-1];
                p2[i]=p2[i-1];
                p3[i]=p3[i-1];
            }
            if(a[i]==1)p1[i]++;
            if(a[i]==2)p2[i]++;
            if(a[i]==3)p3[i]++;
            d[i]=p1[i]+p2[i]-p3[i];
        }
        ll k=__lg(n)+2;
        vvl st(n,vl(k,0));
        for(ll i=0;i<n;i++)st[i][0]=d[i];
        for(ll j=1;j<k;j++){
            for(ll i=0;i+(1<<j)<=n;i++){
                st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
        string ans="NO";
        for(ll i=0;i<n-2;i++){
            if(p1[i]>=p2[i]+p3[i]){
                ll ql=i+1,qr=n-2;
                ll lg=__lg(qr-ql+1);
                ll mx=max(st[ql][lg],st[qr-(1<<lg)+1][lg]);
                if(mx>=d[i]){
                    ans="YES";
                    break;
                }
            }
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
/**
 * Author:  hunglvh
 * Created: 2026
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
void pr(i128 x){
    if(x<0){
        cout<<'-';
        x=-x;

    }
    if(x>9){
        pr(x/10);

    }
    cout<<(char)('0'+x%10);
}
i128 cd(i128 a,i128 b){
    return (a+b-1)/b;
}
inline void solve() {
    ll d,x,k,y;cin>>d>>x>>k>>y;
    i128 kx=(i128)k*x;
    if(kx>=(i128)d){
        i128 ans=cd(d,x);
        pr(ans);
        cout<<el;
        return;
    }
    i128 net=kx-(i128)y;
    if(net<=0){
        cout<<-1<<el;
        return;
    }
    i128 rem=(i128)d-kx;
    i128 iv=cd(rem,net  );
    i128 pos=iv*net;
    i128 rm2=(i128)d-pos;
    i128 j;
    if(rm2<=0){
        j=1;
    }
    else{
        j=cd(rm2,(i128)x);
    }
    i128 ans=iv*((i128)k+1)+j;
    pr(ans);
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

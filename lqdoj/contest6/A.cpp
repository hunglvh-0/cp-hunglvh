/**
 * Author:  hunglvh
 * Created: 2026-07-11 16:04:02
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
#define arr(a,n) for(int i=0;i<n;i++)cin>>a[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
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
ll gcd(ll a, ll b){return std::gcd(a, b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
ll pow_mod(ll a, ll b, ll m = MOD){
    ll res=1;a%=m;
    while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}
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

ll cal(ll d,ll x,ll k,ll y){
    i128 _d=d;
    i128 _x=x;
    i128 _k=k;
    i128 _y=y;
    if(_d<=_k*_x){
        return(ll)((_d+_x-1)/_x);
    }
    i128 c=_k*_x-_y;
    i128 d2=_d-_k*_x;
    i128 m=(d2+c-1)/c;
    i128 rm=_d-m*c;
    i128 ans=m*(_k+1)+(rm+_x-1)/_x;
    //debug(ans);
    return(ll)ans;
}

inline void solve(){
    ll d,x,k,y;cin>>d>>x>>k>>y;
    ll ans=cal(d,x,k,y);
    cout<<ans<<el;
}

int32_t main(){
    fast;
    #define file "main"
    if(fopen(file".INP","r")){
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
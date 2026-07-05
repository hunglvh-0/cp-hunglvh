/**
 * Author:  hunglvh
 * Created: 2026-06-05 10:54:19
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
namespace sub3{
    void sol(){
        int n,q;cin>>n>>q;
        vl a(n+1);
        for(int i=0;i<=n;i++)cin>>a[i];
        ll last_ans=0;
        ll p=998244353;
        vl f(400005,1),inv(400005,1);
        auto pw=[&](ll x,ll y){
            ll r=1;x%=p;
            while(y>0){if(y&1)r=(r*x)%p;x=(x*x)%p;y>>=1;}
            return r;
        };
        for(int i=1;i<=400000;i++)f[i]=(f[i-1]*i)%p;
        inv[400000]=pw(f[400000],p-2);
        for(int i=399999;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%p;
        auto C=[&](int n1,int k1){
            if(k1<0 or k1>n1)return 0LL;
            return f[n1]*inv[k1]%p*inv[n1-k1]%p;
        };
        while(q--){
            char type;cin>>type;
            if(type=='D'){
                if(sz(a)>0)a.erase(a.begin());
            }else if(type=='S'){
                ll c;cin>>c;c^=last_ans;c%=p;
                vl nxt(sz(a),0);
                for(int i=0;i<sz(a);i++){
                    for(int j=i;j<sz(a);j++){
                        ll val=(a[j]*C(j,i))%p;
                        val=(val*pw(c,j-i))%p;
                        nxt[i]=(nxt[i]+val)%p;
                    }
                }
                a=nxt;
            }else if(type=='M'){
                int m;cin>>m;
                vl b(m);
                for(int i=0;i<m;i++)cin>>b[i];
                if(sz(a)==0)continue;
                vl nxt(sz(a)+m-1,0);
                for(int i=0;i<sz(a);i++){
                    for(int j=0;j<m;j++){
                        nxt[i+j]=(nxt[i+j]+a[i]*b[j])%p;
                    }
                }
                a=nxt;
            }else if(type=='Q'){
                ll t;cin>>t;t^=last_ans;
                ll ans=0;
                if(t<sz(a))ans=(a[t]*f[t])%p;
                cout<<ans<<el;
                last_ans=ans;
            }
        }

    }
}
inline void solve() {
    sub3::sol();
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
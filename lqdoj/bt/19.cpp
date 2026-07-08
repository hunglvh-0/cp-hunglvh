/**
 * Author:  hunglvh
 * Created: 2026-07-08 7:34:44
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
namespace sub4{
    void solve(){
        int t,k;cin>>t>>k;
        vector<ll>a(t);arr(a,t);
        ll md=1;
        for(int i=0;i<k;i++)md*=10;
        vector<ll>p(md,1);
        for(int i=1;i<md;i++){
            p[i]=p[i-1];
            if(i%2!=0 and i%5!=0)p[i]=(p[i]*i)%md;
        }
        for(int i=0;i<t;i++){
            ll n=a[i],c2=0,c5=0,t2=n,t5=n,ans=1;
            while(t2>0){
                c2+=t2/2;
                t2/=2;
            }
            while(t5>0){
                c5+=t5/5;
                t5/=5;
            }
            ll p2=1;
            while(p2<=n){
                ll p5=1;
                while(p2*p5<=n){
                    ll v=n/(p2*p5),bl=v/md,rm=v%md;
                    ans=(ans*pow_mod(p[md-1],bl,md))%md;
                    ans=(ans*p[rm])%md;
                    if(n/5<p5)break;
                    p5*=5;
                }
                if(n/2<p2)break;
                p2*=2;
            }
            ans=(ans*pow_mod(2,c2-c5,md))%md;
            string s=to_string(ans);
            while(sz(s)<k){
                s="0"+s;
            }
            cout<<s<<" ";
        }
    }
}
inline void solve() {
    sub4::solve();
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
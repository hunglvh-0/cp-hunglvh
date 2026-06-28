/**
 * Author:  hunglvh
 * Created: 2026-06-28 19:05:47
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
        ll n,K;cin>>n>>K;
        vl a(n);
        arr(a,n);
        ll md=998244353;
        vl fact(n+1,1),inv(n+1,1);
        for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%md;
        inv[n]=pow_mod(fact[n],md-2,md);
        for(int i=n-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%md;
        auto C=[&](int x,int y)->ll{
            if(y<0 or y>x)return 0;
            return fact[x]*inv[y]%md*inv[x-y]%md;
        };
        ll ans=1;
        for(int i=0;i<n;){
            int j=i;
            ll rem=a[i]%K;
            ll g=min(rem,(K-rem)%K);
            while(j<n){
                ll r2=a[j]%K;
                ll g2=min(r2,(K-r2)%K);
                if(g2==g)j++;
                else break;
            }
            ll L=j-i;
            if(g==0 or g*2==K){
                map<ll,ll>mp;
                for(int k=i;k<j;k++)mp[a[k]]++;
                ll ways=fact[L];
                for(auto p:mp)ways=ways*inv[p.s]%md;
                ans=ans*ways%md;
            }else{
                int cnt=0;
                for(int k=i;k<j;k++)if(a[k]%K==g)cnt++;
                ans=ans*C(L,cnt)%md;
            }
            i=j;
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
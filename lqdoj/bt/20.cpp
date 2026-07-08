/**
 * Author:  hunglvh
 * Created: 2026-07-08 14:22:42
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
        int ms=144;
        vi off(ms+2,0);
        for(int s=1;s<=ms;s++)off[s+1]=off[s]+17*(s+1)*s;
        vl dp(off[ms+1],0);
        vvi p10(ms+1,vi(17,1));
        for(int s=1;s<=ms;s++){
            for(int i=1;i<=16;i++){
                p10[s][i]=(p10[s][i-1]*10)%s;
            }
        }
        for(int s=1;s<=ms;s++){
            dp[off[s]]=1;
            for(int i=0;i<16;i++){
                for(int sum=0;sum<=s;sum++){
                    for(int r=0;r<s;r++){
                        ll v=dp[off[s]+i*(s+1)*s+sum*s+r];
                        if(!v)continue;
                        for(int d=0;d<=9;d++){
                            int ns=sum+d;
                            if(ns>s)break;
                            int nr=(r+d*p10[s][i])%s;
                            dp[off[s]+(i+1)*(s+1)*s+ns*s+nr]+=v;
                        }
                    }
                }
            }
        }
        auto cnt=[&](ll m)->ll{
            if(m==0)return 0;
            vi sm(16,0);
            for(int i=15;i>=0;i--){
                sm[i]=m%10;
                m/=10;
            }
            ll tot=0;
            for(int s=1;s<=ms;s++){
                int cs=0,cr=0;
                for(int i=0;i<16;i++){
                    int D=sm[i];
                    for(int d=0;d<D;d++){
                        if(cs+d>s)break;
                        int rs=s-(cs+d);
                        int rl=15-i;
                        int rr=(s-((cr*10+d)%s*p10[s][rl])%s)%s;
                        tot+=dp[off[s]+rl*(s+1)*s+rs*s+rr];
                    }
                    cs+=D;
                    cr=(cr*10+D)%s;
                }
                if(cs==s and cr==0)tot++;
            }
            return tot;
        };
        int t;cin>>t;
        while(t--){
            ll x,k;cin>>x>>k;
            ll b=cnt(x);
            ll l=x+1,r=1e16-1,ans=-1;
            while(l<=r){
                ll mid=(l+r)/2;
                if(cnt(mid)-b>=k){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            cout<<ans<<el;
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
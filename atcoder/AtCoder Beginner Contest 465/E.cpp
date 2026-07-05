/**
 * Author:  hunglvh
 * Created: 2026-07-04 19:36:42
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
string S;
int dp[505][2][2][3][2][1024];
int md=998244353;

int calc(int p,int l,int st,int m3,int h3,int mk){
    if(p==sz(S)){
        if(!st)return 0;
        int c1=(m3==0);int c2=h3;int c3=(__builtin_popcount(mk)==3);
        if(c1+c2+c3==1)return 1;return 0;
    }
    if(dp[p][l][st][m3][h3][mk]!=-1)return dp[p][l][st][m3][h3][mk];
    int r=0;int lim=l?9:(S[p]-'0');
    for(int d=0;d<=lim;d++){
        int nl=l or(d<lim);int nst=st or(d>0);int nm3=(m3+d)%3;
        int nh3=h3 or(d==3);int nmk=nst?(mk|(1<<d)):0;
        r=(r+calc(p+1,nl,nst,nm3,nh3,nmk))%md;
    }
    return dp[p][l][st][m3][h3][mk]=r;
}

inline void solve() {
    cin>>S;
    memset(dp,-1,sizeof(dp));
    int ans=calc(0,0,0,0,0,0);
    cout<<ans<<el;
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
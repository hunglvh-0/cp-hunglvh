/**
 * Author:  hunglvh
 * Created: 2026-07-18 22:02:41
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
int N;
vi mn_t,mx_t,isb_t,bad_t,lvl_t;
void build_tree(int n,vi&a){
    N=1;
    while(N<n){
        N<<=1;
    }
    int I=2000000007;
    mn_t.assign(2*N,I);
    mx_t.assign(2*N,-I);
    isb_t.assign(2*N,0);
    bad_t.assign(26,0);
    lvl_t.assign(2*N,0);
    for(int i=0;i<n;i++){
        mn_t[N+i]=a[i];
        mx_t[N+i]=a[i];
    }
    for(int i=N-1;i>=1;i--){
        lvl_t[i]=lvl_t[2*i]+1;
        mn_t[i]=min(mn_t[2*i],mn_t[2*i+1]);
        mx_t[i]=max(mx_t[2*i],mx_t[2*i+1]);
        if(mx_t[2*i]>mn_t[2*i+1]){
            isb_t[i]=1;
        }else{
            isb_t[i]=0;
        }
        bad_t[lvl_t[i]]+=isb_t[i];
    }
}

void update_tree(int idx,int v){
    int p=N+idx;
    mn_t[p]=v;
    mx_t[p]=v;
    p/=2;
    while(p>=1){
        bad_t[lvl_t[p]]-=isb_t[p];
        mn_t[p]=min(mn_t[2*p],mn_t[2*p+1]);
        mx_t[p]=max(mx_t[2*p],mx_t[2*p+1]);
        if(mx_t[2*p]>mn_t[2*p+1]){
            isb_t[p]=1;
        }else{
            isb_t[p]=0;
        }
        bad_t[lvl_t[p]]+=isb_t[p];
        p/=2;
    }
}

int get_ans(){
    int ans=0;
    for(int l=25;l>=1;l--){
        if(bad_t[l]>0){
            ans=(1<<(l-1));
            break;
        }
    }
    return ans;
}
inline void solve() {
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vi a(n);arr(a,n);
        build_tree(n,a);
        int ans=get_ans();
        cout<<ans<<el;
        while(q--){
            int idx,v;cin>>idx>>v;
            update_tree(idx,v);
            ans=get_ans();
            cout<<ans<<el;
        }
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
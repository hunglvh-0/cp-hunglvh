/**
 * Author:  hunglvh
 * Created: 2026-07-11 08:14:46
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
int m,n,q;
vector<vector<int>>a(5,vector<int>(50005));
vector<vector<vector<int>>>val(5,vector<vector<int>>(5,vector<int>(50005)));
vector<multiset<int>>ms(5);

int get_val(int k,int r,int c){
    int mx=-1,mn=1e9+7;
    for(int i=r;i<r+k;i++){
        for(int j=c;j<c+k;j++){
            mx=max(mx,a[i][j]);
            mn=min(mn,a[i][j]);
        }
    }
    return mx-mn;
}
void del(int i,int j){
    for(int k=2;k<=min(m,n);k++){
        for(int r=max(1,i-k+1);r<=min(m-k+1,i);r++){
            for(int c=max(1,j-k+1);c<=min(n-k+1,j);c++){
                ms[k].erase(ms[k].find(val[k][r][c]));
            }
        }
    }
}
void add(int i,int j){
    for(int k=2;k<=min(m,n);k++){
        for(int r=max(1,i-k+1);r<=min(m-k+1,i);r++){
            for(int c=max(1,j-k+1);c<=min(n-k+1,j);c++){
                val[k][r][c]=get_val(k,r,c);
                ms[k].insert(val[k][r][c]);
            }
        }
    }
}
inline void solve() {
    cin>>m>>n>>q;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int k=2;k<=min(m,n);k++){
        for(int r=1;r<=m-k+1;r++){
            for(int c=1;c<=n-k+1;c++){
                val[k][r][c]=get_val(k,r,c);
                ms[k].insert(val[k][r][c]);
            }
        }
    }
    while(q--){
        int type;cin>>type;
        if(type==1){
            int i,j,x;cin>>i>>j>>x;
            del(i,j);
            a[i][j]=x;
            add(i,j);
        }else{
            int t;cin>>t;
            int ans=1;
            for(int k=min(m,n);k>=2;k--){
                if(!ms[k].empty()and(*ms[k].begin()<=t)){
                    ans=k;
                    break;
                }
            }
            cout<<ans<<el;
        }
    }
}
int32_t main() {
    fast;
    #define file "khuvuonanhsang"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
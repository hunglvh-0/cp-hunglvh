/**
 * Author:  hunglvh
 * Created: 2026-07-11 07:36:17
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
// void pri(i128 x){
//     if(x<0){cout<<"-";x=-x;}
//     if(x>9)pri(x/10);
//     cout<<(char)(x%10+'0');
// }
// struct H{
//     size_t operator()(pii const&p)const{
//         return hash<ll>()(((ll)p.f<<32)|((ll)p.s&0xFFFFFFFFLL));
//     }
// };
struct D{
    int x,y,id;
    i128 sm;
    bool operator<(const D&o)const{
        if(x!=o.x)return x<o.x;
        if(y!=o.y)return y<o.y;
        return id<o.id;
    }
};
inline void solve() {
    int n;cin>>n;
    vi t(n);for(int i=0;i<n;i++)cin>>t[i];
    vl a(n);for(int i=0;i<n;i++)cin>>a[i];
    vector<D>v;
    v.pb({0,0,0,0});
    int c0=0,c1=0,c2=0;
    i128 sm=0;
    for(int i=0;i<n;i++){
        if(t[i]==0)c0++;
        else if(t[i]==1)c1++;
        else c2++;
        sm+=a[i];
        v.pb({c0-c1,c1-c2,i+1,sm});
    }
    sort(all(v));
    i128 ans=0;
    bool ok=0;
    for(int i=0;i<sz(v);i++){
        int j=i;
        i128 mi=v[i].sm;
        while(j+1<sz(v)and v[j+1].x==v[i].x and v[j+1].y==v[i].y){
            j++;
            i128 val=v[j].sm-mi;
            if(!ok or val>ans){
                ans=val;
                ok=1;
            }
            if(v[j].sm<mi)mi=v[j].sm;
        }
        i=j;
    }
    if(!ok)cout<<"KHONG"<<el;
    else{
        if(ans<0){
            cout<<"-";
            ans=-ans;
        }
        if(ans==0)cout<<0<<el;
        else{
            string s="";
            while(ans>0){
                s+=(char)(ans%10+'0');
                ans/=10;
            }
            reverse(all(s));
            cout<<s<<el;
        }
    }
}
int32_t main() {
    fast;
    #define file "thatthach"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
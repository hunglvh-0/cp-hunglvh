/**
 * Author:  hunglvh
 * Created: 2026-07-13 10:29:18
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
const int MAXN=200005;
ll E[MAXN];
char B[MAXN];
struct Node{
    ll sum_e;
    ll left_e;
    ll right_e;
    char left_b;
    char right_b;
    ll pen;
}st[4*MAXN];
void pull(int id){
    st[id].sum_e=st[2*id].sum_e+st[2*id+1].sum_e;
    st[id].left_e=st[2*id].left_e;
    st[id].right_e=st[2*id+1].right_e;
    st[id].left_b=st[2*id].left_b;
    st[id].right_b=st[2*id+1].right_b;
    st[id].pen=st[2*id].pen+st[2*id+1].pen;
    if(st[2*id].right_b==st[2*id+1].left_b){
        st[id].pen+=min(st[2*id].right_e,st[2*id+1].left_e);
    }
}
void build(int id,int l,int r){
    if(l==r){
        st[id].sum_e=E[l];
        st[id].left_e=E[l];
        st[id].right_e=E[l];
        st[id].left_b=B[l];
        st[id].right_b=B[l];
        st[id].pen=0;
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    pull(id);
}
void upd_e(int id,int l,int r,int p,ll v){
    if(l==r){
        st[id].sum_e=v;
        st[id].left_e=v;
        st[id].right_e=v;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid){
        upd_e(2*id,l,mid,p,v);
    }
    if(p>mid){
        upd_e(2*id+1,mid+1,r,p,v);
    }
    pull(id);
}
void upd_b(int id,int l,int r,int p,char c){
    if(l==r){
        st[id].left_b=c;
        st[id].right_b=c;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid){
        upd_b(2*id,l,mid,p,c);
    }
    if(p>mid){
        upd_b(2*id+1,mid+1,r,p,c);
    }
    pull(id);
}
Node query(int id,int l,int r,int u,int v){
    if(l>v or r<u){
        return {0,0,0,0,0,0};
    }
    if(l>=u and r<=v){
        return st[id];
    }
    int mid=(l+r)/2;
    Node L=query(2*id,l,mid,u,v);
    Node R=query(2*id+1,mid+1,r,u,v);
    if(L.left_b==0){
        return R;
    }
    if(R.left_b==0){
        return L;
    }
    Node res;
    res.sum_e=L.sum_e+R.sum_e;
    res.left_e=L.left_e;
    res.right_e=R.right_e;
    res.left_b=L.left_b;
    res.right_b=R.right_b;
    res.pen=L.pen+R.pen;
    if(L.right_b==R.left_b){
        res.pen+=min(L.right_e,R.left_e);
    }
    return res;
}

inline void solve(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        ll l;cin>>l>>E[i]>>B[i];
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(t==1){
            int p;ll v;cin>>p>>v;
            upd_e(1,1,n,p,v);
        }
        if(t==2){
            int p;char c;cin>>p>>c;
            upd_b(1,1,n,p,c);
        }
        if(t==3){
            int u,v;cin>>u>>v;
            Node res=query(1,1,n,u,v);
            ll ans=res.sum_e-res.pen;
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
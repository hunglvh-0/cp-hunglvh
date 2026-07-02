/**
 * Author:  hunglvh
 * Created: 2026-07-02 10:29:07
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
//seg tree :((
//plsss no rte
struct Node{
    ll p[3],s[3],a,sm;
    bool c;
    int lp;
    int rp;
};
vector<Node>t(800005);
Node nul;
Node mg(Node l, Node r){
    if(l.lp==-1)return r;
    if(r.lp==-1)return l;
    Node x;x.lp=l.lp;
    x.rp=r.rp;
    x.c=(l.c and r.c and (l.rp!=r.lp));
    x.sm = x.c?(l.sm+r.sm):-INF;
    for(int i=0;i<3;i++){
        x.p[i]=l.p[i];
        x.s[i]=r.s[i];
    }
    if(l.c and (l.rp!=r.lp)){
        for(int i=0;i<3;i++){
            if(r.p[i]!=-INF){
                ll v=l.sm+r.p[i];
                x.p[(v%3+3)%3]=max(x.p[(v%3+3)%3],v);
            }
        }
    }
    if(r.c and (l.rp!= r.lp)){
        for(int i=0;i<3;i++){
            if(l.s[i]!=-INF){
                ll v=r.sm+l.s[i];
                x.s[(v%3+3)%3]=max(x.s[(v%3+3)%3],v);
            }
        }
    }
    x.a=max(l.a,r.a);
    if(l.rp!=r.lp){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(l.s[i]!=-INF and r.p[j]!=-INF){
                    ll v=l.s[i]+r.p[j];
                    if((v%3+3)%3==0){
                        x.a=max(x.a,v);
                    }
                }
            }
        }
    }
    return x;
}
void bd(int id,int l,int r,vector<ll>&arr){
    if(l==r){
        t[id].lp=t[id].rp=abs(arr[l]%2);
        t[id].c=true;
        t[id].sm=arr[l];
        for(int i=0;i<3;i++){
            t[id].p[i]=t[id].s[i]=-INF;
        }
        t[id].p[(arr[l]%3+3)%3]=arr[l];
        t[id].s[(arr[l]%3+3)%3]=arr[l];
        t[id].a=(arr[l]%3==0)?arr[l]:-INF;
        return;
    }
    int m=(l+r)/2;
    bd(id*2,l,m,arr);
    bd(id*2+1,m+1,r,arr);
    t[id]=mg(t[id*2],t[id*2+1]);
}
void up(int id,int l,int r,int pos,ll val){
    if(l==r){
        t[id].lp=t[id].rp=abs(val)%2;
        t[id].c=true;
        t[id].sm=val;
        for(int i=0;i<3;i++){
            t[id].p[i]=t[id].s[i]=-INF;
        }
        t[id].p[(val%3+3)%3]=val;
        t[id].s[(val%3+3)%3]=val;
        t[id].a=(val%3==0)?val:-INF;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m){
        up(id*2,l,m,pos,val);
    }
    else{
        up(id*2+1,m+1,r,pos,val);
    }
    t[id]=mg(t[id*2],t[id*2+1]);
}
Node get(int id,int l,int r,int ql,int qr){
    if(l>qr or r<ql)return nul;
    if(ql<=l and r<=qr)return t[id];
    int m=(l+r)/2;
    return mg(get(id*2,l,m,ql,qr),get(id*2+1,m+1,r,ql,qr));
}
inline void solve() {
    nul.lp=-1;
    int n,q;cin>>n>>q;
    vl a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    bd(1,1,n,a);
    while(q--){
        int type;cin>>type;
        if(type==1){
            int x;ll y;cin>>x>>y;
            up(1,1,n,x,y);
        }
        else{
            int l,r;cin>>l>>r;
            Node res=get(1,1,n,l,r);
            ll ans=res.a;
            cout<<(ans==-INF?0:ans)<<el;
        }
    }
}
int32_t main() {
    fast;
    #define file "prbc"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
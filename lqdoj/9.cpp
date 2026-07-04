/**
 * Author:  hunglvh
 * Created: 2026-07-04 17:54:58
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
struct Node{
    int mn,mx,ans;
    ll cnt;
    int lmn,rmn,lmx,rmx;
};
Node t[800005];
int ar[200005];
Node mrg(Node x,Node y){
    if(x.mn==-1)return y;
    if(y.mn==-1)return x;
    Node z;
    z.mn=min(x.mn,y.mn);
    z.mx=max(x.mx,y.mx);
    z.ans=1e9;z.cnt=0;
    z.lmn=-1;z.rmn=-1;z.lmx=-1;z.rmx=-1;
    if(x.mn==z.mn)z.lmn=(z.lmn==-1?x.lmn:z.lmn),z.rmn=x.rmn;
    if(y.mn==z.mn)z.lmn=(z.lmn==-1?y.lmn:z.lmn),z.rmn=y.rmn;
    if(x.mx==z.mx)z.lmx=(z.lmx==-1?x.lmx:z.lmx),z.rmx=x.rmx;
    if(y.mx==z.mx)z.lmx=(z.lmx==-1?y.lmx:z.lmx),z.rmx=y.rmx;
    if(z.mn==z.mx){
        z.ans=1;
        z.cnt=(x.mn==z.mn?x.cnt:0)+(y.mn==z.mn?y.cnt:0);
        return z;
    }
    if(x.mn==z.mn and x.mx==z.mx){
        if(x.ans<z.ans)z.ans=x.ans,z.cnt=x.cnt;
        else if(x.ans==z.ans)z.cnt+=x.cnt;
    }
    if(y.mn==z.mn and y.mx==z.mx){
        if(y.ans<z.ans)z.ans=y.ans,z.cnt=y.cnt;
        else if(y.ans==z.ans)z.cnt+=y.cnt;
    }
    if(x.rmn!=-1 and x.mn==z.mn and y.lmx!=-1 and y.mx==z.mx){
        int d=y.lmx-x.rmn+1;
        if(d<z.ans)z.ans=d,z.cnt=1;
        else if(d==z.ans)z.cnt++;
    }
    if(x.rmx!=-1 and x.mx==z.mx and y.lmn!=-1 and y.mn==z.mn){
        int d=y.lmn-x.rmx+1;
        if(d<z.ans)z.ans=d,z.cnt=1;
        else if(d==z.ans)z.cnt++;
    }
    return z;
}
void bd(int id,int l,int r){
    if(l==r){
        t[id].mn=ar[l];t[id].mx=ar[l];
        t[id].ans=1;t[id].cnt=1;
        t[id].lmn=l;t[id].rmn=l;t[id].lmx=l;t[id].rmx=l;
        return;
    }
    int m=(l+r)/2;
    bd(id*2,l,m);bd(id*2+1,m+1,r);
    t[id]=mrg(t[id*2],t[id*2+1]);
}
void up(int id,int l,int r,int p,int v){
    if(l==r){
        t[id].mn=v;t[id].mx=v;
        return;
    }
    int m=(l+r)/2;
    if(p<=m)up(id*2,l,m,p,v);
    else up(id*2+1,m+1,r,p,v);
    t[id]=mrg(t[id*2],t[id*2+1]);
}
Node get(int id,int l,int r,int u,int v){
    if(u>r or v<l){
        Node tmp;tmp.mn=-1;return tmp;
    }
    if(u<=l and r<=v)return t[id];
    int m=(l+r)/2;
    return mrg(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
inline void solve() {
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>ar[i];
    bd(1,1,n);
    while(q--){
        int ty;cin>>ty;
        if(ty==1){
            int p,x;cin>>p>>x;
            up(1,1,n,p,x);
        }else{
            int l,r;cin>>l>>r;
            Node ans=get(1,1,n,l,r);
            cout<<ans.ans<<" "<<ans.cnt<<el;
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
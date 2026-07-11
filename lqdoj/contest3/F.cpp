/**
 * Author:  hunglvh
 * Created: 2026-07-11 06:51:48
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
vl a(5005);
ll calc(int l,int r){
    if(l>r)return 0;
    if(l==r)return 1;
    int mid=(l+r)/2;
    ll res=calc(l,mid)+calc(mid+1,r);
    vl mxL(r+2,0),mnL(r+2,INF);
    vl mxR(r+2,0),mnR(r+2,INF);
    mxL[mid]=mnL[mid]=a[mid];
    for(int i=mid-1;i>=l;i--){
        mxL[i]=max(mxL[i+1],a[i]);
        mnL[i]=min(mnL[i+1],a[i]);
    }
    if(mid+1<=r){
        mxR[mid+1]=mnR[mid+1]=a[mid+1];
        for(int i=mid+2;i<=r;i++){
            mxR[i]=max(mxR[i-1],a[i]);
            mnR[i]=min(mnR[i-1],a[i]);
        }
    }
    for(int i=l;i<=mid;i++){
        ll j=mxL[i]-mnL[i]+i;
        if(j>=mid+1 and j<=r){
            if(mxL[i]>=mxR[j] and mnL[i]<=mnR[j])res++;
        }
    }
    for(int j=mid+1;j<=r;j++){
        ll i=j-(mxR[j]-mnR[j]);
        if(i>=l and i<=mid){
            if(mxL[i]<mxR[j] and mnL[i]>mnR[j])res++;
        }
    }
    map<ll,vi>mp3,mp4;
    for(int j=mid+1;j<=r;j++){
        mp3[mnR[j]+j].pb(j);
        mp4[mxR[j]-j].pb(j);
    }
    for(int i=l;i<=mid;i++){
        int R1=mid;
        int low=mid+1,high=r;
        while(low<=high){
            int m=(low+high)/2;
            if(mxR[m]<=mxL[i]){R1=m;low=m+1;}
            else high=m-1;
        }
        int L1=r+1;
        low=mid+1,high=r;
        while(low<=high){
            int m=(low+high)/2;
            if(mnR[m]<mnL[i]){L1=m;high=m-1;}
            else low=m+1;
        }
        if(L1<=R1){
            ll target=mxL[i]+i;
            if(mp3.count(target)){
                res+=upper_bound(all(mp3[target]),R1)-lower_bound(all(mp3[target]),L1);
            }
        }
    }
    for(int i=l;i<=mid;i++){
        int L2=r+1;
        int low=mid+1,high=r;
        while(low<=high){
            int m=(low+high)/2;
            if(mxR[m]>mxL[i]){L2=m;high=m-1;}
            else low=m+1;
        }
        int R2=mid;
        low=mid+1,high=r;
        while(low<=high){
            int m=(low+high)/2;
            if(mnR[m]>=mnL[i]){R2=m;low=m+1;}
            else high=m-1;
        }
        if(L2<=R2){
            ll target=mnL[i]-i;
            if(mp4.count(target)){
                res+=upper_bound(all(mp4[target]),R2)-lower_bound(all(mp4[target]),L2);
            }
        }
    }
    return res;
}
inline void solve() {
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(q--){
        int t;cin>>t;
        if(t==1){
            int p;ll x;cin>>p>>x;
            a[p]=x;
        }else{
            int l,r;cin>>l>>r;
            ll ans=calc(l,r);
            cout<<ans<<el;
        }
    }
}
int32_t main() {
    fast;
    #define file "domino"
    if(fopen(file".INP","r")) {
        freopen(file".INP","r",stdin);
        freopen(file".OUT","w",stdout);
    }
    solve();
    return 0;
}
/**
 * Author:  hunglvh
 * Created: 2026-05-16 21:35:53
 * ❤️chau
**/
#include<bits/stdc++.h>

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
namespace sub1{
    void solve(){
        int n;cin>>n;
        map<pii,int>M;
        for(int i=1;i<=n;i++){
            M[{i,i}]=i;
        }
        vector<pii>vr;
        for(int len=2;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                cout<<"?"<<" "<<i<<" "<<j<<endl;
                int f;cin>>f;
                if(f==1){
                    vr.pb({i,j});
                }
            }
        }
        int nxt=n+1;
            vector<pii>ch(2*n);
            for(auto&p:vr){
                int l=p.f,r=p.s;
                for(int m=l;m<r;m++){
                    if((M.count({l,m})) and (M.count({m+1,r}))){
                        int id=nxt++;
                        M[{l,r}]=id;
                        ch[id]={M[{l,m}],M[{m+1,r}]};
                        break;
                    }
                }
            }
            cout<<"!";
            // for(int i=n+1;i<2*n-1;i++){
            //     cout<<" "<<ch[i].f<<" "<<ch[i].s;
            // }
            // cout<<endl;
            int limit=2*n;
            for(int i=n+1;i<limit;i++){
                cout<<" "<<ch[i].f<<" "<<ch[i].s;
            }
            cout<<endl;
    }
}
//gg
namespace sub2{
    void solve(){
        int n;cin>>n;
        vi st;st.pb(1);
        int nxt=n+1;
        map<int,pii> ans;
        for(int i=2;i<=n;i++){
            cout<<"?"<<" "<<1<<" "<<i<<endl;
            int f;cin>>f;
            int c=sz(st)+1-f;
            if(c>0){
                vi p;
                for(int j=0;j<c;j++){
                    p.pb(st.back());
                    st.pop_back();
                }
                int curr=i;
                for(int j=0;j<c;j++){
                    int id=nxt++;
                    ans[id]={p[j],curr};
                    curr=id;
                }
                st.pb(curr);
            }else{
                st.pb(i);
            }

        }
        cout<<"!";
            int limit=2*n;
            for(int i=n+1;i<limit;i++){
                int idx=i;
                cout<<" "<<ans[idx].f<<" "<<ans[idx].s;
            }
            cout<<endl;
    }
}
void solve() {
    int t;cin>>t;
    while(t--){
        sub2::solve();
    }
}
int32_t main() {
    fast;
    // #define file "main"
    // if(fopen(file".INP","r")) {
    //     freopen(file".INP","r",stdin);
    //     freopen(file".OUT","w",stdout);
    // }
    solve();
    return 0;
}
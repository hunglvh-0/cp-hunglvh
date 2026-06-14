/**
 * Author:  hunglvh
 * Created: 2026-06-14 20:12:07
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
inline void solve() {
    int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<vector<ll>>a(n+1,vector<ll>(n+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		auto valid=[&](int r,int c){
			return(r>=1)and(r<=n)and(c>=1)and(c<=n);
		};
		auto id=[&](int r,int c){
			return(r-1)*n+c;
		};
		vector<vector<pair<int,int>>>adjL(n*n+1),adjR(n*n+1);
		for(int r=1;r<=n;r++){
			for(int c=1;c<=n;c++){
				int u=id(r,c);
				if(c>1){
					if(valid(r-1,c-1))adjL[u].pb({r-1,c-1});
					if(valid(r+1,c-1))adjL[u].pb({r+1,c-1});
					if(valid(r,c-2))adjL[u].pb({r,c-2});
				}else{
					if(valid(r-1,c+1))adjL[u].pb({r-1,c+1});
					if(valid(r+1,c+1))adjL[u].pb({r+1,c+1});
					if(valid(r,c+2))adjL[u].pb({r,c+2});
				}
				if(c<n){
					if(valid(r-1,c+1))adjR[u].pb({r-1,c+1});
					if(valid(r+1,c+1))adjR[u].pb({r+1,c+1});
					if(valid(r,c+2))adjR[u].pb({r,c+2});
				}else{
					if(valid(r-1,c-1))adjR[u].pb({r-1,c-1});
					if(valid(r+1,c-1))adjR[u].pb({r+1,c-1});
					if(valid(r,c-2))adjR[u].pb({r,c-2});
				}
			}
		}
		vector<bool>inL(n*n+1,false),inR(n*n+1,false);
		queue<int>qL,qR;
		for(int r=1;r<=n;r++){
			qL.push(id(r,1));inL[id(r,1)]=true;
			qR.push(id(r,n));inR[id(r,n)]=true;
		}
		while(!qL.empty()){
			int u=qL.front();qL.pop();
			for(auto&v:adjL[u]){
				int vid=id(v.f,v.s);
				if(!inL[vid]){
					inL[vid]=true;qL.push(vid);
				}
			}
		}
		while(!qR.empty()){
			int u=qR.front();qR.pop();
			for(auto&v:adjR[u]){
				int vid=id(v.f,v.s);
				if(!inR[vid]){
					inR[vid]=true;qR.push(vid);
				}
			}
		}
		ll sumL[2]={0,0},sumR[2]={0,0};
		vector<vector<vector<ll>>>prefL(2,vector<vector<ll>>(2*n+3,vector<ll>(2*n+3,0)));
		vector<vector<vector<ll>>>sufR(2,vector<vector<ll>>(2*n+3,vector<ll>(2*n+3,0)));
		for(int r=1;r<=n;r++){
			for(int c=1;c<=n;c++){
				int p=(r+c)%2;
				int X=r+c;
				int Y=c-r+n;
				if(inL[id(r,c)])sumL[p]+=a[r][c];
				else{prefL[p][X][Y]=a[r][c];}
				if(inR[id(r,c)])sumR[p]+=a[r][c];
				else{sufR[p][X][Y]=a[r][c];}
			}
		}
		for(int p=0;p<2;p++){
			for(int x=1;x<=2*n;x++){
				for(int y=1;y<=2*n;y++){
					prefL[p][x][y]+=prefL[p][x-1][y]+prefL[p][x][y-1]-prefL[p][x-1][y-1];
				}
			}
			for(int x=2*n;x>=1;x--){
				for(int y=2*n;y>=1;y--){
					sufR[p][x][y]+=sufR[p][x+1][y]+sufR[p][x][y+1]-sufR[p][x+1][y+1];
				}
			}
		}
		for(int r=1;r<=n;r++){
			for(int c=1;c<=n;c++){
				int p=(r+c)%2;
				int X=r+c;
				int Y=c-r+n;
				ll ansL=sumL[p]+prefL[p][X][Y];
				ll ansR=sumR[p]+sufR[p][X][Y];
				ll ans=min(ansL,ansR);
				if(c<n){cout<<ans<<char(32);}
				else{cout<<ans<<"\n";}
			}
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
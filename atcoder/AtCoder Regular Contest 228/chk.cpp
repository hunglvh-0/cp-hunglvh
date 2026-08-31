
#include <iostream>
#include <vector>
using namespace std;
#define sz(x) (int)(x).size()
#define vl vector<long long>
#define vvl vector<vl>
const long long MOD = 998244353;
long long pow_mod(long long a, long long b) {
    long long res = 1; a %= MOD;
    while(b > 0) { if(b&1) res=(res*a)%MOD; a=(a*a)%MOD; b>>=1; }
    return res;
}
vvl multiply(vvl p1,vvl p2) {
    int a1=sz(p1), b1=sz(p1[0]), a2=sz(p2), b2=sz(p2[0]);
    vvl res(a1+a2-1,vl(b1+b2-1,0));
    for(int i=0;i<a1;i++) for(int j=0;j<b1;j++) if(p1[i][j])
        for(int k=0;k<a2;k++) for(int l=0;l<b2;l++)
            res[i+k][j+l]=(res[i+k][j+l]+p1[i][j]*p2[k][l])%MOD;
    return res;
}
vvl getpoly(int len) {
    vvl pol(len/2+1,vl(len+1,0));
    for(int fx=0;fx<=1;fx++) {
        vector<vector<vector<long long>>> dp(len/2+1,vector<vector<long long>>(len+1,vector<long long>(2,0)));
        dp[0][0][fx]=1;
        for(int i=1;i<len;i++) {
            vector<vector<vector<long long>>> nxt(len/2+1,vector<vector<long long>>(len+1,vector<long long>(2,0)));
            for(int a=0;a<=len/2;a++) for(int b=0;b<=i;b++) for(int lx=0;lx<=1;lx++) {
                long long w=dp[a][b][lx]; if(!w) continue;
                if(lx==0) { if(b+1<=len) nxt[a][b+1][0]=(nxt[a][b+1][0]+w)%MOD; }
                else { if(a+1<=len/2) nxt[a+1][b][0]=(nxt[a+1][b][0]+w)%MOD; }
                nxt[a][b][1]=(nxt[a][b][1]+w)%MOD;
            }
            dp=nxt;
        }
        for(int a=0;a<=len/2;a++) for(int b=0;b<=len;b++) for(int lx=0;lx<=1;lx++) {
            long long w=dp[a][b][lx]; if(!w) continue;
            int na=a, nb=b;
            if(lx==0 && fx==0) nb++;
            if(lx==1 && fx==0) na++;
            if(na<=len/2 && nb<=len) pol[na][nb]=(pol[na][nb]+w)%MOD;
        }
    }
    return pol;
}
int main() {
    int n = 8, m = 15;
    vvl tot={{1}};
    tot = multiply(tot, getpoly(4));
    tot = multiply(tot, getpoly(2));
    tot = multiply(tot, getpoly(2));
    
    vl f(2*n+1,1), inv(2*n+1,1);
    for(int i=1;i<=2*n;i++) f[i]=(f[i-1]*i)%MOD;
    inv[2*n]=pow_mod(f[2*n],MOD-2);
    for(int i=2*n-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%MOD;
    
    vvl w(n/2+1,vl(n+1,0));
    w[0][n]=1;
    for(int stp=1;stp<=m;stp++) {
        vvl nw(n/2+1,vl(n+1,0));
        for(int a=0;a<=n/2;a++) {
            for(int b=0;b<=n;b++) {
                long long cur=w[a][b]; if(!cur) continue;
                int c=n-2*a-b; if(c<0) continue;
                long long slf=(1LL*n*n-2LL*a*a-2LL*b*c-b-c)%MOD;
                if(slf<0) slf+=MOD;
                nw[a][b]=(nw[a][b]+cur*slf)%MOD;
                if(a>=1 && b+1<=n) nw[a-1][b+1]=(nw[a-1][b+1]+cur*((2LL*a*a)%MOD))%MOD;
                if(a+1<=n/2 && b>=1) nw[a+1][b-1]=(nw[a+1][b-1]+cur*((2LL*b*c)%MOD))%MOD;
                if(b>=1) nw[a][b-1]=(nw[a][b-1]+cur*b)%MOD;
                if(b+1<=n) nw[a][b+1]=(nw[a][b+1]+cur*c)%MOD;
            }
        }
        w=nw;
    }
    long long ans = 0;
    for(int a=0;a<=n/2;a++) {
        for(int b=0;b<=n;b++) {
            if(!tot[a][b]) continue;
            int c=n-2*a-b; if(c<0) continue;
            int d=a;
            long long num=f[n];
            num=(num*inv[a])%MOD; num=(num*inv[b])%MOD; num=(num*inv[c])%MOD; num=(num*inv[d])%MOD;
            long long pm=w[a][b];
            long long inm=pow_mod(num,MOD-2);
            pm=(pm*inm)%MOD;
            long long term=(tot[a][b]*pm)%MOD;
            ans=(ans+term)%MOD;
        }
    }
    cout << ans << endl;
}


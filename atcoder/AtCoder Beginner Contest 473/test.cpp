#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define sz(x) (int)(x).size()

const ll md=998244353;
const ll root=62;
ll pow_mod(ll a, ll b, ll m=md){ll res=1;a%=m;while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b>>=1;}return res;}

void ntt(vl&a){
    int n=sz(a),lg=31-__builtin_clz(n);
    static vl rt(2,1);
    for(static int k=2,s=2;k<n;k*=2,s++){
        rt.resize(n);
        ll z[]={1,pow_mod(root,md>>s,md)};
        for(int i=k;i<2*k;i++)rt[i]=rt[i/2]*z[i&1]%md;
    }
    vi rev(n);
    for(int i=0;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<lg)/2;
    for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int k=1;k<n;k*=2){
        for(int i=0;i<n;i+=2*k){
            for(int j=0;j<k;j++){
                ll z=rt[j+k]*a[i+j+k]%md,&ai=a[i+j];
                a[i+j+k]=ai-z+(z>ai?md:0);
                ai+=(ai+z>=md?z-md:z);
            }
        }
    }
}
vl conv(const vl&a,const vl&b){
    if(sz(a)==0 or sz(b)==0)return {};
    int s=sz(a)+sz(b)-1,bt=32-__builtin_clz(s),n=1<<bt;
    ll inv=pow_mod(n,md-2,md);
    vl va(a),vb(b),out(n);
    va.resize(n);vb.resize(n);
    ntt(va);ntt(vb);
    for(int i=0;i<n;i++)out[-i&(n-1)]=va[i]*vb[i]%md*inv%md;
    ntt(out);
    return {out.begin(),out.begin()+s};
}
vl dnc(int l,int r){
    if(l==r)return {l,1};
    int m=(l+r)/2;
    return conv(dnc(l,m),dnc(m+1,r));
}

int main(){
    vl a=dnc(0,2);
    for(int i=0;i<sz(a);i++) cout<<a[i]<<" "; cout<<endl;
}


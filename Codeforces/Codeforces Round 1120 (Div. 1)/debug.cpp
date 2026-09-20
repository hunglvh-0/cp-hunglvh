#include <bits/stdc++.h>
using namespace std;
int main() {
    int t=1;
    while(t--) {
        int n=4;
        vector<long long> a = {0, 1, 3, 4};
        long long su=8;
        long long x=a[n-1];
        int k1=n/2;
        int k2=(n+1)/2;
        set<long long> cd;
        long long rm=1LL*k2*x-su;
        cout<<"rm="<<rm<<endl;
        if(n%2!=0) {}
        else {
            if(rm==0) {
                cd.insert(a[1]);
                if((x-a[1])%(k2-1)==0) {
                    cd.insert((x-a[1])/(k2-1));
                }
            }
        }
        for(long long d:cd) {
            cout<<"d="<<d<<endl;
            vector<long long> b;
            for(int i=0;i<k1;i++) b.push_back(i*d);
            for(int i=0;i<k2;i++) b.push_back(x-i*d);
            sort(b.begin(),b.end());
            cout<<"b==a: "<<(b==a)<<endl;
        }
    }
}



#include <iostream>
using namespace std;
long long modpow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while(b > 0) { if(b&1) res=(res*a)%m; a=(a*a)%m; b>>=1; }
    return res;
}
int main() {
    cout << (571380540LL * modpow(506814795LL, 998244353-2, 998244353)) % 998244353 << endl;
}


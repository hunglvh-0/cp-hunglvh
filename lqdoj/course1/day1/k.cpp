#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
void print128(__int128 n) {
    if (n == 0) {
        cout << 0;
        return;
    }
    string s;
    while (n > 0) {
        s += (char)('0' + n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
inline void sol(){
    ll a, b;
    cin >> a >> b;
    __int128 A = a;
    __int128 B = b;
    __int128 ans = ((B - A + 1) * (A + B)) / 2;
    print128(ans);
    cout << el;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    int n = 100;
    cout<<1<<'\n'<<n<<'\n';
    cout<<n<<'\n';
    for(int i=0;i<n;i++) {
        cout<<rng()%n + 1<<" ";
    }
    cout<<'\n';
}

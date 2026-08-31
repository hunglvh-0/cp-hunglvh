
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> p(n+1), q(n+1), qinv(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) { cin >> q[i]; qinv[q[i]] = i; }
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            int cur = i, len = 0;
            while(!vis[cur]) {
                vis[cur] = 1; len++;
                cur = qinv[p[cur]];
            }
            cout << len << ' ';
        }
    }
}


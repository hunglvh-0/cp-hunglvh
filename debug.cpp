#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100005;
int fq[maxn], p[maxn], v[maxn];
int main() {
    int t;
    if (!(cin >> t)) return 0;
    while(t--) {
        int n, m; cin >> n >> m;
        for(int i=0; i<n; i++) fq[i] = 0;
        for(int i=1; i<=n; i++) {
            cin >> p[i];
            int df = (i - p[i] + n) % n;
            fq[df]++;
        }
        vector<int> r;
        for(int k=0; k<n; k++) {
            if(fq[k] >= n - 2*m) {
                for(int i=1; i<=n; i++) v[i] = 0;
                int cy = 0;
                for(int i=1; i<=n; i++) {
                    if(v[i] == 0) {
                        cy++;
                        int cr = i;
                        while(v[cr] == 0) {
                            v[cr] = 1;
                            int tg = (p[cr] + k - 1) % n + 1;
                            cr = tg;
                        }
                    }
                }
                if(n - cy <= m) r.push_back(k);
            }
        }
        cout << r.size();
        for(int i=0; i<r.size(); i++) cout << " " << r[i];
        cout << "\n";
    }
}


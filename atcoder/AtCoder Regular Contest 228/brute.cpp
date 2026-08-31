
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 998244353;
int N, M;
vector<int> P, Q;

bool isValid(const vector<int>& p, const vector<int>& q) {
    vector<int> cnt(N+1, 0);
    for(int x : p) cnt[x]++;
    for(int i=1; i<=N; i++) if(cnt[i] != 1) return false;
    return true;
}

int dfs(int step, vector<int> p, vector<int> q) {
    if(step == M) {
        return isValid(p, q) ? 1 : 0;
    }
    long long ways = 0;
    // Swap P
    for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) {
        swap(p[i], p[j]);
        ways = (ways + dfs(step+1, p, q)) % MOD;
        swap(p[i], p[j]);
    }
    // Swap Q
    for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) {
        swap(q[i], q[j]);
        ways = (ways + dfs(step+1, p, q)) % MOD;
        swap(q[i], q[j]);
    }
    // Swap P, Q
    for(int i=0; i<N; i++) {
        swap(p[i], q[i]);
        ways = (ways + dfs(step+1, p, q)) % MOD;
        swap(p[i], q[i]);
    }
    return ways;
}

int main() {
    cin >> N >> M;
    P.resize(N); Q.resize(N);
    for(int i=0; i<N; i++) cin >> P[i];
    for(int i=0; i<N; i++) cin >> Q[i];
    cout << dfs(0, P, Q) << endl;
}


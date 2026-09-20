#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vector<int> p(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<int> max_p(n);
    max_p[0] = p[0];
    for (int i = 1; i < n; i++)
        max_p[i] = max(max_p[i - 1], p[i]);
    vector<int> min_s(n);
    min_s[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--)
        min_s[i] = min(min_s[i + 1], p[i]);

    // Let's check prefix max < suffix min split point!
    // If max_p[i] < min_s[i+1], then all elements in p[0..i] are smaller than
    // all elements in p[i+1..n-1]. Any edge between u in p[0..i] and v in
    // p[i+1..n-1] must have u < v because u <= max_p[i] < min_s[i+1] <= v. And
    // u appears before v in p! So edges between p[0..i] and p[i+1..n-1] are
    // ALWAYS valid! Thus we can split the problem into components! But within a
    // component, CAN WE ALWAYS satisfy it if max_p[i] > min_s[i+1]? Wait, let's
    // test if a component is valid iff it doesn't have an internal
    // contradiction.
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
            solve();
    }
    return 0;
}

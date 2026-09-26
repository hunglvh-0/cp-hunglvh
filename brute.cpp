#include <bits/stdc++.h>
using namespace std;

int bfs_dist(string start)
{
    int n = start.size();
    auto is_sorted = [&](const string &s)
    {
        for (int i = 0; i < n - 1; i++)
            if (s[i] > s[i + 1])
                return false;
        return true;
    };
    if (is_sorted(start))
        return 0;

    queue<string> q;
    map<string, int> dist;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        string u = q.front();
        q.pop();
        int d = dist[u];

        if (is_sorted(u))
            return d;

        for (int i = 0; i < n; i++)
        {
            // prefix u[0..i]
            int has_0 = 0, has_1 = 0;
            for (int j = 0; j <= i; j++)
            {
                if (u[j] == '0')
                    has_0 = 1;
                if (u[j] == '1')
                    has_1 = 1;
            }
            // AND result: 1 if !has_0, else 0
            char and_res = (!has_0) ? '1' : '0';
            // OR result: 1 if has_1, else 0
            char or_res = (has_1) ? '1' : '0';

            // try AND
            if (u[i] != and_res)
            {
                string v = u;
                v[i] = and_res;
                if (!dist.count(v))
                {
                    dist[v] = d + 1;
                    if (is_sorted(v))
                        return d + 1;
                    q.push(v);
                }
            }
            // try OR
            if (u[i] != or_res)
            {
                string v = u;
                v[i] = or_res;
                if (!dist.count(v))
                {
                    dist[v] = d + 1;
                    if (is_sorted(v))
                        return d + 1;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

int solve_fast(string s)
{
    int n = s.size();
    // check if already sorted
    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
        if (s[i] > s[i + 1])
            sorted = false;
    if (sorted)
        return 0;

    if (s[0] == '1')
    {
        int cnt0 = 0;
        for (char c : s)
            if (c == '0')
                cnt0++;
        return cnt0;
    }

    int first_1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            first_1 = i;
            break;
        }
    }
    if (first_1 == -1)
        return 0;

    // prefix sums of 1s
    vector<int> pref1(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref1[i + 1] = pref1[i] + (s[i] == '1');

    int total1 = pref1[n];
    // Option 1: all 0s
    int ans = total1;

    // Option 2: first 1 at p (first_1 <= p < n)
    // target has 0s in [0, p-1] and 1s in [p, n-1]
    // cost = (1s in [0, p-1]) + (0s in [p, n-1])
    // 1s in [0, p-1] = pref1[p]
    // 0s in [p, n-1] = (n - p) - (pref1[n] - pref1[p])
    for (int p = first_1; p < n; p++)
    {
        int cost = pref1[p] + (n - p) - (pref1[n] - pref1[p]);
        ans = min(ans, cost);
    }
    return ans;
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            string s;
            cin >> n >> s;
            cout << bfs_dist(s) << "\n";
        }
    }
    return 0;
}

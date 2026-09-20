// Source: https://cp-algorithms.com/dynamic_programming/knuth-optimization.html

namespace DP_KnuthOptimization
{
        namespace DPKnuthOptimization
        {
                const long long INF64 = (long long)4e18;
                long long optimal_merge_cost(const vector<long long> &a)
                {
                        int n = (int)a.size() - 1;
                        if (n <= 1)
                        {
                                return 0;
                        }
                        vector<long long> pre(n + 1, 0);
                        for (int i = 1; i <= n; ++i)
                        {
                                pre[i] = pre[i - 1] + a[i];
                        }
                        auto w = [&](int l, int r) -> long long
                        {
                                return pre[r] - pre[l - 1];
                        };
                        vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
                        vector<vector<int>> opt(n + 2, vector<int>(n + 2, 0));
                        for (int i = 1; i <= n; ++i)
                        {
                                dp[i][i] = 0;
                                opt[i][i] = i;
                        }
                        for (int len = 2; len <= n; ++len)
                        {
                                for (int l = 1; l + len - 1 <= n; ++l)
                                {
                                        int r = l + len - 1;
                                        dp[l][r] = INF64;
                                        int L = opt[l][r - 1];
                                        int R = opt[l + 1][r];
                                        if (L < l)
                                        {
                                                L = l;
                                        }
                                        if (R > r - 1)
                                        {
                                                R = r - 1;
                                        }
                                        for (int k = L; k <= R; ++k)
                                        {
                                                long long cand = dp[l][k] + dp[k + 1][r] + w(l, r);
                                                if (cand < dp[l][r])
                                                {
                                                        dp[l][r] = cand;
                                                        opt[l][r] = k;
                                                }
                                        }
                                }
                        }
                        return dp[1][n];
                }
        }
}

// Source: https://oi-wiki.org/math/combinatorics/stirling/

namespace Stirling_Numbers
{
        namespace StirlingNumbers
        {
                long long norm(long long x, long long mod)
                {
                        if (!mod)
                        {
                                return x;
                        }
                        x %= mod;
                        if (x < 0)
                        {
                                x += mod;
                        }
                        return x;
                }
                long long add(long long a, long long b, long long mod)
                {
                        return norm(norm(a, mod) + norm(b, mod), mod);
                }
                long long sub(long long a, long long b, long long mod)
                {
                        return norm(norm(a, mod) - norm(b, mod), mod);
                }
                long long mul(long long a, long long b, long long mod)
                {
                        if (!mod)
                        {
                                return (long long)((__int128)a * b);
                        }
                        return (long long)((__int128)norm(a, mod) * norm(b, mod) % mod);
                }
                vector<vector<long long>> stirling2_table(int n, int k, long long mod = 0)
                {
                        vector<vector<long long>> s(n + 1, vector<long long>(k + 1, 0));
                        s[0][0] = 1;
                        for (int i = 1; i <= n; ++i)
                        {
                                int lim = min(i, k);
                                for (int j = 1; j <= lim; ++j)
                                {
                                        s[i][j] = add(s[i - 1][j - 1], mul(j, s[i - 1][j], mod), mod);
                                }
                        }
                        return s;
                }
                vector<vector<long long>> stirling1_unsigned_table(int n, int k, long long mod = 0)
                {
                        vector<vector<long long>> s(n + 1, vector<long long>(k + 1, 0));
                        s[0][0] = 1;
                        for (int i = 1; i <= n; ++i)
                        {
                                int lim = min(i, k);
                                for (int j = 1; j <= lim; ++j)
                                {
                                        s[i][j] = add(s[i - 1][j - 1], mul(i - 1, s[i - 1][j], mod), mod);
                                }
                        }
                        return s;
                }
                vector<vector<long long>> stirling1_signed_table(int n, int k, long long mod = 0)
                {
                        vector<vector<long long>> s(n + 1, vector<long long>(k + 1, 0));
                        s[0][0] = 1;
                        for (int i = 1; i <= n; ++i)
                        {
                                int lim = min(i, k);
                                for (int j = 1; j <= lim; ++j)
                                {
                                        s[i][j] = sub(s[i - 1][j - 1], mul(i - 1, s[i - 1][j], mod), mod);
                                }
                        }
                        return s;
                }
                vector<long long> stirling2_row(int n, int k, long long mod = 0)
                {
                        vector<long long> dp(k + 1, 0);
                        dp[0] = 1;
                        for (int i = 1; i <= n; ++i)
                        {
                                int lim = min(i, k);
                                for (int j = lim; j >= 1; --j)
                                {
                                        dp[j] = add(dp[j - 1], mul(j, dp[j], mod), mod);
                                }
                                dp[0] = 0;
                        }
                        return dp;
                }
                vector<long long> stirling1_unsigned_row(int n, int k, long long mod = 0)
                {
                        vector<long long> dp(k + 1, 0);
                        dp[0] = 1;
                        for (int i = 1; i <= n; ++i)
                        {
                                int lim = min(i, k);
                                for (int j = lim; j >= 1; --j)
                                {
                                        dp[j] = add(dp[j - 1], mul(i - 1, dp[j], mod), mod);
                                }
                                dp[0] = 0;
                        }
                        return dp;
                }
        }
}

// Source: https://www.geeksforgeeks.org/digit-dp-introduction/

namespace DP_Digit
{
        namespace DPDigit
        {
                struct DigitDP
                {
                        string s;
                        int n;
                        int mod;
                        int target;
                        vector<vector<vector<vector<long long>>>> memo;
                        vector<vector<vector<vector<char>>>> vis;
                        long long dfs(int pos, int tight, int started, int last, int rem)
                        {
                                if (pos == n)
                                {
                                        return (rem == target ? 1 : 0);
                                }
                                if (!tight and vis[pos][started][last][rem])
                                {
                                        return memo[pos][started][last][rem];
                                }
                                int up = (tight ? s[pos] - '0' : 9);
                                long long ans = 0;
                                for (int d = 0; d <= up; ++d)
                                {
                                        int ntight = (tight and d == up);
                                        if (!started and d == 0)
                                        {
                                                ans += dfs(pos + 1, ntight, 0, 10, rem);
                                        }
                                        else
                                        {
                                                if (started and d == last)
                                                {
                                                        continue;
                                                }
                                                ans += dfs(pos + 1, ntight, 1, d, (rem + d) % mod);
                                        }
                                }
                                if (!tight)
                                {
                                        vis[pos][started][last][rem] = 1;
                                        memo[pos][started][last][rem] = ans;
                                }
                                return ans;
                        }
                        long long solve_upto(long long x, int _mod, int _target)
                        {
                                if (x < 0)
                                {
                                        return 0;
                                }
                                s = to_string(x);
                                n = (int)s.size();
                                mod = _mod;
                                target = ((_target % mod) + mod) % mod;
                                memo.assign(n, vector<vector<vector<long long>>>(2, vector<vector<long long>>(11, vector<long long>(mod, 0))));
                                vis.assign(n, vector<vector<vector<char>>>(2, vector<vector<char>>(11, vector<char>(mod, 0))));
                                return dfs(0, 1, 0, 10, 0);
                        }
                        long long solve_range(long long L, long long R, int _mod, int _target)
                        {
                                if (L > R)
                                {
                                        return 0;
                                }
                                return solve_upto(R, _mod, _target) - solve_upto(L - 1, _mod, _target);
                        }
                };
        }
}

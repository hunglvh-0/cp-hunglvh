// Source: https://cp-algorithms.com/dynamic_programming/profile-dynamics.html

namespace DP_BrokenProfile
{
        namespace DPBrokenProfile
        {
                struct ProfileDP
                {
                        int n;
                        int m;
                        long long mod;
                        vector<int> blocked;
                        void dfs_row(int col, int cur_mask, int next_mask, int nxt_block, vector<int> &outs)
                        {
                                if (col == m)
                                {
                                        outs.push_back(next_mask);
                                        return;
                                }
                                if ((cur_mask >> col) & 1)
                                {
                                        dfs_row(col + 1, cur_mask, next_mask, nxt_block, outs);
                                        return;
                                }
                                if (col + 1 < m and (((cur_mask >> (col + 1)) & 1) == 0))
                                {
                                        dfs_row(col + 2, cur_mask, next_mask, nxt_block, outs);
                                }
                                if (((nxt_block >> col) & 1) == 0)
                                {
                                        dfs_row(col + 1, cur_mask, next_mask | (1 << col), nxt_block, outs);
                                }
                        }
                        long long add(long long a, long long b) const
                        {
                                if (!mod)
                                {
                                        return a + b;
                                }
                                a += b;
                                if (a >= mod)
                                {
                                        a -= mod;
                                }
                                return a;
                        }
                        long long count_tilings(int _n, int _m, const vector<int> &_blocked, long long _mod = 0)
                        {
                                n = _n;
                                m = _m;
                                blocked = _blocked;
                                mod = _mod;
                                int S = 1 << m;
                                vector<long long> dp(S, 0), ndp(S, 0);
                                dp[0] = 1;
                                for (int r = 0; r < n; ++r)
                                {
                                        fill(ndp.begin(), ndp.end(), 0);
                                        int cur_block = blocked[r];
                                        int nxt_block = (r + 1 < n ? blocked[r + 1] : (S - 1));
                                        for (int mask = 0; mask < S; ++mask)
                                        {
                                                if (!dp[mask])
                                                {
                                                        continue;
                                                }
                                                if (mask & cur_block)
                                                {
                                                        continue;
                                                }
                                                vector<int> outs;
                                                dfs_row(0, mask | cur_block, 0, nxt_block, outs);
                                                for (int nm : outs)
                                                {
                                                        ndp[nm] = add(ndp[nm], dp[mask]);
                                                }
                                        }
                                        dp.swap(ndp);
                                }
                                return dp[0];
                        }
                };
        }
}

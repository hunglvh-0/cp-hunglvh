// Source: https://cp-algorithms.com/game_theory/sprague-grundy-nim.html

namespace Sprague_Grundy_Nim
{
        namespace SpragueGrundyNim
        {
                int mex(const vector<int> &v)
                {
                        int lim = (int)v.size() + 5;
                        vector<char> seen(lim, false);
                        for (int x : v)
                        {
                                if (x >= 0 and x < lim)
                                {
                                        seen[x] = true;
                                }
                        }
                        int r = 0;
                        while (r < lim and seen[r])
                        {
                                ++r;
                        }
                        return r;
                }
                int grundy_dfs(int u, const vector<vector<int>> &g, vector<int> &dp)
                {
                        if (dp[u] != -1)
                        {
                                return dp[u];
                        }
                        vector<int> nxt;
                        nxt.reserve(g[u].size());
                        for (int v : g[u])
                        {
                                nxt.push_back(grundy_dfs(v, g, dp));
                        }
                        dp[u] = mex(nxt);
                        return dp[u];
                }
                vector<int> grundy_dag(const vector<vector<int>> &g)
                {
                        int n = (int)g.size();
                        vector<int> dp(n, -1);
                        for (int i = 0; i < n; ++i)
                        {
                                if (dp[i] == -1)
                                {
                                        grundy_dfs(i, g, dp);
                                }
                        }
                        return dp;
                }
                vector<int> grundy_subtraction_game(int n, const vector<int> &moves)
                {
                        vector<int> sg(n + 1, 0);
                        for (int i = 1; i <= n; ++i)
                        {
                                vector<int> nxt;
                                for (int d : moves)
                                {
                                        if (d <= i)
                                        {
                                                nxt.push_back(sg[i - d]);
                                        }
                                }
                                sg[i] = mex(nxt);
                        }
                        return sg;
                }
                int nim_sum(const vector<int> &a)
                {
                        int x = 0;
                        for (int v : a)
                        {
                                x ^= v;
                        }
                        return x;
                }
                bool first_win_nim(const vector<int> &piles)
                {
                        return nim_sum(piles) != 0;
                }
                bool first_win_disjoint_games(const vector<int> &grundy_values)
                {
                        return nim_sum(grundy_values) != 0;
                }
        }
}

// Source: https://oi-wiki.org/dp/tree/

namespace DP_Tree_Knapsack
{
    namespace DPTreeKnapsack
    {
        const long long NEG = (long long)-4e18;
        struct Solver
    {
            int n;
            int K;
            vector<vector<int>> g;
            vector<long long> w;
            vector<int> sz;
            vector<vector<long long>> dp;
            Solver(int _n = 0, int _K = 0)
    {
                init(_n, _K);

    }
            void init(int _n, int _K)
    {
                n = _n;
                K = _K;
                g.assign(n + 1,
    {
    }
    );
                w.assign(n + 1, 0);
                sz.assign(n + 1, 0);
                dp.assign(n + 1, vector<long long>(K + 1, NEG));

    }
            void add_edge(int u, int v)
    {
                g[u].push_back(v);
                g[v].push_back(u);

    }
            void set_weight(int u, long long val)
    {
                w[u] = val;

    }
            void dfs(int u, int p)
    {
                sz[u] = 1;
                dp[u][0] = 0;
                if (K >= 1)
    {
                    dp[u][1] = w[u];

    }
                for (int v : g[u])
    {
                    if (v == p)
    {
                        continue;

    }
                    dfs(v, u);
                    vector<long long> ndp(K + 1, NEG);
                    for (int i = 0; i <= min(sz[u], K); ++i)
    {
                        if (dp[u][i] <= NEG / 2)
    {
                            continue;

    }
                        for (int j = 0; j <= min(sz[v], K - i); ++j)
    {
                            if (dp[v][j] <= NEG / 2)
    {
                                continue;

    }
                            ndp[i + j] = max(ndp[i + j], dp[u][i] + dp[v][j]);

    }

    }
                    dp[u].swap(ndp);
                    sz[u] += sz[v];

    }

    }
            long long solve_exact_k(int root, int k)
    {
                dfs(root, 0);
                return dp[root][k];

    }

    }
    ;
    }
}

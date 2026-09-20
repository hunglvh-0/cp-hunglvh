// Source: https://en.wikipedia.org/wiki/Blossom_algorithm

namespace MaximumWeightMatching_Blossom
{
        namespace MaximumWeightMatchingBlossom
        {
                class BlossomGeneralMatching
                {
                public:
                        int n;
                        std::vector<std::vector<int>> g;
                        std::vector<int> match;
                        std::vector<int> p;
                        std::vector<int> base;
                        std::vector<int> q;
                        std::vector<char> used;
                        std::vector<char> blossom;
                        BlossomGeneralMatching(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                                match.assign(n + 1, 0);
                                p.assign(n + 1, 0);
                                base.assign(n + 1, 0);
                                q.assign(n + 1, 0);
                                used.assign(n + 1, 0);
                                blossom.assign(n + 1, 0);
                        }
                        void AddEdge(int u, int v)
                        {
                                if (u == v)
                                {
                                        return;
                                }
                                g[u].push_back(v);
                                g[v].push_back(u);
                        }
                        int LCA(int a, int b)
                        {
                                std::vector<char> vis(n + 1, 0);
                                while (true)
                                {
                                        a = base[a];
                                        vis[a] = 1;
                                        if (!match[a])
                                        {
                                                break;
                                        }
                                        a = p[match[a]];
                                }
                                while (true)
                                {
                                        b = base[b];
                                        if (vis[b])
                                        {
                                                return b;
                                        }
                                        if (!match[b])
                                        {
                                                break;
                                        }
                                        b = p[match[b]];
                                }
                                return 0;
                        }
                        void MarkPath(int v, int b, int children)
                        {
                                while (base[v] != b)
                                {
                                        blossom[base[v]] = 1;
                                        blossom[base[match[v]]] = 1;
                                        p[v] = children;
                                        children = match[v];
                                        v = p[match[v]];
                                }
                        }
                        int FindPath(int root)
                        {
                                std::fill(used.begin(), used.end(), 0);
                                std::fill(p.begin(), p.end(), 0);
                                std::iota(base.begin(), base.end(), 0);
                                int qh = 0;
                                int qt = 0;
                                q[qt++] = root;
                                used[root] = 1;
                                while (qh < qt)
                                {
                                        int v = q[qh++];
                                        for (int u : g[v])
                                        {
                                                if (base[v] == base[u] or match[v] == u)
                                                {
                                                        continue;
                                                }
                                                if (u == root or (match[u] and p[match[u]]))
                                                {
                                                        int cur = LCA(v, u);
                                                        std::fill(blossom.begin(), blossom.end(), 0);
                                                        MarkPath(v, cur, u);
                                                        MarkPath(u, cur, v);
                                                        for (int i = 1; i <= n; ++i)
                                                        {
                                                                if (!blossom[base[i]])
                                                                {
                                                                        continue;
                                                                }
                                                                base[i] = cur;
                                                                if (!used[i])
                                                                {
                                                                        used[i] = 1;
                                                                        q[qt++] = i;
                                                                }
                                                        }
                                                }
                                                else if (!p[u])
                                                {
                                                        p[u] = v;
                                                        if (!match[u])
                                                        {
                                                                return u;
                                                        }
                                                        u = match[u];
                                                        used[u] = 1;
                                                        q[qt++] = u;
                                                }
                                        }
                                }
                                return 0;
                        }
                        int MaxMatching()
                        {
                                int matching = 0;
                                for (int i = 1; i <= n; ++i)
                                {
                                        if (match[i])
                                        {
                                                continue;
                                        }
                                        int v = FindPath(i);
                                        if (!v)
                                        {
                                                continue;
                                        }
                                        while (v)
                                        {
                                                int pv = p[v];
                                                int nv = match[pv];
                                                match[v] = pv;
                                                match[pv] = v;
                                                v = nv;
                                        }
                                        matching++;
                                }
                                return matching;
                        }
                };
                class MaximumWeightMatchingSmallN
                {
                public:
                        static long long Solve(const std::vector<std::vector<long long>> &w)
                        {
                                int n = (int)w.size();
                                int N = 1 << n;
                                std::vector<long long> dp(N, LLONG_MIN / 4);
                                dp[0] = 0;
                                for (int mask = 1; mask < N; ++mask)
                                {
                                        int i = __builtin_ctz(mask);
                                        dp[mask] = std::max(dp[mask], dp[mask ^ (1 << i)]);
                                        for (int j = i + 1; j < n; ++j)
                                        {
                                                if ((mask >> j) & 1)
                                                {
                                                        dp[mask] = std::max(dp[mask], dp[mask ^ (1 << i) ^ (1 << j)] + w[i][j]);
                                                }
                                        }
                                }
                                return dp[N - 1];
                        }
                };
        }
}

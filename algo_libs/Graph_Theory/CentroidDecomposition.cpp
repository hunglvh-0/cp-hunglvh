// Source: https://cp-algorithms.com/graph/centroid_decomposition.html

namespace CentroidDecomposition
{
        namespace CentroidDecomposition
        {
                struct Solver
                {
                        int n = 0;
                        std::vector<std::vector<int>> g;
                        std::vector<int> sz;
                        std::vector<int> par;
                        std::vector<int> used;
                        Solver(int n_ = 0)
                        {
                                init(n_);
                        }
                        void init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                                sz.assign(n + 1, 0);
                                par.assign(n + 1, 0);
                                used.assign(n + 1, 0);
                        }
                        void addEdge(int u, int v)
                        {
                                g[u].push_back(v);
                                g[v].push_back(u);
                        }
                        int dfsSize(int u, int p)
                        {
                                sz[u] = 1;
                                for (int v : g[u])
                                {
                                        if (v == p or used[v])
                                        {
                                                continue;
                                        }
                                        sz[u] += dfsSize(v, u);
                                }
                                return sz[u];
                        }
                        int dfsCentroid(int u, int p, int tot)
                        {
                                for (int v : g[u])
                                {
                                        if (v == p or used[v])
                                        {
                                                continue;
                                        }
                                        if (sz[v] > tot / 2)
                                        {
                                                return dfsCentroid(v, u, tot);
                                        }
                                }
                                return u;
                        }
                        int build(int entry = 1, int p = 0)
                        {
                                int tot = dfsSize(entry, 0);
                                int c = dfsCentroid(entry, 0, tot);
                                used[c] = 1;
                                par[c] = p;
                                for (int v : g[c])
                                {
                                        if (used[v])
                                        {
                                                continue;
                                        }
                                        build(v, c);
                                }
                                return c;
                        }
                };
        }
}

// Source: https://cp-algorithms.com/graph/lca_binary_lifting.html

namespace LCA_BinaryLifting
{
        namespace LCABinaryLifting
        {
                class Solver
                {
                public:
                        int n;
                        int lg;
                        int timer;
                        std::vector<std::vector<int>> g;
                        std::vector<std::vector<int>> up;
                        std::vector<int> tin;
                        std::vector<int> tout;
                        std::vector<int> dep;
                        Solver(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                lg = 1;
                                while ((1 << lg) <= n)
                                {
                                        lg++;
                                }
                                timer = 0;
                                g.assign(n + 1,
                                         {});
                                up.assign(lg, std::vector<int>(n + 1, 0));
                                tin.assign(n + 1, 0);
                                tout.assign(n + 1, 0);
                                dep.assign(n + 1, 0);
                        }
                        void AddEdge(int u, int v)
                        {
                                g[u].push_back(v);
                                g[v].push_back(u);
                        }
                        void DFS(int v, int p)
                        {
                                tin[v] = ++timer;
                                up[0][v] = p;
                                for (int i = 1; i < lg; ++i)
                                {
                                        up[i][v] = up[i - 1][up[i - 1][v]];
                                }
                                for (int to : g[v])
                                {
                                        if (to == p)
                                        {
                                                continue;
                                        }
                                        dep[to] = dep[v] + 1;
                                        DFS(to, v);
                                }
                                tout[v] = ++timer;
                        }
                        void Build(int root = 1)
                        {
                                dep[root] = 0;
                                DFS(root, root);
                        }
                        bool IsAncestor(int u, int v) const
                        {
                                return tin[u] <= tin[v] and tout[v] <= tout[u];
                        }
                        int LCA(int u, int v) const
                        {
                                if (IsAncestor(u, v))
                                {
                                        return u;
                                }
                                if (IsAncestor(v, u))
                                {
                                        return v;
                                }
                                for (int i = lg - 1; i >= 0; --i)
                                {
                                        int x = up[i][u];
                                        if (!IsAncestor(x, v))
                                        {
                                                u = x;
                                        }
                                }
                                return up[0][u];
                        }
                        int KthAncestor(int u, int k) const
                        {
                                for (int i = 0; i < lg; ++i)
                                {
                                        if ((k >> i) & 1)
                                        {
                                                u = up[i][u];
                                        }
                                }
                                return u;
                        }
                        int Dist(int u, int v) const
                        {
                                int w = LCA(u, v);
                                return dep[u] + dep[v] - 2 * dep[w];
                        }
                };
        }
}

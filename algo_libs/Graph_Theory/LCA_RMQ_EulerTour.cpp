// Source: https://cp-algorithms.com/graph/lca.html

namespace LCA_RMQ_EulerTour
{
        namespace LCARMQEulerTour
        {
                class Solver
                {
                public:
                        int n;
                        std::vector<std::vector<int>> g;
                        std::vector<int> dep;
                        std::vector<int> first;
                        std::vector<int> euler;
                        std::vector<std::vector<int>> st;
                        std::vector<int> lg2;
                        Solver(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                                dep.assign(n + 1, 0);
                                first.assign(n + 1, -1);
                                euler.clear();
                                st.clear();
                                lg2.clear();
                        }
                        void AddEdge(int u, int v)
                        {
                                g[u].push_back(v);
                                g[v].push_back(u);
                        }
                        void DFS(int v, int p)
                        {
                                first[v] = (int)euler.size();
                                euler.push_back(v);
                                for (int to : g[v])
                                {
                                        if (to == p)
                                        {
                                                continue;
                                        }
                                        dep[to] = dep[v] + 1;
                                        DFS(to, v);
                                        euler.push_back(v);
                                }
                        }
                        void Build(int root = 1)
                        {
                                euler.clear();
                                dep[root] = 0;
                                DFS(root, root);
                                int m = (int)euler.size();
                                lg2.assign(m + 1, 0);
                                for (int i = 2; i <= m; ++i)
                                {
                                        lg2[i] = lg2[i >> 1] + 1;
                                }
                                int K = lg2[m] + 1;
                                st.assign(K, std::vector<int>(m));
                                for (int i = 0; i < m; ++i)
                                {
                                        st[0][i] = euler[i];
                                }
                                for (int k = 1; k < K; ++k)
                                {
                                        for (int i = 0; i + (1 << k) <= m; ++i)
                                        {
                                                int a = st[k - 1][i];
                                                int b = st[k - 1][i + (1 << (k - 1))];
                                                st[k][i] = (dep[a] < dep[b] ? a : b);
                                        }
                                }
                        }
                        int LCA(int u, int v) const
                        {
                                int l = first[u];
                                int r = first[v];
                                if (l > r)
                                {
                                        std::swap(l, r);
                                }
                                int k = lg2[r - l + 1];
                                int a = st[k][l];
                                int b = st[k][r - (1 << k) + 1];
                                return dep[a] < dep[b] ? a : b;
                        }
                        int Dist(int u, int v) const
                        {
                                int w = LCA(u, v);
                                return dep[u] + dep[v] - 2 * dep[w];
                        }
                };
        }
}

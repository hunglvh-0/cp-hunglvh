// Source: https://cp-algorithms.com/graph/lengauer-tarjan.html

namespace DominatorTree
{
        namespace DominatorTree
        {
                struct Solver
                {
                        int n = 0;
                        int timer = 0;
                        std::vector<std::vector<int>> g;
                        std::vector<int> arr;
                        std::vector<int> rev;
                        std::vector<int> par;
                        std::vector<int> sdom;
                        std::vector<int> dom;
                        std::vector<int> dsu;
                        std::vector<int> label;
                        std::vector<std::vector<int>> rg;
                        std::vector<std::vector<int>> bucket;
                        std::vector<int> idom;
                        Solver(int n_ = 0)
                        {
                                init(n_);
                        }
                        void init(int n_)
                        {
                                n = n_;
                                timer = 0;
                                g.assign(n + 1,
                                         {});
                        }
                        void addEdge(int u, int v)
                        {
                                g[u].push_back(v);
                        }
                        void dfs(int u)
                        {
                                timer++;
                                arr[u] = timer;
                                rev[timer] = u;
                                sdom[timer] = timer;
                                label[timer] = timer;
                                dsu[timer] = timer;
                                for (int v : g[u])
                                {
                                        if (!arr[v])
                                        {
                                                dfs(v);
                                                par[arr[v]] = arr[u];
                                        }
                                        if (arr[v])
                                        {
                                                rg[arr[v]].push_back(arr[u]);
                                        }
                                }
                        }
                        int find(int u, int x = 0)
                        {
                                if (u == dsu[u])
                                {
                                        if (x)
                                        {
                                                return -1;
                                        }
                                        return u;
                                }
                                int v = find(dsu[u], x + 1);
                                if (v < 0)
                                {
                                        return u;
                                }
                                if (sdom[label[dsu[u]]] < sdom[label[u]])
                                {
                                        label[u] = label[dsu[u]];
                                }
                                dsu[u] = v;
                                if (x)
                                {
                                        return v;
                                }
                                return label[u];
                        }
                        void unite(int u, int v)
                        {
                                dsu[v] = u;
                        }
                        std::vector<int> build(int src)
                        {
                                arr.assign(n + 1, 0);
                                rev.assign(n + 1, 0);
                                par.assign(n + 1, 0);
                                sdom.assign(n + 1, 0);
                                dom.assign(n + 1, 0);
                                dsu.assign(n + 1, 0);
                                label.assign(n + 1, 0);
                                rg.assign(n + 1,
                                          {});
                                bucket.assign(n + 1,
                                              {});
                                idom.assign(n + 1, -1);
                                timer = 0;
                                dfs(src);
                                int N = timer;
                                for (int i = N; i >= 1; --i)
                                {
                                        for (int v : rg[i])
                                        {
                                                sdom[i] = std::min(sdom[i], sdom[find(v)]);
                                        }
                                        if (i > 1)
                                        {
                                                bucket[sdom[i]].push_back(i);
                                        }
                                        for (int v : bucket[i])
                                        {
                                                int y = find(v);
                                                if (sdom[y] == sdom[v])
                                                {
                                                        dom[v] = sdom[v];
                                                }
                                                else
                                                {
                                                        dom[v] = y;
                                                }
                                        }
                                        if (i > 1)
                                        {
                                                unite(par[i], i);
                                        }
                                }
                                for (int i = 2; i <= N; ++i)
                                {
                                        if (dom[i] != sdom[i])
                                        {
                                                dom[i] = dom[dom[i]];
                                        }
                                }
                                idom[src] = 0;
                                for (int i = 2; i <= N; ++i)
                                {
                                        idom[rev[i]] = rev[dom[i]];
                                }
                                return idom;
                        }
                };
        }
}

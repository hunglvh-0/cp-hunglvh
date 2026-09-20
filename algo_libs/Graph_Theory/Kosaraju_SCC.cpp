// Source: https://cp-algorithms.com/graph/strongly-connected-components.html

namespace Kosaraju_SCC
{
        namespace KosarajuSCC
        {
                struct Solver
                {
                        int n = 0;
                        int compCnt = 0;
                        std::vector<std::vector<int>> g;
                        std::vector<std::vector<int>> rg;
                        std::vector<int> vis;
                        std::vector<int> order;
                        std::vector<int> comp;
                        std::vector<std::vector<int>> comps;
                        Solver(int n_ = 0)
                        {
                                init(n_);
                        }
                        void init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                                rg.assign(n + 1,
                                          {});
                                vis.assign(n + 1, 0);
                                comp.assign(n + 1, -1);
                                order.clear();
                                comps.clear();
                                compCnt = 0;
                        }
                        void addEdge(int u, int v)
                        {
                                g[u].push_back(v);
                                rg[v].push_back(u);
                        }
                        void dfs1(int u)
                        {
                                vis[u] = 1;
                                for (int v : g[u])
                                {
                                        if (!vis[v])
                                        {
                                                dfs1(v);
                                        }
                                }
                                order.push_back(u);
                        }
                        void dfs2(int u)
                        {
                                comp[u] = compCnt;
                                comps.back().push_back(u);
                                for (int v : rg[u])
                                {
                                        if (comp[v] == -1)
                                        {
                                                dfs2(v);
                                        }
                                }
                        }
                        int build()
                        {
                                for (int i = 1; i <= n; ++i)
                                {
                                        if (!vis[i])
                                        {
                                                dfs1(i);
                                        }
                                }
                                std::reverse(order.begin(), order.end());
                                for (int u : order)
                                {
                                        if (comp[u] != -1)
                                        {
                                                continue;
                                        }
                                        comps.push_back(
                                            {});
                                        dfs2(u);
                                        compCnt++;
                                }
                                return compCnt;
                        }
                };
        }
}

// Source: https://cp-algorithms.com/graph/2SAT.html

namespace Two_SAT
{
        namespace TwoSAT
        {
                struct Solver
                {
                        int n = 0;
                        std::vector<std::vector<int>> g;
                        std::vector<std::vector<int>> rg;
                        std::vector<int> order;
                        std::vector<int> comp;
                        std::vector<int> assignment;
                        Solver(int vars = 0)
                        {
                                init(vars);
                        }
                        void init(int vars)
                        {
                                n = vars;
                                g.assign(2 * n,
                                         {});
                                rg.assign(2 * n,
                                          {});
                                order.clear();
                                comp.assign(2 * n, -1);
                                assignment.assign(n, 0);
                        }
                        int id(int x, bool val) const
                        {
                                return 2 * x + (val ? 1 : 0);
                        }
                        void addImp(int a, int b)
                        {
                                g[a].push_back(b);
                                rg[b].push_back(a);
                        }
                        void either(int x, bool xv, int y, bool yv)
                        {
                                addImp(id(x, !xv), id(y, yv));
                                addImp(id(y, !yv), id(x, xv));
                        }
                        void setTrue(int x, bool xv = true)
                        {
                                either(x, xv, x, xv);
                        }
                        void atMostOne(const std::vector<int> &vars)
                        {
                                for (int i = 0; i < (int)vars.size(); ++i)
                                {
                                        for (int j = i + 1; j < (int)vars.size(); ++j)
                                        {
                                                either(vars[i], false, vars[j], false);
                                        }
                                }
                        }
                        void dfs1(int u, std::vector<int> &vis)
                        {
                                vis[u] = 1;
                                for (int v : g[u])
                                {
                                        if (!vis[v])
                                        {
                                                dfs1(v, vis);
                                        }
                                }
                                order.push_back(u);
                        }
                        void dfs2(int u, int c)
                        {
                                comp[u] = c;
                                for (int v : rg[u])
                                {
                                        if (comp[v] == -1)
                                        {
                                                dfs2(v, c);
                                        }
                                }
                        }
                        bool solve()
                        {
                                int N = 2 * n;
                                std::vector<int> vis(N, 0);
                                order.clear();
                                std::fill(comp.begin(), comp.end(), -1);
                                for (int i = 0; i < N; ++i)
                                {
                                        if (!vis[i])
                                        {
                                                dfs1(i, vis);
                                        }
                                }
                                std::reverse(order.begin(), order.end());
                                int c = 0;
                                for (int v : order)
                                {
                                        if (comp[v] == -1)
                                        {
                                                dfs2(v, c++);
                                        }
                                }
                                for (int i = 0; i < n; ++i)
                                {
                                        if (comp[id(i, false)] == comp[id(i, true)])
                                        {
                                                return false;
                                        }
                                        assignment[i] = comp[id(i, true)] > comp[id(i, false)];
                                }
                                return true;
                        }
                };
        }
}

// Source: https://cp-algorithms.com/graph/strongly-connected-components.html

namespace Tarjan_SCC
{
        namespace TarjanSCC
        {
                struct Solver
                {
                        int n = 0;
                        int timer = 0;
                        int compCnt = 0;
                        std::vector<std::vector<int>> g;
                        std::vector<int> tin;
                        std::vector<int> low;
                        std::vector<int> st;
                        std::vector<int> inSt;
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
                                tin.assign(n + 1, 0);
                                low.assign(n + 1, 0);
                                inSt.assign(n + 1, 0);
                                comp.assign(n + 1, -1);
                                st.clear();
                                comps.clear();
                                timer = 0;
                                compCnt = 0;
                        }
                        void addEdge(int u, int v)
                        {
                                g[u].push_back(v);
                        }
                        void dfs(int u)
                        {
                                tin[u] = ++timer;
                                low[u] = tin[u];
                                st.push_back(u);
                                inSt[u] = 1;
                                for (int v : g[u])
                                {
                                        if (!tin[v])
                                        {
                                                dfs(v);
                                                low[u] = std::min(low[u], low[v]);
                                        }
                                        else
                                        {
                                                if (inSt[v])
                                                {
                                                        low[u] = std::min(low[u], tin[v]);
                                                }
                                        }
                                }
                                if (low[u] == tin[u])
                                {
                                        comps.push_back(
                                            {});
                                        while (true)
                                        {
                                                int v = st.back();
                                                st.pop_back();
                                                inSt[v] = 0;
                                                comp[v] = compCnt;
                                                comps.back().push_back(v);
                                                if (v == u)
                                                {
                                                        break;
                                                }
                                        }
                                        compCnt++;
                                }
                        }
                        int build()
                        {
                                for (int i = 1; i <= n; ++i)
                                {
                                        if (!tin[i])
                                        {
                                                dfs(i);
                                        }
                                }
                                return compCnt;
                        }
                };
        }
}

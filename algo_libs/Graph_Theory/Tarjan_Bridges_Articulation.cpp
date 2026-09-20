// Source: https://cp-algorithms.com/graph/bridge-searching.html

namespace Tarjan_Bridges_Articulation
{
        namespace TarjanBridgesArticulation
        {
                struct Solver
                {
                        int n = 0;
                        int timer = 0;
                        std::vector<std::pair<int, int>> edges;
                        std::vector<std::vector<std::pair<int, int>>> g;
                        std::vector<int> tin;
                        std::vector<int> low;
                        std::vector<int> isArt;
                        std::vector<int> bridges;
                        Solver(int n_ = 0)
                        {
                                init(n_);
                        }
                        void init(int n_)
                        {
                                n = n_;
                                timer = 0;
                                edges.clear();
                                g.assign(n + 1,
                                         {});
                                tin.assign(n + 1, 0);
                                low.assign(n + 1, 0);
                                isArt.assign(n + 1, 0);
                                bridges.clear();
                        }
                        void addEdge(int u, int v)
                        {
                                int id = (int)edges.size();
                                edges.push_back(
                                    {u, v});
                                g[u].push_back(
                                    {v, id});
                                g[v].push_back(
                                    {u, id});
                        }
                        void dfs(int u, int pe = -1)
                        {
                                tin[u] = ++timer;
                                low[u] = tin[u];
                                int child = 0;
                                for (auto [v, id] : g[u])
                                {
                                        if (id == pe)
                                        {
                                                continue;
                                        }
                                        if (!tin[v])
                                        {
                                                child++;
                                                dfs(v, id);
                                                low[u] = std::min(low[u], low[v]);
                                                if (low[v] > tin[u])
                                                {
                                                        bridges.push_back(id);
                                                }
                                                if (pe != -1 and low[v] >= tin[u])
                                                {
                                                        isArt[u] = 1;
                                                }
                                        }
                                        else
                                        {
                                                low[u] = std::min(low[u], tin[v]);
                                        }
                                }
                                if (pe == -1 and child > 1)
                                {
                                        isArt[u] = 1;
                                }
                        }
                        void build()
                        {
                                for (int i = 1; i <= n; ++i)
                                {
                                        if (!tin[i])
                                        {
                                                dfs(i);
                                        }
                                }
                        }
                        std::vector<int> articulationPoints() const
                        {
                                std::vector<int> ans;
                                for (int i = 1; i <= n; ++i)
                                {
                                        if (isArt[i])
                                        {
                                                ans.push_back(i);
                                        }
                                }
                                return ans;
                        }
                };
        }
}

// Source: https://en.wikipedia.org/wiki/Chordal_graph

namespace ChordalGraph_PerfectElimination
{
        namespace ChordalGraphPEO
        {
                struct Solver
                {
                        int n = 0;
                        std::vector<std::vector<int>> g;
                        std::vector<std::unordered_set<int>> has;
                        Solver(int n_ = 0)
                        {
                                init(n_);
                        }
                        void init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                                has.assign(n + 1,
                                           {});
                        }
                        void addEdge(int u, int v)
                        {
                                if (u == v)
                                {
                                        return;
                                }
                                g[u].push_back(v);
                                g[v].push_back(u);
                                has[u].insert(v);
                                has[v].insert(u);
                        }
                        std::vector<int> mcsOrder() const
                        {
                                std::vector<int> lbl(n + 1, 0);
                                std::vector<int> used(n + 1, 0);
                                std::vector<int> ord(n + 1, 0);
                                for (int k = n; k >= 1; --k)
                                {
                                        int v = -1;
                                        for (int i = 1; i <= n; ++i)
                                        {
                                                if (used[i])
                                                {
                                                        continue;
                                                }
                                                if (v == -1 or lbl[i] > lbl[v])
                                                {
                                                        v = i;
                                                }
                                        }
                                        ord[k] = v;
                                        used[v] = 1;
                                        for (int to : g[v])
                                        {
                                                if (!used[to])
                                                {
                                                        lbl[to]++;
                                                }
                                        }
                                }
                                ord.erase(ord.begin());
                                return ord;
                        }
                        std::pair<bool, std::vector<int>> perfectEliminationOrdering() const
                        {
                                std::vector<int> peo = mcsOrder();
                                std::vector<int> pos(n + 1, 0);
                                for (int i = 0; i < n; ++i)
                                {
                                        pos[peo[i]] = i;
                                }
                                for (int i = 0; i < n; ++i)
                                {
                                        int v = peo[i];
                                        int parent = -1;
                                        for (int to : g[v])
                                        {
                                                if (pos[to] <= pos[v])
                                                {
                                                        continue;
                                                }
                                                if (parent == -1 or pos[to] < pos[parent])
                                                {
                                                        parent = to;
                                                }
                                        }
                                        if (parent == -1)
                                        {
                                                continue;
                                        }
                                        for (int to : g[v])
                                        {
                                                if (to == parent or pos[to] <= pos[v])
                                                {
                                                        continue;
                                                }
                                                if (!has[parent].count(to))
                                                {
                                                        return {
                                                            false, peo};
                                                }
                                        }
                                }
                                return {
                                    true, peo};
                        }
                        int maxCliqueSizeIfChordal(const std::vector<int> &peo) const
                        {
                                std::vector<int> pos(n + 1, 0);
                                for (int i = 0; i < n; ++i)
                                {
                                        pos[peo[i]] = i;
                                }
                                int ans = 1;
                                for (int v = 1; v <= n; ++v)
                                {
                                        int cnt = 1;
                                        for (int to : g[v])
                                        {
                                                if (pos[to] > pos[v])
                                                {
                                                        cnt++;
                                                }
                                        }
                                        ans = std::max(ans, cnt);
                                }
                                return ans;
                        }
                };
        }
}

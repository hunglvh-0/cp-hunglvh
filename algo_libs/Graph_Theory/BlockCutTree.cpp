// Source: https://nyaannyaan.github.io/library/tree/block-cut-tree.hpp.html

namespace BlockCutTree
{
        namespace BlockCutTree
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
                        std::vector<int> estack;
                        std::vector<std::vector<int>> bcc;
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
                                estack.clear();
                                bcc.clear();
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
                        void makeComponentUntil(int stopEdge)
                        {
                                std::unordered_set<int> verts;
                                while (!estack.empty())
                                {
                                        int id = estack.back();
                                        estack.pop_back();
                                        auto [u, v] = edges[id];
                                        verts.insert(u);
                                        verts.insert(v);
                                        if (id == stopEdge)
                                        {
                                                break;
                                        }
                                }
                                bcc.push_back(std::vector<int>(verts.begin(), verts.end()));
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
                                                estack.push_back(id);
                                                child++;
                                                dfs(v, id);
                                                low[u] = std::min(low[u], low[v]);
                                                if (low[v] >= tin[u])
                                                {
                                                        if (pe != -1 or child > 1)
                                                        {
                                                                isArt[u] = 1;
                                                        }
                                                        makeComponentUntil(id);
                                                }
                                        }
                                        else
                                        {
                                                if (tin[v] < tin[u])
                                                {
                                                        estack.push_back(id);
                                                        low[u] = std::min(low[u], tin[v]);
                                                }
                                        }
                                }
                        }
                        void buildBCC()
                        {
                                for (int i = 1; i <= n; ++i)
                                {
                                        if (tin[i])
                                        {
                                                continue;
                                        }
                                        dfs(i, -1);
                                        if (!estack.empty())
                                        {
                                                makeComponentUntil(estack.front());
                                        }
                                }
                        }
                        struct Result
                        {
                                int tot = 0;
                                std::vector<std::vector<int>> tree;
                                std::vector<int> isArt;
                                std::vector<std::vector<int>> bcc;
                        };
                        Result buildTree()
                        {
                                buildBCC();
                                Result res;
                                res.isArt = isArt;
                                res.bcc = bcc;
                                res.tot = n + (int)bcc.size();
                                res.tree.assign(res.tot + 1,
                                                {});
                                for (int i = 0; i < (int)bcc.size(); ++i)
                                {
                                        int compNode = n + i + 1;
                                        for (int v : bcc[i])
                                        {
                                                res.tree[compNode].push_back(v);
                                                res.tree[v].push_back(compNode);
                                        }
                                }
                                return res;
                        }
                };
        }
}

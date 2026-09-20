// Source: https://oi-wiki.org/graph/virtual-tree/

namespace VirtualTree
{
        namespace VirtualTree
        {
                struct TreeData
                {
                        int root;
                        std::vector<int> nodes;
                        std::vector<std::pair<int, int>> edges;
                };
                class Builder
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
                        Builder(int n_ = 0)
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
                        void BuildLCA(int root = 1)
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
                        TreeData BuildVirtualTree(std::vector<int> nodes) const
                        {
                                auto cmpTin = [&](int a, int b)
                                {
                                        return tin[a] < tin[b];
                                };
                                std::sort(nodes.begin(), nodes.end(), cmpTin);
                                nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());
                                int k = (int)nodes.size();
                                for (int i = 0; i + 1 < k; ++i)
                                {
                                        nodes.push_back(LCA(nodes[i], nodes[i + 1]));
                                }
                                std::sort(nodes.begin(), nodes.end(), cmpTin);
                                nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());
                                std::vector<int> st;
                                std::vector<std::pair<int, int>> vedges;
                                st.reserve(nodes.size());
                                for (int v : nodes)
                                {
                                        while (!st.empty() and !IsAncestor(st.back(), v))
                                        {
                                                st.pop_back();
                                        }
                                        if (!st.empty())
                                        {
                                                vedges.push_back(
                                                    {st.back(), v});
                                        }
                                        st.push_back(v);
                                }
                                TreeData out;
                                out.root = nodes.empty() ? -1 : nodes[0];
                                out.nodes = std::move(nodes);
                                out.edges = std::move(vedges);
                                return out;
                        }
                };
        }
}

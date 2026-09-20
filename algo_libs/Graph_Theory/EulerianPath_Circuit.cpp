// Source: https://cp-algorithms.com/graph/euler_path.html

namespace EulerianPath_Circuit
{
        namespace EulerianPathCircuit
        {
                class Undirected
                {
                public:
                        int n;
                        std::vector<std::pair<int, int>> edges;
                        std::vector<std::vector<std::pair<int, int>>> g;
                        std::vector<int> deg;
                        Undirected(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                edges.clear();
                                g.assign(n + 1,
                                         {});
                                deg.assign(n + 1, 0);
                        }
                        void AddEdge(int u, int v)
                        {
                                int id = (int)edges.size();
                                edges.push_back(
                                    {u, v});
                                g[u].push_back(
                                    {v, id});
                                g[v].push_back(
                                    {u, id});
                                deg[u]++;
                                deg[v]++;
                        }
                        std::vector<int> GetPath() const
                        {
                                int odd = 0;
                                int start = -1;
                                for (int i = 1; i <= n; ++i)
                                {
                                        if (deg[i] & 1)
                                        {
                                                odd++;
                                        }
                                        if (deg[i] > 0 and start == -1)
                                        {
                                                start = i;
                                        }
                                }
                                if (!(odd == 0 or odd == 2))
                                {
                                        return {};
                                }
                                if (start == -1)
                                {
                                        return {
                                            1};
                                }
                                if (odd == 2)
                                {
                                        for (int i = 1; i <= n; ++i)
                                        {
                                                if (deg[i] & 1)
                                                {
                                                        start = i;
                                                        break;
                                                }
                                        }
                                }
                                std::vector<int> it(n + 1, 0);
                                std::vector<int> used(edges.size(), 0);
                                std::vector<int> st;
                                std::vector<int> path;
                                st.push_back(start);
                                while (!st.empty())
                                {
                                        int u = st.back();
                                        while (it[u] < (int)g[u].size() and used[g[u][it[u]].second])
                                        {
                                                it[u]++;
                                        }
                                        if (it[u] == (int)g[u].size())
                                        {
                                                path.push_back(u);
                                                st.pop_back();
                                        }
                                        else
                                        {
                                                std::pair<int, int> e = g[u][it[u]++];
                                                int v = e.first;
                                                int id = e.second;
                                                if (used[id])
                                                {
                                                        continue;
                                                }
                                                used[id] = 1;
                                                st.push_back(v);
                                        }
                                }
                                if ((int)path.size() != (int)edges.size() + 1)
                                {
                                        return {};
                                }
                                std::reverse(path.begin(), path.end());
                                return path;
                        }
                };
                class Directed
                {
                public:
                        int n;
                        std::vector<std::vector<std::pair<int, int>>> g;
                        std::vector<int> in;
                        std::vector<int> out;
                        int m;
                        Directed(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                                in.assign(n + 1, 0);
                                out.assign(n + 1, 0);
                                m = 0;
                        }
                        void AddEdge(int u, int v)
                        {
                                g[u].push_back(
                                    {v, m});
                                m++;
                                out[u]++;
                                in[v]++;
                        }
                        std::vector<int> GetPath() const
                        {
                                int start = -1;
                                int plus1 = 0;
                                int minus1 = 0;
                                for (int i = 1; i <= n; ++i)
                                {
                                        int d = out[i] - in[i];
                                        if (d == 1)
                                        {
                                                plus1++;
                                                start = i;
                                        }
                                        else if (d == -1)
                                        {
                                                minus1++;
                                        }
                                        else if (d != 0)
                                        {
                                                return {};
                                        }
                                }
                                if (!((plus1 == 1 and minus1 == 1) or (plus1 == 0 and minus1 == 0)))
                                {
                                        return {};
                                }
                                if (start == -1)
                                {
                                        for (int i = 1; i <= n; ++i)
                                        {
                                                if (out[i])
                                                {
                                                        start = i;
                                                        break;
                                                }
                                        }
                                        if (start == -1)
                                        {
                                                return {
                                                    1};
                                        }
                                }
                                std::vector<int> it(n + 1, 0);
                                std::vector<int> st;
                                std::vector<int> path;
                                st.push_back(start);
                                while (!st.empty())
                                {
                                        int u = st.back();
                                        if (it[u] == (int)g[u].size())
                                        {
                                                path.push_back(u);
                                                st.pop_back();
                                        }
                                        else
                                        {
                                                st.push_back(g[u][it[u]].first);
                                                it[u]++;
                                        }
                                }
                                if ((int)path.size() != m + 1)
                                {
                                        return {};
                                }
                                std::reverse(path.begin(), path.end());
                                return path;
                        }
                };
        }
}

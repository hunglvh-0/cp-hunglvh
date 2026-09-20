// Source: https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html

namespace Kruskal_Prim_MST
{
        namespace KruskalPrimMST
        {
                struct Edge
                {
                        int u;
                        int v;
                        long long w;
                };
                const long long INF = (long long)4e18;
                class DSU
                {
                public:
                        std::vector<int> p;
                        std::vector<int> sz;
                        DSU(int n = 0)
                        {
                                Init(n);
                        }
                        void Init(int n)
                        {
                                p.resize(n + 1);
                                sz.assign(n + 1, 1);
                                std::iota(p.begin(), p.end(), 0);
                        }
                        int Find(int x)
                        {
                                if (p[x] == x)
                                {
                                        return x;
                                }
                                p[x] = Find(p[x]);
                                return p[x];
                        }
                        bool Unite(int a, int b)
                        {
                                a = Find(a);
                                b = Find(b);
                                if (a == b)
                                {
                                        return false;
                                }
                                if (sz[a] < sz[b])
                                {
                                        std::swap(a, b);
                                }
                                p[b] = a;
                                sz[a] += sz[b];
                                return true;
                        }
                };
                std::pair<long long, std::vector<Edge>> Kruskal(int n, std::vector<Edge> edges)
                {
                        std::sort(
                            edges.begin(),
                            edges.end(),
                            [](const Edge &a, const Edge &b)
                            {
                                    if (a.w != b.w)
                                    {
                                            return a.w < b.w;
                                    }
                                    if (a.u != b.u)
                                    {
                                            return a.u < b.u;
                                    }
                                    return a.v < b.v;
                            });
                        DSU dsu(n);
                        long long total = 0;
                        std::vector<Edge> take;
                        for (const Edge &e : edges)
                        {
                                if (dsu.Unite(e.u, e.v))
                                {
                                        total += e.w;
                                        take.push_back(e);
                                }
                        }
                        if ((int)take.size() != n - 1)
                        {
                                return {
                                    INF,
                                    {}};
                        }
                        return {
                            total, take};
                }
                class PrimSolver
                {
                public:
                        int n;
                        std::vector<std::vector<std::pair<int, long long>>> g;
                        PrimSolver(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                        }
                        void AddEdge(int u, int v, long long w)
                        {
                                g[u].push_back(
                                    {v, w});
                                g[v].push_back(
                                    {u, w});
                        }
                        std::pair<long long, std::vector<int>> MST(int start = 1) const
                        {
                                std::vector<long long> best(n + 1, INF);
                                std::vector<int> par(n + 1, -1);
                                std::vector<int> used(n + 1, 0);
                                std::priority_queue<
                                    std::pair<long long, int>,
                                    std::vector<std::pair<long long, int>>,
                                    std::greater<std::pair<long long, int>>>
                                    pq;
                                best[start] = 0;
                                pq.push(
                                    {0, start});
                                long long total = 0;
                                int cnt = 0;
                                while (!pq.empty())
                                {
                                        std::pair<long long, int> top = pq.top();
                                        pq.pop();
                                        long long w = top.first;
                                        int u = top.second;
                                        if (used[u])
                                        {
                                                continue;
                                        }
                                        used[u] = 1;
                                        total += w;
                                        cnt++;
                                        for (const std::pair<int, long long> &e : g[u])
                                        {
                                                int v = e.first;
                                                long long c = e.second;
                                                if (!used[v] and c < best[v])
                                                {
                                                        best[v] = c;
                                                        par[v] = u;
                                                        pq.push(
                                                            {c, v});
                                                }
                                        }
                                }
                                if (cnt != n)
                                {
                                        return {
                                            INF,
                                            {}};
                                }
                                return {
                                    total, par};
                        }
                };
        }
}

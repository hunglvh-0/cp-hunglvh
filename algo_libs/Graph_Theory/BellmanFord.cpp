// Source: https://cp-algorithms.com/graph/bellman_ford.html

namespace BellmanFord
{
        namespace BellmanFord
        {
                struct Edge
                {
                        int u;
                        int v;
                        long long w;
                };
                const long long INF = (long long)4e18;
                class Solver
                {
                public:
                        int n;
                        std::vector<Edge> edges;
                        Solver(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                edges.clear();
                        }
                        void AddEdge(int u, int v, long long w)
                        {
                                edges.push_back(
                                    {u, v, w});
                        }
                        std::vector<long long> ShortestPath(int src, std::vector<int> &par, bool &negCycleReachable) const
                        {
                                std::vector<long long> dist(n + 1, INF);
                                par.assign(n + 1, -1);
                                dist[src] = 0;
                                for (int it = 1; it <= n - 1; ++it)
                                {
                                        bool any = false;
                                        for (const Edge &e : edges)
                                        {
                                                if (dist[e.u] == INF)
                                                {
                                                        continue;
                                                }
                                                if (dist[e.v] > dist[e.u] + e.w)
                                                {
                                                        dist[e.v] = dist[e.u] + e.w;
                                                        par[e.v] = e.u;
                                                        any = true;
                                                }
                                        }
                                        if (!any)
                                        {
                                                break;
                                        }
                                }
                                negCycleReachable = false;
                                for (const Edge &e : edges)
                                {
                                        if (dist[e.u] == INF)
                                        {
                                                continue;
                                        }
                                        if (dist[e.v] > dist[e.u] + e.w)
                                        {
                                                negCycleReachable = true;
                                                break;
                                        }
                                }
                                return dist;
                        }
                        std::vector<int> FindAnyNegativeCycle() const
                        {
                                std::vector<long long> d(n + 1, 0);
                                std::vector<int> p(n + 1, -1);
                                int x = -1;
                                for (int it = 1; it <= n; ++it)
                                {
                                        x = -1;
                                        for (const Edge &e : edges)
                                        {
                                                if (d[e.v] > d[e.u] + e.w)
                                                {
                                                        d[e.v] = d[e.u] + e.w;
                                                        p[e.v] = e.u;
                                                        x = e.v;
                                                }
                                        }
                                }
                                if (x == -1)
                                {
                                        return {};
                                }
                                for (int i = 1; i <= n; ++i)
                                {
                                        x = p[x];
                                }
                                std::vector<int> cyc;
                                int v = x;
                                do
                                {
                                        cyc.push_back(v);
                                        v = p[v];

                                } while (v != x and v != -1);
                                cyc.push_back(x);
                                std::reverse(cyc.begin(), cyc.end());
                                return cyc;
                        }
                };
        }
}

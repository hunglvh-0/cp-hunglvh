// Source: https://cp-algorithms.com/graph/dijkstra.html

namespace Dijkstra_SPFA
{
        namespace DijkstraSPFA
        {
                struct Edge
                {
                        int to;
                        long long w;
                };
                const long long INF = (long long)4e18;
                class Solver
                {
                public:
                        int n;
                        std::vector<std::vector<Edge>> g;
                        Solver(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                        }
                        void AddEdge(int u, int v, long long w, bool undirected = false)
                        {
                                g[u].push_back(
                                    {v, w});
                                if (undirected)
                                {
                                        g[v].push_back(
                                            {u, w});
                                }
                        }
                        std::vector<long long> Dijkstra(int src, std::vector<int> *parent = nullptr) const
                        {
                                std::vector<long long> dist(n + 1, INF);
                                std::vector<int> par(n + 1, -1);
                                std::priority_queue<
                                    std::pair<long long, int>,
                                    std::vector<std::pair<long long, int>>,
                                    std::greater<std::pair<long long, int>>>
                                    pq;
                                dist[src] = 0;
                                pq.push(
                                    {0, src});
                                while (!pq.empty())
                                {
                                        std::pair<long long, int> top = pq.top();
                                        pq.pop();
                                        long long du = top.first;
                                        int u = top.second;
                                        if (du != dist[u])
                                        {
                                                continue;
                                        }
                                        for (const Edge &e : g[u])
                                        {
                                                if (dist[e.to] > du + e.w)
                                                {
                                                        dist[e.to] = du + e.w;
                                                        par[e.to] = u;
                                                        pq.push(
                                                            {dist[e.to], e.to});
                                                }
                                        }
                                }
                                if (parent != nullptr)
                                {
                                        *parent = par;
                                }
                                return dist;
                        }
                        std::vector<long long> SPFA(int src, bool &hasNegCycle, std::vector<int> *parent = nullptr) const
                        {
                                std::vector<long long> dist(n + 1, INF);
                                std::vector<int> cnt(n + 1, 0);
                                std::vector<int> inq(n + 1, 0);
                                std::vector<int> par(n + 1, -1);
                                std::queue<int> q;
                                dist[src] = 0;
                                q.push(src);
                                inq[src] = 1;
                                hasNegCycle = false;
                                while (!q.empty() and !hasNegCycle)
                                {
                                        int u = q.front();
                                        q.pop();
                                        inq[u] = 0;
                                        for (const Edge &e : g[u])
                                        {
                                                if (dist[u] == INF)
                                                {
                                                        continue;
                                                }
                                                if (dist[e.to] > dist[u] + e.w)
                                                {
                                                        dist[e.to] = dist[u] + e.w;
                                                        par[e.to] = u;
                                                        if (!inq[e.to])
                                                        {
                                                                q.push(e.to);
                                                                inq[e.to] = 1;
                                                                cnt[e.to]++;
                                                                if (cnt[e.to] > n)
                                                                {
                                                                        hasNegCycle = true;
                                                                        break;
                                                                }
                                                        }
                                                }
                                        }
                                }
                                if (parent != nullptr)
                                {
                                        *parent = par;
                                }
                                return dist;
                        }
                };
        }
}

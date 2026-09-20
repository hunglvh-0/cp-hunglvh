// Source: https://cp-algorithms.com/graph/min_cost_flow.html

namespace MinCostMaxFlow
{
    namespace MinCostMaxFlow
    {
        struct Edge
        {
            int to;
            int rev;
            long long cap;
            long long cost;
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
            void AddEdge(int u, int v, long long cap, long long cost)
            {
                Edge a;
                a.to = v;
                a.rev = (int)g[v].size();
                a.cap = cap;
                a.cost = cost;
                Edge b;
                b.to = u;
                b.rev = (int)g[u].size();
                b.cap = 0;
                b.cost = -cost;
                g[u].push_back(a);
                g[v].push_back(b);
            }
            std::pair<long long, long long> Run(int s, int t, long long maxf = INF)
            {
                std::vector<long long> pot(n + 1, 0);
                std::vector<long long> dist(n + 1);
                std::vector<int> pv(n + 1, -1);
                std::vector<int> pe(n + 1, -1);
                long long flow = 0;
                long long cost = 0;
                std::vector<int> inq(n + 1, 0);
                std::queue<int> q;
                std::fill(dist.begin(), dist.end(), INF);
                dist[s] = 0;
                q.push(s);
                inq[s] = 1;
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    inq[u] = 0;
                    for (Edge &e : g[u])
                    {
                        if (e.cap <= 0 or dist[e.to] <= dist[u] + e.cost)
                        {
                            continue;
                        }
                        dist[e.to] = dist[u] + e.cost;
                        if (!inq[e.to])
                        {
                            q.push(e.to);
                            inq[e.to] = 1;
                        }
                    }
                }
                for (int i = 1; i <= n; ++i)
                {
                    if (dist[i] < INF)
                    {
                        pot[i] = dist[i];
                    }
                }
                while (flow < maxf)
                {
                    std::fill(dist.begin(), dist.end(), INF);
                    dist[s] = 0;
                    std::priority_queue<
                        std::pair<long long, int>,
                        std::vector<std::pair<long long, int>>,
                        std::greater<std::pair<long long, int>>>
                        pq;
                    pq.push(
                        {0, s});
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
                        for (int i = 0; i < (int)g[u].size(); ++i)
                        {
                            Edge &e = g[u][i];
                            if (e.cap <= 0)
                            {
                                continue;
                            }
                            long long w = e.cost + pot[u] - pot[e.to];
                            if (dist[e.to] > du + w)
                            {
                                dist[e.to] = du + w;
                                pv[e.to] = u;
                                pe[e.to] = i;
                                pq.push(
                                    {dist[e.to], e.to});
                            }
                        }
                    }
                    if (dist[t] == INF)
                    {
                        break;
                    }
                    for (int i = 1; i <= n; ++i)
                    {
                        if (dist[i] < INF)
                        {
                            pot[i] += dist[i];
                        }
                    }
                    long long add = maxf - flow;
                    for (int v = t; v != s; v = pv[v])
                    {
                        add = std::min(add, g[pv[v]][pe[v]].cap);
                    }
                    flow += add;
                    cost += add * pot[t];
                    for (int v = t; v != s; v = pv[v])
                    {
                        Edge &e = g[pv[v]][pe[v]];
                        e.cap -= add;
                        g[v][e.rev].cap += add;
                    }
                }
                return {
                    flow, cost};
            }
        };
    }
}

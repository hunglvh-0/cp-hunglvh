// Source: https://cp-algorithms.com/graph/dinic.html

namespace Dinic_MaxFlow
{
        namespace DinicMaxFlow
        {
                struct Edge
                {
                        int to;
                        int rev;
                        long long cap;
                };
                class Solver
                {
                public:
                        int n;
                        std::vector<std::vector<Edge>> g;
                        std::vector<int> lvl;
                        std::vector<int> it;
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
                        void AddEdge(int u, int v, long long cap)
                        {
                                Edge a;
                                a.to = v;
                                a.rev = (int)g[v].size();
                                a.cap = cap;
                                Edge b;
                                b.to = u;
                                b.rev = (int)g[u].size();
                                b.cap = 0;
                                g[u].push_back(a);
                                g[v].push_back(b);
                        }
                        bool BFS(int s, int t)
                        {
                                lvl.assign(n + 1, -1);
                                std::queue<int> q;
                                lvl[s] = 0;
                                q.push(s);
                                while (!q.empty())
                                {
                                        int u = q.front();
                                        q.pop();
                                        for (Edge &e : g[u])
                                        {
                                                if (e.cap <= 0 or lvl[e.to] != -1)
                                                {
                                                        continue;
                                                }
                                                lvl[e.to] = lvl[u] + 1;
                                                q.push(e.to);
                                        }
                                }
                                return lvl[t] != -1;
                        }
                        long long DFS(int u, int t, long long f)
                        {
                                if (!f or u == t)
                                {
                                        return f;
                                }
                                for (int &i = it[u]; i < (int)g[u].size(); ++i)
                                {
                                        Edge &e = g[u][i];
                                        if (e.cap <= 0 or lvl[e.to] != lvl[u] + 1)
                                        {
                                                continue;
                                        }
                                        long long got = DFS(e.to, t, std::min(f, e.cap));
                                        if (!got)
                                        {
                                                continue;
                                        }
                                        e.cap -= got;
                                        g[e.to][e.rev].cap += got;
                                        return got;
                                }
                                return 0;
                        }
                        long long MaxFlow(int s, int t)
                        {
                                long long flow = 0;
                                while (BFS(s, t))
                                {
                                        it.assign(n + 1, 0);
                                        while (true)
                                        {
                                                long long pushed = DFS(s, t, (long long)4e18);
                                                if (!pushed)
                                                {
                                                        break;
                                                }
                                                flow += pushed;
                                        }
                                }
                                return flow;
                        }
                };
        }
}

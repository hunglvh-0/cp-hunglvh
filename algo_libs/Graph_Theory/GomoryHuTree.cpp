// Source: https://en.wikipedia.org/wiki/Gomory%E2%80%93Hu_tree

namespace GomoryHuTree
{
        namespace GomoryHuTree
        {
                struct Edge
                {
                        int to;
                        int rev;
                        long long cap;
                };
                class Dinic
                {
                public:
                        int n;
                        std::vector<std::vector<Edge>> g;
                        std::vector<int> lvl;
                        std::vector<int> it;
                        Dinic(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                        }
                        void AddEdge(int u, int v, long long c)
                        {
                                Edge a;
                                a.to = v;
                                a.rev = (int)g[v].size();
                                a.cap = c;
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
                                                long long f = DFS(s, t, (long long)4e18);
                                                if (!f)
                                                {
                                                        break;
                                                }
                                                flow += f;
                                        }
                                }
                                return flow;
                        }
                        std::vector<int> MinCutSide(int s)
                        {
                                std::vector<int> vis(n + 1, 0);
                                std::queue<int> q;
                                q.push(s);
                                vis[s] = 1;
                                while (!q.empty())
                                {
                                        int u = q.front();
                                        q.pop();
                                        for (Edge &e : g[u])
                                        {
                                                if (e.cap <= 0 or vis[e.to])
                                                {
                                                        continue;
                                                }
                                                vis[e.to] = 1;
                                                q.push(e.to);
                                        }
                                }
                                return vis;
                        }
                };
                class Builder
                {
                public:
                        int n;
                        std::vector<std::tuple<int, int, long long>> edges;
                        std::vector<int> parent;
                        std::vector<long long> cutVal;
                        Builder(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                edges.clear();
                                parent.assign(n + 1, 1);
                                cutVal.assign(n + 1, 0);
                        }
                        void AddEdge(int u, int v, long long w)
                        {
                                edges.push_back(
                                    {u, v, w});
                        }
                        std::vector<std::tuple<int, int, long long>> BuildTree()
                        {
                                for (int i = 2; i <= n; ++i)
                                {
                                        parent[i] = 1;
                                }
                                for (int s = 2; s <= n; ++s)
                                {
                                        int t = parent[s];
                                        Dinic mf(n);
                                        for (const std::tuple<int, int, long long> &e : edges)
                                        {
                                                int u = std::get<0>(e);
                                                int v = std::get<1>(e);
                                                long long c = std::get<2>(e);
                                                mf.AddEdge(u, v, c);
                                                mf.AddEdge(v, u, c);
                                        }
                                        long long f = mf.MaxFlow(s, t);
                                        std::vector<int> side = mf.MinCutSide(s);
                                        for (int i = s + 1; i <= n; ++i)
                                        {
                                                if (parent[i] == t and side[i])
                                                {
                                                        parent[i] = s;
                                                }
                                        }
                                        if (side[parent[t]])
                                        {
                                                parent[s] = parent[t];
                                                parent[t] = s;
                                                cutVal[s] = cutVal[t];
                                                cutVal[t] = f;
                                        }
                                        else
                                        {
                                                cutVal[s] = f;
                                        }
                                }
                                std::vector<std::tuple<int, int, long long>> treeEdges;
                                for (int i = 2; i <= n; ++i)
                                {
                                        treeEdges.push_back(
                                            {i, parent[i], cutVal[i]});
                                }
                                return treeEdges;
                        }
                };
        }
}

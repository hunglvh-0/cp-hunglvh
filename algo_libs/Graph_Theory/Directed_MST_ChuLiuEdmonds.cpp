// Source: https://cp-algorithms.com/graph/chu-liu.html

namespace Directed_MST_ChuLiuEdmonds
{
    namespace DirectedMSTChuLiuEdmonds
    {
        struct Solver
        {
            struct Edge
            {
                int u;
                int v;
                long long w;
            };
            static constexpr long long INF = (long long)4e18;
            static std::pair<bool, long long> dmst(int n, int root, std::vector<Edge> edges)
            {
                long long ans = 0;
                while (true)
                {
                    std::vector<long long> in(n, INF);
                    std::vector<int> pre(n, -1);
                    for (auto e : edges)
                    {
                        if (e.u != e.v and e.w < in[e.v])
                        {
                            in[e.v] = e.w;
                            pre[e.v] = e.u;
                        }
                    }
                    in[root] = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        if (in[i] == INF)
                        {
                            return {
                                false, 0};
                        }
                    }
                    int cnt = 0;
                    std::vector<int> id(n, -1);
                    std::vector<int> vis(n, -1);
                    for (int i = 0; i < n; ++i)
                    {
                        ans += in[i];
                    }
                    for (int i = 0; i < n; ++i)
                    {
                        int v = i;
                        while (vis[v] != i and id[v] == -1 and v != root)
                        {
                            vis[v] = i;
                            v = pre[v];
                        }
                        if (v != root and id[v] == -1)
                        {
                            for (int u = pre[v]; u != v; u = pre[u])
                            {
                                id[u] = cnt;
                            }
                            id[v] = cnt++;
                        }
                    }
                    if (cnt == 0)
                    {
                        break;
                    }
                    for (int i = 0; i < n; ++i)
                    {
                        if (id[i] == -1)
                        {
                            id[i] = cnt++;
                        }
                    }
                    std::vector<Edge> ne;
                    ne.reserve(edges.size());
                    for (auto e : edges)
                    {
                        int u = id[e.u];
                        int v = id[e.v];
                        long long w = e.w;
                        if (u != v)
                        {
                            w -= in[e.v];
                        }
                        ne.push_back(
                            {u, v, w});
                    }
                    root = id[root];
                    n = cnt;
                    edges.swap(ne);
                }
                return {
                    true, ans};
            }
        };
    }
}

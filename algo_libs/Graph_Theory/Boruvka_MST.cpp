// Source: https://en.wikipedia.org/wiki/Boruvka%27s_algorithm

namespace Boruvka_MST
{
        namespace BoruvkaMST
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
                std::pair<long long, std::vector<Edge>> MST(int n, const std::vector<Edge> &edges)
                {
                        DSU dsu(n);
                        int comps = n;
                        long long total = 0;
                        std::vector<Edge> take;
                        while (comps > 1)
                        {
                                std::vector<int> best(n + 1, -1);
                                for (int i = 0; i < (int)edges.size(); ++i)
                                {
                                        int a = dsu.Find(edges[i].u);
                                        int b = dsu.Find(edges[i].v);
                                        if (a == b)
                                        {
                                                continue;
                                        }
                                        if (best[a] == -1 or edges[i].w < edges[best[a]].w)
                                        {
                                                best[a] = i;
                                        }
                                        if (best[b] == -1 or edges[i].w < edges[best[b]].w)
                                        {
                                                best[b] = i;
                                        }
                                }
                                bool any = false;
                                for (int v = 1; v <= n; ++v)
                                {
                                        int id = best[dsu.Find(v)];
                                        if (id == -1)
                                        {
                                                continue;
                                        }
                                        const Edge &e = edges[id];
                                        if (dsu.Unite(e.u, e.v))
                                        {
                                                comps--;
                                                total += e.w;
                                                take.push_back(e);
                                                any = true;
                                        }
                                }
                                if (!any)
                                {
                                        break;
                                }
                        }
                        if (comps != 1)
                        {
                                return {
                                    INF,
                                    {}};
                        }
                        return {
                            total, take};
                }
        }
}

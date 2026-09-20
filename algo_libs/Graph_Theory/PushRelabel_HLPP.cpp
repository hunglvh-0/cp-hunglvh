// Source: https://oi-wiki.org/graph/flow/max-flow/

namespace PushRelabel_HLPP
{
        namespace PushRelabelHLPP
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
                        std::vector<long long> ex;
                        std::vector<int> h;
                        std::vector<int> cur;
                        std::vector<int> cnt;
                        std::vector<std::vector<int>> bucket;
                        std::vector<char> inBucket;
                        int highest;
                        Solver(int n_ = 0)
                        {
                                Init(n_);
                        }
                        void Init(int n_)
                        {
                                n = n_;
                                g.assign(n + 1,
                                         {});
                                highest = 0;
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
                        void Push(int u, Edge &e, int s, int t)
                        {
                                if (ex[u] == 0 or e.cap == 0 or h[u] != h[e.to] + 1)
                                {
                                        return;
                                }
                                long long f = std::min(ex[u], e.cap);
                                e.cap -= f;
                                g[e.to][e.rev].cap += f;
                                ex[u] -= f;
                                ex[e.to] += f;
                                if (e.to != s and e.to != t and ex[e.to] > 0 and !inBucket[e.to])
                                {
                                        bucket[h[e.to]].push_back(e.to);
                                        inBucket[e.to] = 1;
                                        highest = std::max(highest, h[e.to]);
                                }
                        }
                        void Relabel(int u)
                        {
                                int nh = INT_MAX;
                                for (Edge &e : g[u])
                                {
                                        if (e.cap > 0)
                                        {
                                                nh = std::min(nh, h[e.to] + 1);
                                        }
                                }
                                if (nh == INT_MAX)
                                {
                                        nh = 2 * n;
                                }
                                cnt[h[u]]--;
                                h[u] = nh;
                                cnt[h[u]]++;
                                highest = std::max(highest, h[u]);
                        }
                        void Gap(int k)
                        {
                                for (int v = 1; v <= n; ++v)
                                {
                                        if (h[v] < k or h[v] >= n)
                                        {
                                                continue;
                                        }
                                        cnt[h[v]]--;
                                        h[v] = n + 1;
                                        cnt[h[v]]++;
                                }
                                highest = std::max(highest, n + 1);
                        }
                        void Discharge(int u, int s, int t)
                        {
                                while (ex[u] > 0)
                                {
                                        if (cur[u] == (int)g[u].size())
                                        {
                                                if (cnt[h[u]] == 1)
                                                {
                                                        Gap(h[u]);
                                                }
                                                Relabel(u);
                                                cur[u] = 0;
                                                continue;
                                        }
                                        Push(u, g[u][cur[u]], s, t);
                                        if (g[u][cur[u]].cap == 0 or h[u] != h[g[u][cur[u]].to] + 1)
                                        {
                                                cur[u]++;
                                        }
                                }
                        }
                        long long MaxFlow(int s, int t)
                        {
                                ex.assign(n + 1, 0);
                                h.assign(n + 1, 0);
                                cur.assign(n + 1, 0);
                                cnt.assign(2 * n + 5, 0);
                                bucket.assign(2 * n + 5,
                                              {});
                                inBucket.assign(n + 1, 0);
                                highest = 0;
                                h[s] = n;
                                cnt[0] = n - 1;
                                cnt[n] = 1;
                                for (Edge &e : g[s])
                                {
                                        if (e.cap == 0)
                                        {
                                                continue;
                                        }
                                        long long f = e.cap;
                                        e.cap = 0;
                                        g[e.to][e.rev].cap += f;
                                        ex[e.to] += f;
                                        ex[s] -= f;
                                        if (e.to != s and e.to != t and !inBucket[e.to])
                                        {
                                                bucket[0].push_back(e.to);
                                                inBucket[e.to] = 1;
                                        }
                                }
                                while (highest >= 0)
                                {
                                        while (highest >= 0 and bucket[highest].empty())
                                        {
                                                highest--;
                                        }
                                        if (highest < 0)
                                        {
                                                break;
                                        }
                                        int u = bucket[highest].back();
                                        bucket[highest].pop_back();
                                        inBucket[u] = 0;
                                        if (u == s or u == t or ex[u] == 0)
                                        {
                                                continue;
                                        }
                                        Discharge(u, s, t);
                                        if (ex[u] > 0 and !inBucket[u])
                                        {
                                                bucket[h[u]].push_back(u);
                                                inBucket[u] = 1;
                                                highest = std::max(highest, h[u]);
                                        }
                                }
                                return ex[t];
                        }
                };
        }
}

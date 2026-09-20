// Source: https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm

namespace BipartiteMatching_HopcroftKarp
{
        namespace BipartiteMatchingHopcroftKarp
        {
                class Solver
                {
                public:
                        int nL;
                        int nR;
                        std::vector<std::vector<int>> g;
                        std::vector<int> dist;
                        std::vector<int> matchL;
                        std::vector<int> matchR;
                        Solver(int L = 0, int R = 0)
                        {
                                Init(L, R);
                        }
                        void Init(int L, int R)
                        {
                                nL = L;
                                nR = R;
                                g.assign(nL + 1,
                                         {});
                                matchL.assign(nL + 1, 0);
                                matchR.assign(nR + 1, 0);
                                dist.assign(nL + 1, 0);
                        }
                        void AddEdge(int l, int r)
                        {
                                g[l].push_back(r);
                        }
                        bool BFS()
                        {
                                std::queue<int> q;
                                for (int u = 1; u <= nL; ++u)
                                {
                                        if (!matchL[u])
                                        {
                                                dist[u] = 0;
                                                q.push(u);
                                        }
                                        else
                                        {
                                                dist[u] = -1;
                                        }
                                }
                                bool ok = false;
                                while (!q.empty())
                                {
                                        int u = q.front();
                                        q.pop();
                                        for (int v : g[u])
                                        {
                                                int w = matchR[v];
                                                if (!w)
                                                {
                                                        ok = true;
                                                }
                                                else if (dist[w] == -1)
                                                {
                                                        dist[w] = dist[u] + 1;
                                                        q.push(w);
                                                }
                                        }
                                }
                                return ok;
                        }
                        bool DFS(int u)
                        {
                                for (int v : g[u])
                                {
                                        int w = matchR[v];
                                        if (!w or (dist[w] == dist[u] + 1 and DFS(w)))
                                        {
                                                matchL[u] = v;
                                                matchR[v] = u;
                                                return true;
                                        }
                                }
                                dist[u] = -1;
                                return false;
                        }
                        int MaxMatching()
                        {
                                int ans = 0;
                                while (BFS())
                                {
                                        for (int u = 1; u <= nL; ++u)
                                        {
                                                if (!matchL[u] and DFS(u))
                                                {
                                                        ans++;
                                                }
                                        }
                                }
                                return ans;
                        }
                };
        }
}

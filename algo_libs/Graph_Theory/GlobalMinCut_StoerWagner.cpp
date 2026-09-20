// Source: https://cp-algorithms.com/graph/stoer_wagner.html

namespace GlobalMinCut_StoerWagner
{
        namespace GlobalMinCutStoerWagner
        {
                const long long INF = (long long)4e18;
                std::pair<long long, std::vector<int>> MinCut(int n, const std::vector<std::tuple<int, int, long long>> &edges)
                {
                        std::vector<std::vector<long long>> w(n, std::vector<long long>(n, 0));
                        for (const std::tuple<int, int, long long> &e : edges)
                        {
                                int u = std::get<0>(e) - 1;
                                int v = std::get<1>(e) - 1;
                                long long c = std::get<2>(e);
                                w[u][v] += c;
                                w[v][u] += c;
                        }
                        std::vector<int> vtx(n);
                        std::iota(vtx.begin(), vtx.end(), 0);
                        long long best = INF;
                        std::vector<int> bestCut;
                        while ((int)vtx.size() > 1)
                        {
                                int m = (int)vtx.size();
                                std::vector<long long> dist(m, 0);
                                std::vector<char> used(m, 0);
                                int prev = -1;
                                int sel = -1;
                                for (int it = 0; it < m; ++it)
                                {
                                        sel = -1;
                                        for (int i = 0; i < m; ++i)
                                        {
                                                if (!used[i] and (sel == -1 or dist[i] > dist[sel]))
                                                {
                                                        sel = i;
                                                }
                                        }
                                        used[sel] = 1;
                                        if (it == m - 1)
                                        {
                                                if (dist[sel] < best)
                                                {
                                                        best = dist[sel];
                                                        bestCut =
                                                            {
                                                                vtx[sel]};
                                                }
                                                if (prev != -1)
                                                {
                                                        for (int i = 0; i < m; ++i)
                                                        {
                                                                if (i == sel or i == prev)
                                                                {
                                                                        continue;
                                                                }
                                                                w[vtx[prev]][vtx[i]] += w[vtx[sel]][vtx[i]];
                                                                w[vtx[i]][vtx[prev]] = w[vtx[prev]][vtx[i]];
                                                        }
                                                        vtx.erase(vtx.begin() + sel);
                                                }
                                                break;
                                        }
                                        prev = sel;
                                        for (int i = 0; i < m; ++i)
                                        {
                                                if (!used[i])
                                                {
                                                        dist[i] += w[vtx[sel]][vtx[i]];
                                                }
                                        }
                                }
                        }
                        for (int &x : bestCut)
                        {
                                x++;
                        }
                        return {
                            best, bestCut};
                }
        }
}

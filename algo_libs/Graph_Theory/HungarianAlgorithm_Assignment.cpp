// Source: https://cp-algorithms.com/graph/hungarian-algorithm.html

namespace HungarianAlgorithm_Assignment
{
    namespace HungarianAlgorithmAssignment
    {
        class Solver
        {
        public:
            static std::pair<long long, std::vector<int>> MaxWeight(const std::vector<std::vector<long long>> &w)
            {
                int n = (int)w.size();
                int m = n ? (int)w[0].size() : 0;
                if (n == 0 or m == 0)
                {
                    return {
                        0,
                        {}};
                }
                bool trans = false;
                std::vector<std::vector<long long>> a = w;
                if (n > m)
                {
                    trans = true;
                    std::vector<std::vector<long long>> b(m, std::vector<long long>(n));
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < m; ++j)
                        {
                            b[j][i] = a[i][j];
                        }
                    }
                    a.swap(b);
                    std::swap(n, m);
                }
                std::vector<long long> u(n + 1, 0);
                std::vector<long long> v(m + 1, 0);
                std::vector<int> p(m + 1, 0);
                std::vector<int> way(m + 1, 0);
                for (int i = 1; i <= n; ++i)
                {
                    p[0] = i;
                    int j0 = 0;
                    std::vector<long long> minv(m + 1, (long long)4e18);
                    std::vector<char> used(m + 1, 0);
                    do
                    {
                        used[j0] = 1;
                        int i0 = p[j0];
                        int j1 = 0;
                        long long delta = (long long)4e18;
                        for (int j = 1; j <= m; ++j)
                        {
                            if (used[j])
                            {
                                continue;
                            }
                            long long cur = -a[i0 - 1][j - 1] - u[i0] - v[j];
                            if (cur < minv[j])
                            {
                                minv[j] = cur;
                                way[j] = j0;
                            }
                            if (minv[j] < delta)
                            {
                                delta = minv[j];
                                j1 = j;
                            }
                        }
                        for (int j = 0; j <= m; ++j)
                        {
                            if (used[j])
                            {
                                u[p[j]] += delta;
                                v[j] -= delta;
                            }
                            else
                            {
                                minv[j] -= delta;
                            }
                        }
                        j0 = j1;

                    } while (p[j0] != 0);
                    do
                    {
                        int j1 = way[j0];
                        p[j0] = p[j1];
                        j0 = j1;

                    } while (j0 != 0);
                }
                std::vector<int> matchRow(n, -1);
                for (int j = 1; j <= m; ++j)
                {
                    if (p[j])
                    {
                        matchRow[p[j] - 1] = j - 1;
                    }
                }
                long long best = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (matchRow[i] != -1)
                    {
                        best += a[i][matchRow[i]];
                    }
                }
                if (!trans)
                {
                    return {
                        best, matchRow};
                }
                std::vector<int> matchLeft((int)w.size(), -1);
                for (int i = 0; i < n; ++i)
                {
                    if (matchRow[i] != -1)
                    {
                        matchLeft[matchRow[i]] = i;
                    }
                }
                return {
                    best, matchLeft};
            }
            static std::pair<long long, std::vector<int>> MinWeight(const std::vector<std::vector<long long>> &cost)
            {
                std::vector<std::vector<long long>> neg = cost;
                for (std::vector<long long> &row : neg)
                {
                    for (long long &x : row)
                    {
                        x = -x;
                    }
                }
                std::pair<long long, std::vector<int>> ans = MaxWeight(neg);
                ans.first = -ans.first;
                return ans;
            }
        };
    }
}

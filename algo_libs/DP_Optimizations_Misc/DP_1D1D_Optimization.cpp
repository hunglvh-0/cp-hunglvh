// Source: https://usaco.guide/plat/convex-hull-trick

namespace DP_1D1D_Optimization
{
        namespace DP1D1DOptimization
        {
                struct Line
                {
                        long long m;
                        long long b;
                        long long f(long long x) const
                        {
                                return (long long)((__int128)m * x + b);
                        }
                };
                bool bad(const Line &a, const Line &b, const Line &c)
                {
                        __int128 x1 = (__int128)(a.b - b.b) * (c.m - b.m);
                        __int128 x2 = (__int128)(b.b - c.b) * (b.m - a.m);
                        return x1 >= x2;
                }
                struct MonotoneCHTMin
                {
                        deque<Line> q;
                        void clear()
                        {
                                q.clear();
                        }
                        void add(long long m, long long b)
                        {
                                Line ln{
                                    m, b};
                                while ((int)q.size() >= 2 and bad(q[(int)q.size() - 2], q.back(), ln))
                                {
                                        q.pop_back();
                                }
                                q.push_back(ln);
                        }
                        long long query(long long x)
                        {
                                while ((int)q.size() >= 2 and q[0].f(x) >= q[1].f(x))
                                {
                                        q.pop_front();
                                }
                                return q.front().f(x);
                        }
                };
                vector<long long> solve_quadratic_dp(const vector<long long> &x, long long C)
                {
                        int n = (int)x.size();
                        vector<long long> dp(n, 0);
                        if (!n)
                        {
                                return dp;
                        }
                        MonotoneCHTMin cht;
                        dp[0] = 0;
                        cht.add(-2 * x[0], dp[0] + x[0] * x[0]);
                        for (int i = 1; i < n; ++i)
                        {
                                long long best = cht.query(x[i]);
                                dp[i] = x[i] * x[i] + C + best;
                                cht.add(-2 * x[i], dp[i] + x[i] * x[i]);
                        }
                        return dp;
                }
        }
}

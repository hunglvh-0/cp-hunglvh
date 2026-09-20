// Source: https://cp-algorithms.com/data_structures/fenwick.html#finding-sum-in-two-dimensional-array

namespace FenwickTree_BIT_2D
{
        namespace FenwickTreeBIT2D
        {
                struct BIT2D
                {
                        int n;
                        int m;
                        vector<vector<long long>> bit;
                        BIT2D(int _n = 0, int _m = 0)
                        {
                                init(_n, _m);
                        }
                        void init(int _n, int _m)
                        {
                                n = _n;
                                m = _m;
                                bit.assign(n + 1, vector<long long>(m + 1, 0));
                        }
                        void add(int x, int y, long long val)
                        {
                                for (int i = x; i <= n; i += i & -i)
                                {
                                        for (int j = y; j <= m; j += j & -j)
                                        {
                                                bit[i][j] += val;
                                        }
                                }
                        }
                        long long sum_prefix(int x, int y) const
                        {
                                long long r = 0;
                                for (int i = x; i > 0; i -= i & -i)
                                {
                                        for (int j = y; j > 0; j -= j & -j)
                                        {
                                                r += bit[i][j];
                                        }
                                }
                                return r;
                        }
                        long long sum_rect(int x1, int y1, int x2, int y2) const
                        {
                                if (x1 > x2 or y1 > y2)
                                {
                                        return 0;
                                }
                                return sum_prefix(x2, y2) - sum_prefix(x1 - 1, y2) - sum_prefix(x2, y1 - 1) + sum_prefix(x1 - 1, y1 - 1);
                        }
                };
        }
}

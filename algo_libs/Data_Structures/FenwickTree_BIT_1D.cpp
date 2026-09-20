// Source: https://cp-algorithms.com/data_structures/fenwick.html

namespace FenwickTree_BIT_1D
{
        namespace FenwickTreeBIT1D
        {
                struct BIT
                {
                        int n;
                        vector<long long> bit;
                        BIT(int _n = 0)
                        {
                                init(_n);
                        }
                        void init(int _n)
                        {
                                n = _n;
                                bit.assign(n + 1, 0);
                        }
                        void add(int idx, long long val)
                        {
                                for (int x = idx; x <= n; x += x & -x)
                                {
                                        bit[x] += val;
                                }
                        }
                        long long sum_prefix(int idx) const
                        {
                                long long r = 0;
                                for (int x = idx; x > 0; x -= x & -x)
                                {
                                        r += bit[x];
                                }
                                return r;
                        }
                        long long sum_range(int l, int r) const
                        {
                                if (l > r)
                                {
                                        return 0;
                                }
                                return sum_prefix(r) - sum_prefix(l - 1);
                        }
                        void build(const vector<long long> &a)
                        {
                                init((int)a.size() - 1);
                                for (int i = 1; i <= n; ++i)
                                {
                                        add(i, a[i]);
                                }
                        }
                };
        }
}

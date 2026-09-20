// Source: https://cp-algorithms.com/data_structures/sqrt_decomposition.html

namespace SqrtDecomposition
{
        namespace SqrtDecompositionDS
        {
                struct SqrtDecomp
                {
                        int n;
                        int B;
                        int nb;
                        vector<long long> a;
                        vector<long long> blk;
                        SqrtDecomp(int _n = 0)
                        {
                                init(_n);
                        }
                        void init(int _n)
                        {
                                n = _n;
                                B = max(1, (int)sqrt((double)max(1, n)));
                                nb = (n + B - 1) / B;
                                a.assign(n + 1, 0);
                                blk.assign(nb, 0);
                        }
                        void build(const vector<long long> &v)
                        {
                                init((int)v.size() - 1);
                                for (int i = 1; i <= n; ++i)
                                {
                                        a[i] = v[i];
                                        blk[(i - 1) / B] += a[i];
                                }
                        }
                        void point_add(int i, long long delta)
                        {
                                a[i] += delta;
                                blk[(i - 1) / B] += delta;
                        }
                        void point_set(int i, long long val)
                        {
                                long long d = val - a[i];
                                a[i] = val;
                                blk[(i - 1) / B] += d;
                        }
                        long long query(int l, int r) const
                        {
                                if (l > r)
                                {
                                        return 0;
                                }
                                long long ans = 0;
                                int cL = (l - 1) / B;
                                int cR = (r - 1) / B;
                                if (cL == cR)
                                {
                                        for (int i = l; i <= r; ++i)
                                        {
                                                ans += a[i];
                                        }
                                        return ans;
                                }
                                int endL = (cL + 1) * B;
                                for (int i = l; i <= min(n, endL); ++i)
                                {
                                        ans += a[i];
                                }
                                for (int b = cL + 1; b <= cR - 1; ++b)
                                {
                                        ans += blk[b];
                                }
                                for (int i = cR * B + 1; i <= r; ++i)
                                {
                                        ans += a[i];
                                }
                                return ans;
                        }
                };
        }
}

// Source: https://cp-algorithms.com/algebra/binary-exp.html

namespace Matrix_Exponentiation
{
        namespace MatrixExponentiation
        {
                struct Mat
                {
                        int n;
                        long long mod;
                        vector<vector<long long>> a;
                        Mat(int _n = 0, long long _mod = 1000000007LL, bool id = false)
                        {
                                n = _n;
                                mod = _mod;
                                a.assign(n, vector<long long>(n, 0));
                                if (id)
                                {
                                        for (int i = 0; i < n; ++i)
                                        {
                                                a[i][i] = 1 % mod;
                                        }
                                }
                        }
                        static Mat I(int n, long long mod)
                        {
                                return Mat(n, mod, true);
                        }
                        vector<long long> &operator[](int i)
                        {
                                return a[i];
                        }
                        const vector<long long> &operator[](int i) const
                        {
                                return a[i];
                        }
                };
                Mat mul(const Mat &x, const Mat &y)
                {
                        Mat r(x.n, x.mod, false);
                        for (int i = 0; i < x.n; ++i)
                        {
                                for (int k = 0; k < x.n; ++k)
                                {
                                        if (!x[i][k])
                                        {
                                                continue;
                                        }
                                        for (int j = 0; j < x.n; ++j)
                                        {
                                                if (!y[k][j])
                                                {
                                                        continue;
                                                }
                                                r[i][j] += (long long)((__int128)x[i][k] * y[k][j] % x.mod);
                                                if (r[i][j] >= x.mod)
                                                {
                                                        r[i][j] %= x.mod;
                                                }
                                        }
                                }
                        }
                        return r;
                }
                Mat pw(Mat b, long long e)
                {
                        Mat r = Mat::I(b.n, b.mod);
                        while (e)
                        {
                                if (e & 1)
                                {
                                        r = mul(r, b);
                                }
                                b = mul(b, b);
                                e >>= 1;
                        }
                        return r;
                }
                vector<long long> apply(const Mat &m, const vector<long long> &v)
                {
                        vector<long long> r(m.n, 0);
                        for (int i = 0; i < m.n; ++i)
                        {
                                for (int j = 0; j < m.n; ++j)
                                {
                                        if (!m[i][j] or !v[j])
                                        {
                                                continue;
                                        }
                                        r[i] += (long long)((__int128)m[i][j] * (v[j] % m.mod) % m.mod);
                                        if (r[i] >= m.mod)
                                        {
                                                r[i] %= m.mod;
                                        }
                                }
                        }
                        return r;
                }
        }
}

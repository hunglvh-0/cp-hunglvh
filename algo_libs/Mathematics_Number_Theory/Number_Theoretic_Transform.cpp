// Source: https://cp-algorithms.com/algebra/fft.html#number-theoretic-transform

namespace Number_Theoretic_Transform
{
        namespace NumberTheoreticTransform
        {
                const int mod = 998244353;
                const int primitive_root = 3;
                int pw(int a, long long e)
                {
                        int r = 1;
                        while (e)
                        {
                                if (e & 1)
                                {
                                        r = (int)(1LL * r * a % mod);
                                }
                                a = (int)(1LL * a * a % mod);
                                e >>= 1;
                        }
                        return r;
                }
                int inv(int a)
                {
                        return pw(a, mod - 2);
                }
                void ntt(vector<int> &a, bool invert)
                {
                        int n = (int)a.size();
                        for (int i = 1, j = 0; i < n; ++i)
                        {
                                int bit = n >> 1;
                                while (j & bit)
                                {
                                        j ^= bit;
                                        bit >>= 1;
                                }
                                j ^= bit;
                                if (i < j)
                                {
                                        swap(a[i], a[j]);
                                }
                        }
                        for (int len = 2; len <= n; len <<= 1)
                        {
                                int wlen = pw(primitive_root, (mod - 1) / len);
                                if (invert)
                                {
                                        wlen = inv(wlen);
                                }
                                for (int i = 0; i < n; i += len)
                                {
                                        int w = 1;
                                        for (int j = 0; j < (len >> 1); ++j)
                                        {
                                                int u = a[i + j];
                                                int v = (int)(1LL * a[i + j + (len >> 1)] * w % mod);
                                                a[i + j] = u + v;
                                                if (a[i + j] >= mod)
                                                {
                                                        a[i + j] -= mod;
                                                }
                                                a[i + j + (len >> 1)] = u - v;
                                                if (a[i + j + (len >> 1)] < 0)
                                                {
                                                        a[i + j + (len >> 1)] += mod;
                                                }
                                                w = (int)(1LL * w * wlen % mod);
                                        }
                                }
                        }
                        if (invert)
                        {
                                int n_inv = inv(n);
                                for (int &x : a)
                                {
                                        x = (int)(1LL * x * n_inv % mod);
                                }
                        }
                }
                vector<int> multiply(vector<int> a, vector<int> b)
                {
                        if (a.empty() or b.empty())
                        {
                                return {};
                        }
                        int need = (int)a.size() + (int)b.size() - 1;
                        int n = 1;
                        while (n < need)
                        {
                                n <<= 1;
                        }
                        a.resize(n);
                        b.resize(n);
                        ntt(a, false);
                        ntt(b, false);
                        for (int i = 0; i < n; ++i)
                        {
                                a[i] = (int)(1LL * a[i] * b[i] % mod);
                        }
                        ntt(a, true);
                        a.resize(need);
                        return a;
                }
        }
}

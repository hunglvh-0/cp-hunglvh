// Source: https://cp-algorithms.com/algebra/polynomial.html

namespace Polynomial_Operations
{
        namespace PolynomialOperations
        {
                const int mod = 998244353;
                const int primitive_root = 3;
                int addmod(int a, int b)
                {
                        a += b;
                        if (a >= mod)
                        {
                                a -= mod;
                        }
                        return a;
                }
                int submod(int a, int b)
                {
                        a -= b;
                        if (a < 0)
                        {
                                a += mod;
                        }
                        return a;
                }
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
                void normalize(vector<int> &a)
                {
                        while (!a.empty() and !a.back())
                        {
                                a.pop_back();
                        }
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
                                                a[i + j] = addmod(u, v);
                                                a[i + j + (len >> 1)] = submod(u, v);
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
                vector<int> multiply(vector<int> a, vector<int> b, int need = -1)
                {
                        if (a.empty() or b.empty())
                        {
                                return {};
                        }
                        int out = (need == -1 ? (int)a.size() + (int)b.size() - 1 : need);
                        int n = 1;
                        while (n < out)
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
                        a.resize(out);
                        return a;
                }
                vector<int> take(const vector<int> &a, int n)
                {
                        vector<int> r(min((int)a.size(), n));
                        for (int i = 0; i < (int)r.size(); ++i)
                        {
                                r[i] = a[i];
                        }
                        return r;
                }
                vector<int> derivative(const vector<int> &a)
                {
                        if ((int)a.size() <= 1)
                        {
                                return {
                                    0};
                        }
                        vector<int> r((int)a.size() - 1);
                        for (int i = 1; i < (int)a.size(); ++i)
                        {
                                r[i - 1] = (int)(1LL * i * a[i] % mod);
                        }
                        return r;
                }
                vector<int> integral(const vector<int> &a)
                {
                        vector<int> r((int)a.size() + 1);
                        r[0] = 0;
                        static vector<int> invs =
                            {
                                0, 1};
                        int n = (int)a.size();
                        if ((int)invs.size() <= n)
                        {
                                int old = (int)invs.size();
                                invs.resize(n + 1);
                                for (int i = old; i <= n; ++i)
                                {
                                        invs[i] = mod - (int)(1LL * (mod / i) * invs[mod % i] % mod);
                                }
                        }
                        for (int i = 0; i < n; ++i)
                        {
                                r[i + 1] = (int)(1LL * a[i] * invs[i + 1] % mod);
                        }
                        return r;
                }
                vector<int> poly_inv(const vector<int> &a, int n)
                {
                        vector<int> r(1, inv(a[0]));
                        while ((int)r.size() < n)
                        {
                                int m = (int)r.size() << 1;
                                vector<int> f = take(a, m);
                                vector<int> fr = multiply(f, r, m);
                                for (int i = 0; i < m; ++i)
                                {
                                        fr[i] = (i ? submod(0, fr[i]) : submod(2, fr[i]));
                                }
                                r = multiply(r, fr, m);
                        }
                        r.resize(n);
                        return r;
                }
                vector<int> poly_log(const vector<int> &a, int n)
                {
                        vector<int> da = derivative(a);
                        vector<int> ia = poly_inv(a, n);
                        vector<int> r = multiply(da, ia, n - 1);
                        r = integral(r);
                        r.resize(n);
                        return r;
                }
                vector<int> poly_exp(const vector<int> &a, int n)
                {
                        vector<int> r(1, 1);
                        while ((int)r.size() < n)
                        {
                                int m = (int)r.size() << 1;
                                vector<int> ln_r = poly_log(r, m);
                                vector<int> q(m, 0);
                                for (int i = 0; i < m and i < (int)a.size(); ++i)
                                {
                                        q[i] = a[i];
                                }
                                for (int i = 0; i < m; ++i)
                                {
                                        q[i] = submod(q[i], i < (int)ln_r.size() ? ln_r[i] : 0);
                                }
                                q[0] = addmod(q[0], 1);
                                r = multiply(r, q, m);
                        }
                        r.resize(n);
                        return r;
                }
                vector<int> poly_sqrt(const vector<int> &a, int n, int s0)
                {
                        int inv2 = (mod + 1) >> 1;
                        vector<int> r(1, s0);
                        while ((int)r.size() < n)
                        {
                                int m = (int)r.size() << 1;
                                vector<int> f = take(a, m);
                                vector<int> ir = poly_inv(r, m);
                                vector<int> t = multiply(f, ir, m);
                                r.resize(m);
                                for (int i = 0; i < m; ++i)
                                {
                                        int x = i < (int)t.size() ? t[i] : 0;
                                        r[i] = (int)(1LL * addmod(r[i], x) * inv2 % mod);
                                }
                        }
                        r.resize(n);
                        return r;
                }
                pair<vector<int>, vector<int>> poly_divmod(vector<int> a, vector<int> b)
                {
                        normalize(a);
                        normalize(b);
                        if (b.empty())
                        {
                                return {
                                    {},
                                    {}};
                        }
                        if (a.empty() or (int) a.size() < (int)b.size())
                        {
                                return {
                                    {0}, a};
                        }
                        int k = (int)a.size() - (int)b.size() + 1;
                        vector<int> ra = a;
                        vector<int> rb = b;
                        reverse(ra.begin(), ra.end());
                        reverse(rb.begin(), rb.end());
                        vector<int> rb_inv = poly_inv(rb, k);
                        vector<int> q = multiply(ra, rb_inv, k);
                        q.resize(k);
                        reverse(q.begin(), q.end());
                        normalize(q);
                        vector<int> prod = multiply(b, q);
                        vector<int> r(max((int)a.size(), (int)prod.size()), 0);
                        for (int i = 0; i < (int)a.size(); ++i)
                        {
                                r[i] = a[i];
                        }
                        for (int i = 0; i < (int)prod.size(); ++i)
                        {
                                r[i] = submod(r[i], prod[i]);
                        }
                        if ((int)r.size() >= (int)b.size())
                        {
                                r.resize((int)b.size() - 1);
                        }
                        normalize(r);
                        if (r.empty())
                        {
                                r.push_back(0);
                        }
                        return {
                            q, r};
                }
        }
}

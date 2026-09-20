// Source: https://oi-wiki.org/math/poly/fwt/

namespace Fast_Walsh_Hadamard
{
        namespace FastWalshHadamard
        {
                long long pw(long long a, long long e, long long mod)
                {
                        long long r = 1 % mod;
                        a %= mod;
                        while (e)
                        {
                                if (e & 1)
                                {
                                        r = (long long)((__int128)r * a % mod);
                                }
                                a = (long long)((__int128)a * a % mod);
                                e >>= 1;
                        }
                        return r;
                }
                long long inv(long long a, long long mod)
                {
                        return pw(a, mod - 2, mod);
                }
                void xor_fwt(vector<long long> &a, int tp, long long mod = 0)
                {
                        int n = (int)a.size();
                        for (int len = 1; len < n; len <<= 1)
                        {
                                for (int i = 0; i < n; i += (len << 1))
                                {
                                        for (int j = 0; j < len; ++j)
                                        {
                                                long long x = a[i + j];
                                                long long y = a[i + j + len];
                                                if (mod)
                                                {
                                                        a[i + j] = (x + y) % mod;
                                                        a[i + j + len] = (x - y) % mod;
                                                        if (a[i + j + len] < 0)
                                                        {
                                                                a[i + j + len] += mod;
                                                        }
                                                }
                                                else
                                                {
                                                        a[i + j] = x + y;
                                                        a[i + j + len] = x - y;
                                                }
                                        }
                                }
                        }
                        if (tp == -1)
                        {
                                if (mod)
                                {
                                        long long iv = inv(n, mod);
                                        for (int i = 0; i < n; ++i)
                                        {
                                                a[i] = (long long)((__int128)a[i] * iv % mod);
                                        }
                                }
                                else
                                {
                                        for (int len = 1; len < n; len <<= 1)
                                        {
                                                for (int i = 0; i < n; i += (len << 1))
                                                {
                                                        for (int j = 0; j < len; ++j)
                                                        {
                                                                a[i + j] /= 2;
                                                                a[i + j + len] /= 2;
                                                        }
                                                }
                                        }
                                }
                        }
                }
                void or_fwt(vector<long long> &a, int tp, long long mod = 0)
                {
                        int n = (int)a.size();
                        for (int len = 1; len < n; len <<= 1)
                        {
                                for (int i = 0; i < n; i += (len << 1))
                                {
                                        for (int j = 0; j < len; ++j)
                                        {
                                                if (tp == 1)
                                                {
                                                        if (mod)
                                                        {
                                                                a[i + j + len] += a[i + j];
                                                                a[i + j + len] %= mod;
                                                        }
                                                        else
                                                        {
                                                                a[i + j + len] += a[i + j];
                                                        }
                                                }
                                                else
                                                {
                                                        if (mod)
                                                        {
                                                                a[i + j + len] -= a[i + j];
                                                                a[i + j + len] %= mod;
                                                                if (a[i + j + len] < 0)
                                                                {
                                                                        a[i + j + len] += mod;
                                                                }
                                                        }
                                                        else
                                                        {
                                                                a[i + j + len] -= a[i + j];
                                                        }
                                                }
                                        }
                                }
                        }
                }
                void and_fwt(vector<long long> &a, int tp, long long mod = 0)
                {
                        int n = (int)a.size();
                        for (int len = 1; len < n; len <<= 1)
                        {
                                for (int i = 0; i < n; i += (len << 1))
                                {
                                        for (int j = 0; j < len; ++j)
                                        {
                                                if (tp == 1)
                                                {
                                                        if (mod)
                                                        {
                                                                a[i + j] += a[i + j + len];
                                                                a[i + j] %= mod;
                                                        }
                                                        else
                                                        {
                                                                a[i + j] += a[i + j + len];
                                                        }
                                                }
                                                else
                                                {
                                                        if (mod)
                                                        {
                                                                a[i + j] -= a[i + j + len];
                                                                a[i + j] %= mod;
                                                                if (a[i + j] < 0)
                                                                {
                                                                        a[i + j] += mod;
                                                                }
                                                        }
                                                        else
                                                        {
                                                                a[i + j] -= a[i + j + len];
                                                        }
                                                }
                                        }
                                }
                        }
                }
                vector<long long> conv_xor(vector<long long> a, vector<long long> b, long long mod = 0)
                {
                        if (a.empty() and b.empty())
                        {
                                return {};
                        }
                        int n = 1;
                        int need = (int)max(a.size(), b.size());
                        while (n < need)
                        {
                                n <<= 1;
                        }
                        a.resize(n);
                        b.resize(n);
                        xor_fwt(a, 1, mod);
                        xor_fwt(b, 1, mod);
                        for (int i = 0; i < n; ++i)
                        {
                                if (mod)
                                {
                                        a[i] = (long long)((__int128)a[i] * b[i] % mod);
                                }
                                else
                                {
                                        a[i] *= b[i];
                                }
                        }
                        xor_fwt(a, -1, mod);
                        return a;
                }
                vector<long long> conv_or(vector<long long> a, vector<long long> b, long long mod = 0)
                {
                        if (a.empty() and b.empty())
                        {
                                return {};
                        }
                        int n = 1;
                        int need = (int)max(a.size(), b.size());
                        while (n < need)
                        {
                                n <<= 1;
                        }
                        a.resize(n);
                        b.resize(n);
                        or_fwt(a, 1, mod);
                        or_fwt(b, 1, mod);
                        for (int i = 0; i < n; ++i)
                        {
                                if (mod)
                                {
                                        a[i] = (long long)((__int128)a[i] * b[i] % mod);
                                }
                                else
                                {
                                        a[i] *= b[i];
                                }
                        }
                        or_fwt(a, -1, mod);
                        return a;
                }
                vector<long long> conv_and(vector<long long> a, vector<long long> b, long long mod = 0)
                {
                        if (a.empty() and b.empty())
                        {
                                return {};
                        }
                        int n = 1;
                        int need = (int)max(a.size(), b.size());
                        while (n < need)
                        {
                                n <<= 1;
                        }
                        a.resize(n);
                        b.resize(n);
                        and_fwt(a, 1, mod);
                        and_fwt(b, 1, mod);
                        for (int i = 0; i < n; ++i)
                        {
                                if (mod)
                                {
                                        a[i] = (long long)((__int128)a[i] * b[i] % mod);
                                }
                                else
                                {
                                        a[i] *= b[i];
                                }
                        }
                        and_fwt(a, -1, mod);
                        return a;
                }
        }
}

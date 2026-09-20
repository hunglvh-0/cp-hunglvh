// Source: https://cp-algorithms.com/algebra/polynomial.html#interpolation

namespace Lagrange_Interpolation
{
        namespace LagrangeInterpolation
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
                long long eval(const vector<long long> &y, long long x, long long mod)
                {
                        int n = (int)y.size();
                        if (n == 0)
                        {
                                return 0;
                        }
                        x %= mod;
                        if (x < 0)
                        {
                                x += mod;
                        }
                        if (x < n)
                        {
                                long long t = y[(int)x] % mod;
                                if (t < 0)
                                {
                                        t += mod;
                                }
                                return t;
                        }
                        vector<long long> fac(n + 1, 1), ifac(n + 1, 1);
                        for (int i = 1; i <= n; ++i)
                        {
                                fac[i] = (long long)((__int128)fac[i - 1] * i % mod);
                        }
                        ifac[n] = inv(fac[n], mod);
                        for (int i = n; i >= 1; --i)
                        {
                                ifac[i - 1] = (long long)((__int128)ifac[i] * i % mod);
                        }
                        vector<long long> pre(n + 1, 1), suf(n + 1, 1);
                        for (int i = 0; i < n; ++i)
                        {
                                long long d = (x - i) % mod;
                                if (d < 0)
                                {
                                        d += mod;
                                }
                                pre[i + 1] = (long long)((__int128)pre[i] * d % mod);
                        }
                        for (int i = n - 1; i >= 0; --i)
                        {
                                long long d = (x - i) % mod;
                                if (d < 0)
                                {
                                        d += mod;
                                }
                                suf[i] = (long long)((__int128)suf[i + 1] * d % mod);
                        }
                        long long ans = 0;
                        for (int i = 0; i < n; ++i)
                        {
                                long long num = (long long)((__int128)pre[i] * suf[i + 1] % mod);
                                long long den = (long long)((__int128)ifac[i] * ifac[n - 1 - i] % mod);
                                if ((n - 1 - i) & 1)
                                {
                                        den = (mod - den) % mod;
                                }
                                long long yi = y[i] % mod;
                                if (yi < 0)
                                {
                                        yi += mod;
                                }
                                long long add = (long long)((__int128)yi * num % mod);
                                add = (long long)((__int128)add * den % mod);
                                ans += add;
                                ans %= mod;
                        }
                        return ans;
                }
        }
}

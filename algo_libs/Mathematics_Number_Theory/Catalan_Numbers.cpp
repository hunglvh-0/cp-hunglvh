// Source: https://cp-algorithms.com/combinatorics/catalan-numbers.html

namespace Catalan_Numbers
{
        namespace CatalanNumbers
        {
                long long exg(long long a, long long b, long long &x, long long &y)
                {
                        if (b == 0)
                        {
                                x = 1;
                                y = 0;
                                return a;
                        }
                        long long x1 = 0;
                        long long y1 = 0;
                        long long g = exg(b, a % b, x1, y1);
                        x = y1;
                        y = x1 - y1 * (a / b);
                        return g;
                }
                long long inv(long long a, long long m)
                {
                        long long x = 0;
                        long long y = 0;
                        long long g = exg(a, m, x, y);
                        if (g != 1)
                        {
                                return -1;
                        }
                        x %= m;
                        if (x < 0)
                        {
                                x += m;
                        }
                        return x;
                }
                long long one(int n)
                {
                        __int128 c = 1;
                        for (int i = 1; i <= n; i++)
                        {
                                c = c * (n + i) / i;
                        }
                        c /= (n + 1);
                        return (long long)c;
                }
                vector<long long> gen_dp(int n)
                {
                        vector<long long> c(n + 1, 0);
                        c[0] = 1;
                        for (int i = 1; i <= n; i++)
                        {
                                for (int j = 0; j < i; j++)
                                {
                                        c[i] += c[j] * c[i - 1 - j];
                                }
                        }
                        return c;
                }
                vector<long long> gen_mod(int n, long long mod)
                {
                        vector<long long> c(n + 1, 0);
                        c[0] = 1 % mod;
                        for (int i = 1; i <= n; i++)
                        {
                                long long iv = inv(i + 1, mod);
                                if (iv == -1)
                                {
                                        for (int j = 0; j < i; j++)
                                        {
                                                c[i] = (c[i] + (long long)((__int128)c[j] * c[i - 1 - j] % mod)) % mod;
                                        }
                                }
                                else
                                {
                                        long long t = (2LL * (2LL * i - 1)) % mod;
                                        c[i] = (long long)((__int128)c[i - 1] * t % mod);
                                        c[i] = (long long)((__int128)c[i] * iv % mod);
                                }
                        }
                        return c;
                }
        }
}

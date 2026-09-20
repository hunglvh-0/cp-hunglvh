// Source: https://oi-wiki.org/math/number-theory/quad-residue/#tonellishanks-%E7%AE%97%E6%B3%95

namespace Tonelli_Shanks
{
        namespace TonelliShanks
        {
                long long mul_mod(long long a, long long b, long long mod)
                {
                        return (long long)((__int128)a * b % mod);
                }
                long long pw_mod(long long a, long long e, long long mod)
                {
                        long long r = 1 % mod;
                        a %= mod;
                        while (e)
                        {
                                if (e & 1)
                                {
                                        r = mul_mod(r, a, mod);
                                }
                                a = mul_mod(a, a, mod);
                                e >>= 1;
                        }
                        return r;
                }
                bool is_quadratic_residue(long long n, long long p)
                {
                        n %= p;
                        if (n < 0)
                        {
                                n += p;
                        }
                        if (!n)
                        {
                                return true;
                        }
                        return pw_mod(n, (p - 1) >> 1, p) == 1;
                }
                long long tonelli_shanks(long long n, long long p)
                {
                        if (p == 2)
                        {
                                return n & 1;
                        }
                        n %= p;
                        if (n < 0)
                        {
                                n += p;
                        }
                        if (!n)
                        {
                                return 0;
                        }
                        if (!is_quadratic_residue(n, p))
                        {
                                return -1;
                        }
                        if (p % 4 == 3)
                        {
                                return pw_mod(n, (p + 1) >> 2, p);
                        }
                        long long q = p - 1;
                        int s = 0;
                        while ((q & 1) == 0)
                        {
                                q >>= 1;
                                ++s;
                        }
                        long long z = 2;
                        while (is_quadratic_residue(z, p))
                        {
                                ++z;
                        }
                        long long c = pw_mod(z, q, p);
                        long long x = pw_mod(n, (q + 1) >> 1, p);
                        long long t = pw_mod(n, q, p);
                        int m = s;
                        while (t != 1)
                        {
                                int i = 0;
                                long long tt = t;
                                while (tt != 1)
                                {
                                        tt = mul_mod(tt, tt, p);
                                        ++i;
                                        if (i == m)
                                        {
                                                return -1;
                                        }
                                }
                                long long b = pw_mod(c, 1LL << (m - i - 1), p);
                                x = mul_mod(x, b, p);
                                t = mul_mod(t, mul_mod(b, b, p), p);
                                c = mul_mod(b, b, p);
                                m = i;
                        }
                        return x;
                }
                pair<long long, long long> roots(long long n, long long p)
                {
                        long long r = tonelli_shanks(n, p);
                        if (r == -1)
                        {
                                return {
                                    -1, -1};
                        }
                        long long s = (p - r) % p;
                        if (r > s)
                        {
                                swap(r, s);
                        }
                        return {
                            r, s};
                }
        }
}

// Source: https://oi-wiki.org/math/number-theory/lucas/

namespace Lucas_Theorem
{
        namespace LucasTheorem
        {
                struct Lucas
                {
                        long long p;
                        vector<long long> fac;
                        vector<long long> ifac;
                        Lucas(long long _p = 2)
                        {
                                init(_p);
                        }
                        long long pw(long long a, long long e) const
                        {
                                long long r = 1 % p;
                                a %= p;
                                while (e)
                                {
                                        if (e & 1)
                                        {
                                                r = (long long)((__int128)r * a % p);
                                        }
                                        a = (long long)((__int128)a * a % p);
                                        e >>= 1;
                                }
                                return r;
                        }
                        void init(long long _p)
                        {
                                p = _p;
                                fac.assign(p, 1);
                                ifac.assign(p, 1);
                                for (long long i = 1; i < p; ++i)
                                {
                                        fac[i] = (long long)((__int128)fac[i - 1] * i % p);
                                }
                                ifac[p - 1] = pw(fac[p - 1], p - 2);
                                for (long long i = p - 1; i >= 1; --i)
                                {
                                        ifac[i - 1] = (long long)((__int128)ifac[i] * i % p);
                                }
                        }
                        long long c(long long n, long long k) const
                        {
                                if (k < 0 or k > n)
                                {
                                        return 0;
                                }
                                long long r = fac[n];
                                r = (long long)((__int128)r * ifac[k] % p);
                                r = (long long)((__int128)r * ifac[n - k] % p);
                                return r;
                        }
                        long long calc(long long n, long long k) const
                        {
                                if (k < 0 or k > n)
                                {
                                        return 0;
                                }
                                long long r = 1;
                                while (n or k)
                                {
                                        long long ni = n % p;
                                        long long ki = k % p;
                                        if (ki > ni)
                                        {
                                                return 0;
                                        }
                                        r = (long long)((__int128)r * c(ni, ki) % p);
                                        n /= p;
                                        k /= p;
                                }
                                return r;
                        }
                };
        }
}

// Source: https://cp-algorithms.com/algebra/factorization.html

namespace MillerRabin_PollardRho
{
        namespace MillerRabinPollardRho
        {
                using u64 = unsigned long long;
                using u128 = __uint128_t;
                u64 mul_mod(u64 a, u64 b, u64 mod)
                {
                        return (u64)((u128)a * b % mod);
                }
                u64 pw_mod(u64 a, u64 e, u64 mod)
                {
                        u64 r = 1 % mod;
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
                bool chk(u64 n, u64 a, u64 d, int s)
                {
                        u64 x = pw_mod(a, d, n);
                        if (x == 1 or x == n - 1)
                        {
                                return false;
                        }
                        for (int r = 1; r < s; ++r)
                        {
                                x = mul_mod(x, x, n);
                                if (x == n - 1)
                                {
                                        return false;
                                }
                        }
                        return true;
                }
                bool is_prime(u64 n)
                {
                        if (n < 2)
                        {
                                return false;
                        }
                        for (u64 p :
                             {
                                 2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL})

                        {
                                if (n % p == 0)
                                {
                                        return n == p;
                                }
                        }
                        int s = 0;
                        u64 d = n - 1;
                        while ((d & 1) == 0)
                        {
                                d >>= 1;
                                ++s;
                        }
                        for (u64 a :
                             {
                                 2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL})

                        {
                                if (a % n == 0)
                                {
                                        continue;
                                }
                                if (chk(n, a, d, s))
                                {
                                        return false;
                                }
                        }
                        return true;
                }
                u64 f(u64 x, u64 c, u64 mod)
                {
                        return (mul_mod(x, x, mod) + c) % mod;
                }
                u64 rho(u64 n)
                {
                        if ((n & 1) == 0)
                        {
                                return 2;
                        }
                        static mt19937_64 rng((u64)chrono::steady_clock::now().time_since_epoch().count());
                        while (true)
                        {
                                u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
                                u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
                                u64 y = x;
                                u64 d = 1;
                                while (d == 1)
                                {
                                        x = f(x, c, n);
                                        y = f(f(y, c, n), c, n);
                                        u64 v = (x > y ? x - y : y - x);
                                        d = std::gcd(v, n);
                                }
                                if (d != n)
                                {
                                        return d;
                                }
                        }
                }
                void fac(u64 n, vector<u64> &v)
                {
                        if (n == 1)
                        {
                                return;
                        }
                        if (is_prime(n))
                        {
                                v.push_back(n);
                                return;
                        }
                        u64 d = n;
                        while (d == n)
                        {
                                d = rho(n);
                        }
                        fac(d, v);
                        fac(n / d, v);
                }
                vector<u64> factor_list(u64 n)
                {
                        vector<u64> v;
                        fac(n, v);
                        sort(v.begin(), v.end());
                        return v;
                }
                vector<pair<u64, int>> factor(u64 n)
                {
                        vector<u64> v = factor_list(n);
                        vector<pair<u64, int>> r;
                        for (u64 x : v)
                        {
                                if (r.empty() or r.back().first != x)
                                {
                                        r.push_back(
                                            {x, 1});
                                }
                                else
                                {
                                        ++r.back().second;
                                }
                        }
                        return r;
                }
        }
}

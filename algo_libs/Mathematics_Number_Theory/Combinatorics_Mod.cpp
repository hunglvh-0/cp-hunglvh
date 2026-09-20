// Source: https://cp-algorithms.com/combinatorics/binomial-coefficients.html

namespace Combinatorics_Mod
{
        namespace CombinatoricsMod
        {
                struct Comb
                {
                        long long m;
                        vector<long long> f;
                        vector<long long> fi;
                        vector<long long> iv;
                        void init(int n, long long mod)
                        {
                                m = mod;
                                f.assign(n + 1, 1);
                                fi.assign(n + 1, 1);
                                iv.assign(n + 1, 0);
                                if (n >= 1)
                                {
                                        iv[1] = 1;
                                }
                                for (int i = 2; i <= n; i++)
                                {
                                        iv[i] = m - (long long)((__int128)(m / i) * iv[m % i] % m);
                                }
                                for (int i = 1; i <= n; i++)
                                {
                                        f[i] = (long long)((__int128)f[i - 1] * i % m);
                                        fi[i] = (long long)((__int128)fi[i - 1] * iv[i] % m);
                                }
                        }
                        long long F(int n) const
                        {
                                if (n < 0 or n >= (int)f.size())
                                {
                                        return 0;
                                }
                                return f[n];
                        }
                        long long C(int n, int r) const
                        {
                                if (r < 0 or r > n)
                                {
                                        return 0;
                                }
                                if (n >= (int)f.size())
                                {
                                        return 0;
                                }
                                return (long long)((__int128)f[n] * fi[r] % m * fi[n - r] % m);
                        }
                        long long P(int n, int r) const
                        {
                                if (r < 0 or r > n)
                                {
                                        return 0;
                                }
                                if (n >= (int)f.size())
                                {
                                        return 0;
                                }
                                return (long long)((__int128)f[n] * fi[n - r] % m);
                        }
                };
        }
}

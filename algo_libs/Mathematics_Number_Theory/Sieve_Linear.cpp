// Source: https://cp-algorithms.com/algebra/prime-sieve-linear.html

namespace Sieve_Linear
{
        namespace SieveLinear
        {
                struct LinearSieve
                {
                        int n;
                        vector<int> p;
                        vector<int> lp;
                        vector<int> phi;
                        vector<int> mu;
                        LinearSieve(int _n = 0)
                        {
                                n = 0;
                                if (_n)
                                {
                                        init(_n);
                                }
                        }
                        void init(int _n)
                        {
                                n = _n;
                                p.clear();
                                lp.assign(n + 1, 0);
                                phi.assign(n + 1, 0);
                                mu.assign(n + 1, 0);
                                if (n >= 1)
                                {
                                        phi[1] = 1;
                                        mu[1] = 1;
                                }
                                for (int i = 2; i <= n; ++i)
                                {
                                        if (!lp[i])
                                        {
                                                lp[i] = i;
                                                p.push_back(i);
                                                phi[i] = i - 1;
                                                mu[i] = -1;
                                        }
                                        for (int x : p)
                                        {
                                                long long v = 1LL * i * x;
                                                if (v > n)
                                                {
                                                        break;
                                                }
                                                lp[v] = x;
                                                if (x == lp[i])
                                                {
                                                        phi[v] = phi[i] * x;
                                                        mu[v] = 0;
                                                        break;
                                                }
                                                phi[v] = phi[i] * (x - 1);
                                                mu[v] = -mu[i];
                                        }
                                }
                        }
                        bool is_prime(int x) const
                        {
                                return x >= 2 and x <= n and lp[x] == x;
                        }
                        vector<pair<int, int>> factorize_small(int x) const
                        {
                                vector<pair<int, int>> fac;
                                if (x <= 1 or x > n)
                                {
                                        return fac;
                                }
                                while (x > 1)
                                {
                                        int q = lp[x];
                                        int c = 0;
                                        while (x % q == 0)
                                        {
                                                x /= q;
                                                ++c;
                                        }
                                        fac.push_back(
                                            {q, c});
                                }
                                return fac;
                        }
                };
                vector<pair<long long, int>> factorize_large(long long x, const vector<int> &primes)
                {
                        vector<pair<long long, int>> fac;
                        for (int q : primes)
                        {
                                if (1LL * q * q > x)
                                {
                                        break;
                                }
                                if (x % q)
                                {
                                        continue;
                                }
                                int c = 0;
                                while (x % q == 0)
                                {
                                        x /= q;
                                        ++c;
                                }
                                fac.push_back(
                                    {q, c});
                        }
                        if (x > 1)
                        {
                                fac.push_back(
                                    {x, 1});
                        }
                        return fac;
                }
        }
}

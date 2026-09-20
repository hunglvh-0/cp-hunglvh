// Source: https://cp-algorithms.com/algebra/phi-function.html

namespace Euler_Totient
{
        namespace EulerTotient
        {
                long long phi_one(long long n)
                {
                        long long r = n;
                        for (long long p = 2; p * p <= n; p++)
                        {
                                if (n % p == 0)
                                {
                                        while (n % p == 0)
                                        {
                                                n /= p;
                                        }
                                        r -= r / p;
                                }
                        }
                        if (n > 1)
                        {
                                r -= r / n;
                        }
                        return r;
                }
                vector<int> phi_sieve(int n)
                {
                        vector<int> phi(n + 1);
                        for (int i = 0; i <= n; i++)
                        {
                                phi[i] = i;
                        }
                        for (int i = 2; i <= n; i++)
                        {
                                if (phi[i] == i)
                                {
                                        for (int j = i; j <= n; j += i)
                                        {
                                                phi[j] -= phi[j] / i;
                                        }
                                }
                        }
                        return phi;
                }
                vector<int> phi_linear(int n)
                {
                        vector<int> pr;
                        vector<int> mk(n + 1, 0);
                        vector<int> phi(n + 1, 0);
                        if (n >= 1)
                        {
                                phi[1] = 1;
                        }
                        for (int i = 2; i <= n; i++)
                        {
                                if (!mk[i])
                                {
                                        pr.push_back(i);
                                        phi[i] = i - 1;
                                }
                                for (int p : pr)
                                {
                                        if (1LL * i * p > n)
                                        {
                                                break;
                                        }
                                        mk[i * p] = 1;
                                        if (i % p == 0)
                                        {
                                                phi[i * p] = phi[i] * p;
                                                break;
                                        }
                                        phi[i * p] = phi[i] * (p - 1);
                                }
                        }
                        return phi;
                }
        }
}

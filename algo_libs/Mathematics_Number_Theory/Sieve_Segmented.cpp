// Source: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#find-primes-in-range

namespace Sieve_Segmented
{
        namespace SieveSegmented
        {
                vector<int> simple_sieve(int n)
                {
                        if (n < 2)
                        {
                                return {};
                        }
                        vector<char> is(n + 1, true);
                        is[0] = false;
                        is[1] = false;
                        for (int i = 2; 1LL * i * i <= n; ++i)
                        {
                                if (!is[i])
                                {
                                        continue;
                                }
                                for (long long j = 1LL * i * i; j <= n; j += i)
                                {
                                        is[(int)j] = false;
                                }
                        }
                        vector<int> p;
                        for (int i = 2; i <= n; ++i)
                        {
                                if (is[i])
                                {
                                        p.push_back(i);
                                }
                        }
                        return p;
                }
                vector<char> mark_segment(long long L, long long R)
                {
                        if (L > R)
                        {
                                return {};
                        }
                        vector<char> is(R - L + 1, true);
                        if (R < 2)
                        {
                                fill(is.begin(), is.end(), false);
                                return is;
                        }
                        int lim = (int)sqrt((long double)R);
                        vector<int> p = simple_sieve(lim);
                        for (int x : p)
                        {
                                long long start = max(1LL * x * x, ((L + x - 1) / x) * 1LL * x);
                                for (long long j = start; j <= R; j += x)
                                {
                                        is[j - L] = false;
                                }
                        }
                        for (long long x = L; x <= R and x <= 1; ++x)
                        {
                                is[x - L] = false;
                        }
                        return is;
                }
                vector<long long> primes_in_range(long long L, long long R)
                {
                        vector<char> is = mark_segment(L, R);
                        vector<long long> primes;
                        for (long long x = L; x <= R; ++x)
                        {
                                if (!is[x - L])
                                {
                                        continue;
                                }
                                primes.push_back(x);
                        }
                        return primes;
                }
        }
}

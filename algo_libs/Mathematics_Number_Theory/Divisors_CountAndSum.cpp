// Source: https://cp-algorithms.com/algebra/divisors.html

namespace Divisors_CountAndSum
{
    namespace DivisorsCountAndSum
    {
        vector<pair<long long, int>> fac(long long n)
    {
            vector<pair<long long, int>> f;
            for (long long p = 2; p * p <= n; p++)
    {
                if (n % p == 0)
    {
                    int e = 0;
                    while (n % p == 0)
    {
                        n /= p;
                        e++;

    }
                    f.push_back(
    {
    p, e
    }
    );

    }

    }
            if (n > 1)
    {
                f.push_back(
    {
    n, 1
    }
    );

    }
            return f;

    }
        pair<long long, long long> from_fac(const vector<pair<long long, int>> &f)
    {
            long long c = 1;
            long long s = 1;
            for (auto [p, e] : f)
    {
                c *= (e + 1);
                long long sm = 1;
                long long pw = 1;
                for (int i = 1; i <= e; i++)
    {
                    pw *= p;
                    sm += pw;

    }
                s *= sm;

    }
            return
    {
    c, s
    }
    ;

    }
        pair<long long, long long> one(long long n)
    {
            return from_fac(fac(n));

    }
        vector<int> cnt_all(int n)
    {
            vector<int> d(n + 1, 0);
            for (int i = 1; i <= n; i++)
    {
                for (int j = i; j <= n; j += i)
    {
                    d[j]++;

    }

    }
            return d;

    }
        vector<long long> sum_all(int n)
    {
            vector<long long> s(n + 1, 0);
            for (int i = 1; i <= n; i++)
    {
                for (int j = i; j <= n; j += i)
    {
                    s[j] += i;

    }

    }
            return s;

    }
    }
}

// Source: https://oi-wiki.org/math/number-theory/min-25/

namespace Min25_Sieve
{
        namespace Min25Sieve
        {
                struct Min25
                {
                        long long n;
                        int sq;
                        vector<int> pr;
                        vector<long long> sp0;
                        vector<long long> sp1;
                        vector<long long> w;
                        vector<long long> g0;
                        vector<long long> g1;
                        vector<int> id1;
                        vector<int> id2;
                        Min25(long long _n = 0)
                        {
                                if (_n)
                                {
                                        init(_n);
                                }
                        }
                        int gid(long long x) const
                        {
                                if (x <= sq)
                                {
                                        return id1[(int)x];
                                }
                                return id2[(int)(n / x)];
                        }
                        void init(long long _n)
                        {
                                n = _n;
                                sq = (int)sqrt((long double)n);
                                pr.clear();
                                vector<int> lp(sq + 1, 0);
                                for (int i = 2; i <= sq; ++i)
                                {
                                        if (!lp[i])
                                        {
                                                lp[i] = i;
                                                pr.push_back(i);
                                        }
                                        for (int p : pr)
                                        {
                                                long long v = 1LL * i * p;
                                                if (p > lp[i] or v > sq)
                                                {
                                                        break;
                                                }
                                                lp[(int)v] = p;
                                        }
                                }
                                sp0.assign(pr.size() + 1, 0);
                                sp1.assign(pr.size() + 1, 0);
                                for (int i = 0; i < (int)pr.size(); ++i)
                                {
                                        sp0[i + 1] = sp0[i] + 1;
                                        sp1[i + 1] = sp1[i] + pr[i];
                                }
                                w.clear();
                                g0.clear();
                                g1.clear();
                                id1.assign(sq + 1, -1);
                                id2.assign(sq + 1, -1);
                                for (long long l = 1, r; l <= n; l = r + 1)
                                {
                                        long long v = n / l;
                                        r = n / v;
                                        int id = (int)w.size();
                                        w.push_back(v);
                                        g0.push_back(v - 1);
                                        g1.push_back(v * (v + 1) / 2 - 1);
                                        if (v <= sq)
                                        {
                                                id1[(int)v] = id;
                                        }
                                        else
                                        {
                                                id2[(int)(n / v)] = id;
                                        }
                                }
                                for (int j = 0; j < (int)pr.size(); ++j)
                                {
                                        long long p = pr[j];
                                        long long p2 = p * p;
                                        if (p2 > n)
                                        {
                                                break;
                                        }
                                        for (int i = 0; i < (int)w.size() and w[i] >= p2; ++i)
                                        {
                                                int k = gid(w[i] / p);
                                                g0[i] -= g0[k] - j;
                                                g1[i] -= p * (g1[k] - sp1[j]);
                                        }
                                }
                        }
                        long long pi(long long x) const
                        {
                                if (x < 2)
                                {
                                        return 0;
                                }
                                return g0[gid(x)];
                        }
                        long long sum_prime(long long x) const
                        {
                                if (x < 2)
                                {
                                        return 0;
                                }
                                return g1[gid(x)];
                        }
                        long long sum_prime_f(long long x, int j) const
                        {
                                if (x < 2)
                                {
                                        return 0;
                                }
                                return (g1[gid(x)] - g0[gid(x)]) - (sp1[j] - sp0[j]);
                        }
                        long long sf_phi(long long x, int j) const
                        {
                                if (x < 2)
                                {
                                        return 0;
                                }
                                if (j < (int)pr.size() and x <= pr[j])
                                {
                                        return 0;
                                }
                                long long ans = sum_prime_f(x, j);
                                for (int i = j; i < (int)pr.size(); ++i)
                                {
                                        long long p = pr[i];
                                        if (p * p > x)
                                        {
                                                break;
                                        }
                                        long long pk = p;
                                        int c = 1;
                                        while (pk <= x / p)
                                        {
                                                long long fp = pk - pk / p;
                                                ans += fp * (sf_phi(x / pk, i + 1) + (c > 1));
                                                pk *= p;
                                                ++c;
                                        }
                                        if (pk <= x and c > 1)
                                        {
                                                long long fp = pk - pk / p;
                                                ans += fp;
                                        }
                                }
                                return ans;
                        }
                        long long sum_phi() const
                        {
                                return sf_phi(n, 0) + 1;
                        }
                };
        }
}

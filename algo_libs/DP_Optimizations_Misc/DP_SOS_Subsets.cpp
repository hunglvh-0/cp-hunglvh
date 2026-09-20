// Source: https://cp-algorithms.com/algebra/all-submasks.html

namespace DP_SOS_Subsets
{
        namespace DPSOSSubsets
        {
                template <class T>
                vector<T> zeta_subset(vector<T> f)
                {
                        int n = 0;
                        while ((1 << n) < (int)f.size())
                        {
                                ++n;
                        }
                        for (int b = 0; b < n; ++b)
                        {
                                for (int mask = 0; mask < (1 << n); ++mask)
                                {
                                        if ((mask >> b) & 1)
                                        {
                                                f[mask] += f[mask ^ (1 << b)];
                                        }
                                }
                        }
                        return f;
                }
                template <class T>
                vector<T> mobius_subset(vector<T> f)
                {
                        int n = 0;
                        while ((1 << n) < (int)f.size())
                        {
                                ++n;
                        }
                        for (int b = 0; b < n; ++b)
                        {
                                for (int mask = 0; mask < (1 << n); ++mask)
                                {
                                        if ((mask >> b) & 1)
                                        {
                                                f[mask] -= f[mask ^ (1 << b)];
                                        }
                                }
                        }
                        return f;
                }
                template <class T>
                vector<T> zeta_superset(vector<T> f)
                {
                        int n = 0;
                        while ((1 << n) < (int)f.size())
                        {
                                ++n;
                        }
                        for (int b = 0; b < n; ++b)
                        {
                                for (int mask = 0; mask < (1 << n); ++mask)
                                {
                                        if (((mask >> b) & 1) == 0)
                                        {
                                                f[mask] += f[mask | (1 << b)];
                                        }
                                }
                        }
                        return f;
                }
                template <class T>
                vector<T> mobius_superset(vector<T> f)
                {
                        int n = 0;
                        while ((1 << n) < (int)f.size())
                        {
                                ++n;
                        }
                        for (int b = 0; b < n; ++b)
                        {
                                for (int mask = 0; mask < (1 << n); ++mask)
                                {
                                        if (((mask >> b) & 1) == 0)
                                        {
                                                f[mask] -= f[mask | (1 << b)];
                                        }
                                }
                        }
                        return f;
                }
                vector<long long> max_over_subsets(vector<long long> a)
                {
                        int n = 0;
                        while ((1 << n) < (int)a.size())
                        {
                                ++n;
                        }
                        for (int b = 0; b < n; ++b)
                        {
                                for (int mask = 0; mask < (1 << n); ++mask)
                                {
                                        if ((mask >> b) & 1)
                                        {
                                                a[mask] = max(a[mask], a[mask ^ (1 << b)]);
                                        }
                                }
                        }
                        return a;
                }
        }
}

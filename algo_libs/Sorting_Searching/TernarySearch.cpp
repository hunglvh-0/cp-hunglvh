// Source: https://cp-algorithms.com/num_methods/ternary_search.html

namespace TernarySearch
{
        namespace TernarySearch
        {
                template <class F>
                double mx_d(double l, double r, F f, int it = 200)
                {
                        for (int i = 0; i < it; i++)
                        {
                                double m1 = l + (r - l) / 3.0;
                                double m2 = r - (r - l) / 3.0;
                                if (f(m1) < f(m2))
                                {
                                        l = m1;
                                }
                                else
                                {
                                        r = m2;
                                }
                        }
                        return l;
                }
                template <class F>
                double mn_d(double l, double r, F f, int it = 200)
                {
                        for (int i = 0; i < it; i++)
                        {
                                double m1 = l + (r - l) / 3.0;
                                double m2 = r - (r - l) / 3.0;
                                if (f(m1) > f(m2))
                                {
                                        l = m1;
                                }
                                else
                                {
                                        r = m2;
                                }
                        }
                        return l;
                }
                template <class F>
                int mx_i(int l, int r, F f)
                {
                        while (r - l >= 3)
                        {
                                int m1 = l + (r - l) / 3;
                                int m2 = r - (r - l) / 3;
                                if (f(m1) < f(m2))
                                {
                                        l = m1;
                                }
                                else
                                {
                                        r = m2;
                                }
                        }
                        int b = l;
                        for (int i = l + 1; i <= r; i++)
                        {
                                if (f(i) > f(b))
                                {
                                        b = i;
                                }
                        }
                        return b;
                }
                template <class F>
                int mn_i(int l, int r, F f)
                {
                        while (r - l >= 3)
                        {
                                int m1 = l + (r - l) / 3;
                                int m2 = r - (r - l) / 3;
                                if (f(m1) > f(m2))
                                {
                                        l = m1;
                                }
                                else
                                {
                                        r = m2;
                                }
                        }
                        int b = l;
                        for (int i = l + 1; i <= r; i++)
                        {
                                if (f(i) < f(b))
                                {
                                        b = i;
                                }
                        }
                        return b;
                }
                int mx_u(const vector<ll> &a)
                {
                        int l = 0;
                        int r = (int)a.size() - 1;
                        while (r - l >= 3)
                        {
                                int m1 = l + (r - l) / 3;
                                int m2 = r - (r - l) / 3;
                                if (a[m1] < a[m2])
                                {
                                        l = m1;
                                }
                                else
                                {
                                        r = m2;
                                }
                        }
                        int b = l;
                        for (int i = l + 1; i <= r; i++)
                        {
                                if (a[i] > a[b])
                                {
                                        b = i;
                                }
                        }
                        return b;
                }
        }
}

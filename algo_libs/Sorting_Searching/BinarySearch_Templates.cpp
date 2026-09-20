// Source: https://cp-algorithms.com/num_methods/binary_search.html

namespace BinarySearch_Templates
{
        namespace BinarySearchTemplates
        {
                template <class F>
                int fst_t(int l, int r, F f)
                {
                        while (l < r)
                        {
                                int m = l + (r - l) / 2;
                                if (f(m))
                                {
                                        r = m;
                                }
                                else
                                {
                                        l = m + 1;
                                }
                        }
                        return l;
                }
                template <class F>
                int lst_t(int l, int r, F f)
                {
                        while (l < r)
                        {
                                int m = l + (r - l + 1) / 2;
                                if (f(m))
                                {
                                        l = m;
                                }
                                else
                                {
                                        r = m - 1;
                                }
                        }
                        return l;
                }
                int lb(const vector<int> &a, int x)
                {
                        int l = 0;
                        int r = (int)a.size();
                        while (l < r)
                        {
                                int m = l + (r - l) / 2;
                                if (a[m] >= x)
                                {
                                        r = m;
                                }
                                else
                                {
                                        l = m + 1;
                                }
                        }
                        return l;
                }
                int ub(const vector<int> &a, int x)
                {
                        int l = 0;
                        int r = (int)a.size();
                        while (l < r)
                        {
                                int m = l + (r - l) / 2;
                                if (a[m] > x)
                                {
                                        r = m;
                                }
                                else
                                {
                                        l = m + 1;
                                }
                        }
                        return l;
                }
        }
}

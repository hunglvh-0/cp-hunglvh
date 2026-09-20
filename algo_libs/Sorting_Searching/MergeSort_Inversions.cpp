// Source: https://en.oi-wiki.org/basic/merge-sort/

namespace MergeSort_Inversions
{
        namespace MergeSortInversions
        {
                ll mrg(vector<ll> &a, vector<ll> &t, int l, int r)
                {
                        if (r - l <= 1)
                        {
                                return 0;
                        }
                        int m = l + (r - l) / 2;
                        ll an = mrg(a, t, l, m) + mrg(a, t, m, r);
                        int i = l;
                        int j = m;
                        int k = l;
                        while (i < m and j < r)
                        {
                                if (a[i] <= a[j])
                                {
                                        t[k++] = a[i++];
                                }
                                else
                                {
                                        an += m - i;
                                        t[k++] = a[j++];
                                }
                        }
                        while (i < m)
                        {
                                t[k++] = a[i++];
                        }
                        while (j < r)
                        {
                                t[k++] = a[j++];
                        }
                        for (int x = l; x < r; x++)
                        {
                                a[x] = t[x];
                        }
                        return an;
                }
                ll cnt(vector<ll> a)
                {
                        int n = (int)a.size();
                        vector<ll> t(n);
                        return mrg(a, t, 0, n);
                }
        }
}

// Source: https://en.oi-wiki.org/basic/heap-sort/

namespace HeapSort
{
        namespace HeapSort
        {
                void dn(vector<int> &a, int s, int e)
                {
                        int p = s;
                        int c = p * 2 + 1;
                        while (c <= e)
                        {
                                if (c + 1 <= e and a[c] < a[c + 1])
                                {
                                        c++;
                                }
                                if (a[p] >= a[c])
                                {
                                        return;
                                }
                                swap(a[p], a[c]);
                                p = c;
                                c = p * 2 + 1;
                        }
                }
                void srt(vector<int> &a)
                {
                        int n = (int)a.size();
                        if (n <= 1)
                        {
                                return;
                        }
                        for (int i = (n - 2) / 2; i >= 0; i--)
                        {
                                dn(a, i, n - 1);
                        }
                        for (int i = n - 1; i > 0; i--)
                        {
                                swap(a[0], a[i]);
                                dn(a, 0, i - 1);
                        }
                }
        }
}

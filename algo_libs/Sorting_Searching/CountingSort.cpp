// Source: https://en.oi-wiki.org/basic/counting-sort/

namespace CountingSort
{
        namespace CountingSort
        {
                vector<int> srt(const vector<int> &a, int mx)
                {
                        int n = (int)a.size();
                        if (n == 0)
                        {
                                return vector<int>();
                        }
                        vector<int> c(mx + 1, 0);
                        for (int x : a)
                        {
                                c[x]++;
                        }
                        for (int i = 1; i <= mx; i++)
                        {
                                c[i] += c[i - 1];
                        }
                        vector<int> b(n);
                        for (int i = n - 1; i >= 0; i--)
                        {
                                int x = a[i];
                                b[--c[x]] = x;
                        }
                        return b;
                }
        }
}

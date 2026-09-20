// Source: https://en.oi-wiki.org/basic/radix-sort/

namespace RadixSort
{
        namespace RadixSort
        {
                void srt(vector<int> &a)
                {
                        int n = (int)a.size();
                        if (n <= 1)
                        {
                                return;
                        }
                        vector<unsigned int> v(n);
                        vector<unsigned int> t(n);
                        for (int i = 0; i < n; i++)
                        {
                                v[i] = (unsigned int)a[i] ^ 0x80000000u;
                        }
                        const int b = 1 << 16;
                        vector<int> c(b);
                        for (int sh = 0; sh < 32; sh += 16)
                        {
                                fill(c.begin(), c.end(), 0);
                                for (int i = 0; i < n; i++)
                                {
                                        int d = (int)((v[i] >> sh) & (b - 1));
                                        c[d]++;
                                }
                                for (int i = 1; i < b; i++)
                                {
                                        c[i] += c[i - 1];
                                }
                                for (int i = n - 1; i >= 0; i--)
                                {
                                        int d = (int)((v[i] >> sh) & (b - 1));
                                        t[--c[d]] = v[i];
                                }
                                v.swap(t);
                        }
                        for (int i = 0; i < n; i++)
                        {
                                a[i] = (int)(v[i] ^ 0x80000000u);
                        }
                }
        }
}

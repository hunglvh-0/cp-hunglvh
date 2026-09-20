// Source: https://codeforces.com/blog/entry/61203

namespace HilbertCurve_Sort
{
        namespace HilbertCurveSort
        {
                long long ord(int x, int y, int p, int r)
                {
                        if (p == 0)
                        {
                                return 0;
                        }
                        int h = 1 << (p - 1);
                        int s = 0;
                        if (x < h)
                        {
                                s = (y < h) ? 0 : 3;
                        }
                        else
                        {
                                s = (y < h) ? 1 : 2;
                        }
                        s = (s + r) & 3;
                        int rd[4];
                        rd[0] = 3;
                        rd[1] = 0;
                        rd[2] = 0;
                        rd[3] = 1;
                        int nx = x & (x ^ h);
                        int ny = y & (y ^ h);
                        int nr = (r + rd[s]) & 3;
                        long long ss = 1LL << (2 * p - 2);
                        long long an = s * ss;
                        long long ad = ord(nx, ny, p - 1, nr);
                        if (s == 1 or s == 2)
                        {
                                an += ad;
                        }
                        else
                        {
                                an += ss - ad - 1;
                        }
                        return an;
                }
                struct Qr
                {
                        int l;
                        int r;
                        int id;
                        long long o;
                };
                void build(vector<Qr> &q, int p = 21)
                {
                        for (Qr &x : q)
                        {
                                x.o = ord(x.l, x.r, p, 0);
                        }
                        sort(q.begin(), q.end(), [](const Qr &a, const Qr &b)

                             { return a.o < b.o; });
                }
        }
}

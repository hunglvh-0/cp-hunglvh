// Source: https://cp-algorithms.com/algebra/fft.html

namespace Fast_Fourier_Transform
{
        namespace FastFourierTransform
        {
                using cd = complex<double>;
                const double PI = acos(-1.0);
                void fft(vector<cd> &a, bool iv)
                {
                        int n = (int)a.size();
                        for (int i = 1, j = 0; i < n; i++)
                        {
                                int bt = n >> 1;
                                for (; j & bt; bt >>= 1)
                                {
                                        j ^= bt;
                                }
                                j ^= bt;
                                if (i < j)
                                {
                                        swap(a[i], a[j]);
                                }
                        }
                        for (int ln = 2; ln <= n; ln <<= 1)
                        {
                                double ag = 2 * PI / ln * (iv ? -1 : 1);
                                cd wl(cos(ag), sin(ag));
                                for (int i = 0; i < n; i += ln)
                                {
                                        cd w(1);
                                        for (int j = 0; j < ln / 2; j++)
                                        {
                                                cd u = a[i + j];
                                                cd v = a[i + j + ln / 2] * w;
                                                a[i + j] = u + v;
                                                a[i + j + ln / 2] = u - v;
                                                w *= wl;
                                        }
                                }
                        }
                        if (iv)
                        {
                                for (cd &x : a)
                                {
                                        x /= n;
                                }
                        }
                }
                vector<long long> mul(const vector<long long> &a, const vector<long long> &b)
                {
                        if (a.empty() or b.empty())
                        {
                                return {};
                        }
                        int n = 1;
                        int nd = (int)a.size() + (int)b.size() - 1;
                        while (n < nd)
                        {
                                n <<= 1;
                        }
                        vector<cd> fa(a.begin(), a.end());
                        vector<cd> fb(b.begin(), b.end());
                        fa.resize(n);
                        fb.resize(n);
                        fft(fa, false);
                        fft(fb, false);
                        for (int i = 0; i < n; i++)
                        {
                                fa[i] *= fb[i];
                        }
                        fft(fa, true);
                        vector<long long> r(nd);
                        for (int i = 0; i < nd; i++)
                        {
                                r[i] = llround(fa[i].real());
                        }
                        return r;
                }
                vector<int> mul_digits(const vector<int> &a, const vector<int> &b, int bs = 10)
                {
                        vector<long long> x(a.begin(), a.end());
                        vector<long long> y(b.begin(), b.end());
                        vector<long long> c = mul(x, y);
                        vector<int> r(c.size());
                        long long cr = 0;
                        for (int i = 0; i < (int)c.size(); i++)
                        {
                                long long v = c[i] + cr;
                                r[i] = (int)(v % bs);
                                cr = v / bs;
                        }
                        while (cr > 0)
                        {
                                r.push_back((int)(cr % bs));
                                cr /= bs;
                        }
                        while (r.size() > 1 and r.back() == 0)
                        {
                                r.pop_back();
                        }
                        return r;
                }
        }
}

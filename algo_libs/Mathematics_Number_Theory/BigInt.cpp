// Source: https://cp-algorithms.com/algebra/big-integer.html

namespace BigInt
{
        namespace BigIntegerLib
        {
                struct BigInt
                {
                        static const int B = 1000000000;
                        static const int W = 9;
                        vector<int> d;
                        int s;
                        BigInt(long long v = 0)
                        {
                                *this = v;
                        }
                        BigInt(const string &x)
                        {
                                read(x);
                        }
                        BigInt &operator=(long long v)
                        {
                                s = 1;
                                if (v < 0)
                                {
                                        s = -1;
                                        v = -v;
                                }
                                d.clear();
                                while (v > 0)
                                {
                                        d.push_back((int)(v % B));
                                        v /= B;
                                }
                                return *this;
                        }
                        bool is0() const
                        {
                                return d.empty();
                        }
                        BigInt &trim()
                        {
                                while (!d.empty() and d.back() == 0)
                                {
                                        d.pop_back();
                                }
                                if (d.empty())
                                {
                                        s = 1;
                                }
                                return *this;
                        }
                        void read(const string &x)
                        {
                                s = 1;
                                d.clear();
                                if (x.empty())
                                {
                                        return;
                                }
                                int p = 0;
                                if (x[0] == '-')
                                {
                                        s = -1;
                                        p = 1;
                                }
                                for (int i = (int)x.size(); i > p; i -= W)
                                {
                                        int l = max(p, i - W);
                                        int y = 0;
                                        for (int j = l; j < i; j++)
                                        {
                                                y = y * 10 + (x[j] - '0');
                                        }
                                        d.push_back(y);
                                }
                                trim();
                        }
                        string str() const
                        {
                                if (d.empty())
                                {
                                        return "0";
                                }
                                string r = (s == -1 ? "-" : "");
                                r += to_string(d.back());
                                for (int i = (int)d.size() - 2; i >= 0; i--)
                                {
                                        string t = to_string(d[i]);
                                        r += string(W - (int)t.size(), '0') + t;
                                }
                                return r;
                        }
                        void shl()
                        {
                                if (d.empty())
                                {
                                        d.push_back(0);
                                        return;
                                }
                                d.insert(d.begin(), 0);
                        }
                        static int cmp_abs(const BigInt &a, const BigInt &b)
                        {
                                if (a.d.size() != b.d.size())
                                {
                                        return a.d.size() < b.d.size() ? -1 : 1;
                                }
                                for (int i = (int)a.d.size() - 1; i >= 0; i--)
                                {
                                        if (a.d[i] != b.d[i])
                                        {
                                                return a.d[i] < b.d[i] ? -1 : 1;
                                        }
                                }
                                return 0;
                        }
                        static BigInt add_abs(const BigInt &a, const BigInt &b)
                        {
                                BigInt r;
                                r.s = 1;
                                int n = max((int)a.d.size(), (int)b.d.size());
                                r.d.assign(n, 0);
                                long long c = 0;
                                for (int i = 0; i < n or c; i++)
                                {
                                        if (i == (int)r.d.size())
                                        {
                                                r.d.push_back(0);
                                        }
                                        long long v = c;
                                        if (i < (int)a.d.size())
                                        {
                                                v += a.d[i];
                                        }
                                        if (i < (int)b.d.size())
                                        {
                                                v += b.d[i];
                                        }
                                        r.d[i] = (int)(v % B);
                                        c = v / B;
                                }
                                return r.trim();
                        }
                        static BigInt sub_abs(const BigInt &a, const BigInt &b)
                        {
                                BigInt r;
                                r.s = 1;
                                r.d.assign(a.d.size(), 0);
                                long long c = 0;
                                for (int i = 0; i < (int)a.d.size(); i++)
                                {
                                        long long v = a.d[i] - c - (i < (int)b.d.size() ? b.d[i] : 0);
                                        if (v < 0)
                                        {
                                                v += B;
                                                c = 1;
                                        }
                                        else
                                        {
                                                c = 0;
                                        }
                                        r.d[i] = (int)v;
                                }
                                return r.trim();
                        }
                };
                BigInt ab(BigInt a)
                {
                        a.s = 1;
                        return a;
                }
                bool operator<(const BigInt &a, const BigInt &b)
                {
                        if (a.s != b.s)
                        {
                                return a.s < b.s;
                        }
                        int c = BigInt::cmp_abs(a, b);
                        if (a.s == 1)
                        {
                                return c < 0;
                        }
                        return c > 0;
                }
                bool operator>(const BigInt &a, const BigInt &b)
                {
                        return b < a;
                }
                bool operator<=(const BigInt &a, const BigInt &b)
                {
                        return !(b < a);
                }
                bool operator>=(const BigInt &a, const BigInt &b)
                {
                        return !(a < b);
                }
                bool operator==(const BigInt &a, const BigInt &b)
                {
                        return a.s == b.s and a.d == b.d;
                }
                bool operator!=(const BigInt &a, const BigInt &b)
                {
                        return !(a == b);
                }
                BigInt operator-(BigInt a)
                {
                        if (!a.is0())
                        {
                                a.s = -a.s;
                        }
                        return a;
                }
                BigInt operator+(const BigInt &a, const BigInt &b)
                {
                        if (a.s == b.s)
                        {
                                BigInt r = BigInt::add_abs(a, b);
                                r.s = a.s;
                                return r.trim();
                        }
                        int c = BigInt::cmp_abs(a, b);
                        if (c == 0)
                        {
                                return BigInt(0);
                        }
                        if (c > 0)
                        {
                                BigInt r = BigInt::sub_abs(a, b);
                                r.s = a.s;
                                return r.trim();
                        }
                        BigInt r = BigInt::sub_abs(b, a);
                        r.s = b.s;
                        return r.trim();
                }
                BigInt operator-(const BigInt &a, const BigInt &b)
                {
                        return a + (-b);
                }
                BigInt operator*(BigInt a, int m)
                {
                        if (a.is0() or m == 0)
                        {
                                return BigInt(0);
                        }
                        if (m < 0)
                        {
                                a.s = -a.s;
                                m = -m;
                        }
                        long long c = 0;
                        for (int i = 0; i < (int)a.d.size() or c; i++)
                        {
                                if (i == (int)a.d.size())
                                {
                                        a.d.push_back(0);
                                }
                                long long v = c + 1LL * a.d[i] * m;
                                a.d[i] = (int)(v % BigInt::B);
                                c = v / BigInt::B;
                        }
                        return a.trim();
                }
                BigInt operator*(const BigInt &a, const BigInt &b)
                {
                        if (a.is0() or b.is0())
                        {
                                return BigInt(0);
                        }
                        BigInt r;
                        r.s = a.s * b.s;
                        r.d.assign(a.d.size() + b.d.size(), 0);
                        for (int i = 0; i < (int)a.d.size(); i++)
                        {
                                long long c = 0;
                                for (int j = 0; j < (int)b.d.size() or c; j++)
                                {
                                        if (i + j == (int)r.d.size())
                                        {
                                                r.d.push_back(0);
                                        }
                                        long long v = r.d[i + j] + c + 1LL * a.d[i] * (j < (int)b.d.size() ? b.d[j] : 0);
                                        r.d[i + j] = (int)(v % BigInt::B);
                                        c = v / BigInt::B;
                                }
                        }
                        return r.trim();
                }
                BigInt operator/(BigInt a, int v)
                {
                        if (v < 0)
                        {
                                a.s = -a.s;
                                v = -v;
                        }
                        long long r = 0;
                        for (int i = (int)a.d.size() - 1; i >= 0; i--)
                        {
                                long long cur = a.d[i] + r * BigInt::B;
                                a.d[i] = (int)(cur / v);
                                r = cur % v;
                        }
                        return a.trim();
                }
                int operator%(const BigInt &a, int v)
                {
                        if (v < 0)
                        {
                                v = -v;
                        }
                        long long r = 0;
                        for (int i = (int)a.d.size() - 1; i >= 0; i--)
                        {
                                long long cur = a.d[i] + r * BigInt::B;
                                r = cur % v;
                        }
                        return (int)(a.s == -1 ? -r : r);
                }
                pair<BigInt, BigInt> divmod(BigInt a, BigInt b)
                {
                        int sa = a.s;
                        int sb = b.s;
                        a = ab(a);
                        b = ab(b);
                        int norm = BigInt::B / (b.d.back() + 1);
                        a = a * norm;
                        b = b * norm;
                        BigInt q;
                        q.s = sa * sb;
                        q.d.assign(a.d.size(), 0);
                        BigInt r;
                        r.s = 1;
                        for (int i = (int)a.d.size() - 1; i >= 0; i--)
                        {
                                r.shl();
                                r.d[0] = a.d[i];
                                r.trim();
                                int s1 = (int)r.d.size() <= (int)b.d.size() ? 0 : r.d[b.d.size()];
                                int s2 = (int)r.d.size() <= (int)b.d.size() - 1 ? 0 : r.d[b.d.size() - 1];
                                long long dd = ((long long)BigInt::B * s1 + s2) / b.d.back();
                                if (dd >= BigInt::B)
                                {
                                        dd = BigInt::B - 1;
                                }
                                r = r - b * (int)dd;
                                while (r.s == -1)
                                {
                                        r = r + b;
                                        dd--;
                                }
                                q.d[i] = (int)dd;
                        }
                        q.trim();
                        r = r / norm;
                        r.s = sa;
                        r.trim();
                        if (q.is0())
                        {
                                q.s = 1;
                        }
                        return {
                            q, r};
                }
                BigInt operator/(const BigInt &a, const BigInt &b)
                {
                        return divmod(a, b).first;
                }
                BigInt operator%(const BigInt &a, const BigInt &b)
                {
                        return divmod(a, b).second;
                }
        }
}

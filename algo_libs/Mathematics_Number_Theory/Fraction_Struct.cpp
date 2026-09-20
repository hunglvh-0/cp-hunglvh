// Source: https://cp-algorithms.com/others/stern_brocot_tree_farey_sequences.html

namespace Fraction_Struct
{
        namespace FractionStruct
        {
                struct Frac
                {
                        long long n;
                        long long d;
                        Frac(long long _n = 0, long long _d = 1)
                        {
                                n = _n;
                                d = _d;
                                norm();
                        }
                        void norm()
                        {
                                if (d == 0)
                                {
                                        n = (n >= 0 ? 1 : -1);
                                        return;
                                }
                                if (n == 0)
                                {
                                        d = 1;
                                        return;
                                }
                                if (d < 0)
                                {
                                        n = -n;
                                        d = -d;
                                }
                                long long g = std::gcd(n, d);
                                if (g < 0)
                                {
                                        g = -g;
                                }
                                n /= g;
                                d /= g;
                        }
                        Frac inv() const
                        {
                                return Frac(d, n);
                        }
                        long double ld() const
                        {
                                return (long double)n / (long double)d;
                        }
                };
                Frac operator-(const Frac &a)
                {
                        return Frac(-a.n, a.d);
                }
                Frac operator+(const Frac &a, const Frac &b)
                {
                        long long g = std::gcd(a.d, b.d);
                        __int128 x = (__int128)a.n * (b.d / g) + (__int128)b.n * (a.d / g);
                        __int128 y = (__int128)a.d / g * b.d;
                        return Frac((long long)x, (long long)y);
                }
                Frac operator-(const Frac &a, const Frac &b)
                {
                        return a + (-b);
                }
                Frac operator*(Frac a, Frac b)
                {
                        long long g1 = std::gcd(a.n, b.d);
                        if (g1 < 0)
                        {
                                g1 = -g1;
                        }
                        long long g2 = std::gcd(b.n, a.d);
                        if (g2 < 0)
                        {
                                g2 = -g2;
                        }
                        a.n /= g1;
                        b.d /= g1;
                        b.n /= g2;
                        a.d /= g2;
                        __int128 x = (__int128)a.n * b.n;
                        __int128 y = (__int128)a.d * b.d;
                        return Frac((long long)x, (long long)y);
                }
                Frac operator/(Frac a, Frac b)
                {
                        return a * b.inv();
                }
                bool operator==(const Frac &a, const Frac &b)
                {
                        return a.n == b.n and a.d == b.d;
                }
                bool operator!=(const Frac &a, const Frac &b)
                {
                        return !(a == b);
                }
                bool operator<(const Frac &a, const Frac &b)
                {
                        return (__int128)a.n * b.d < (__int128)b.n * a.d;
                }
                bool operator>(const Frac &a, const Frac &b)
                {
                        return b < a;
                }
                bool operator<=(const Frac &a, const Frac &b)
                {
                        return !(b < a);
                }
                bool operator>=(const Frac &a, const Frac &b)
                {
                        return !(a < b);
                }
        }
}

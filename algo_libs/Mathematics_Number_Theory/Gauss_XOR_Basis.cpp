// Source: https://oi-wiki.org/math/linear-algebra/basis/

namespace Gauss_XOR_Basis
{
        namespace GaussXorBasis
        {
                struct Basis
                {
                        static const int LG = 63;
                        unsigned long long b[LG + 1];
                        int rk;
                        Basis()
                        {
                                clear();
                        }
                        void clear()
                        {
                                for (int i = 0; i <= LG; ++i)
                                {
                                        b[i] = 0;
                                }
                                rk = 0;
                        }
                        bool add(unsigned long long x)
                        {
                                for (int i = LG; i >= 0; --i)
                                {
                                        if (((x >> i) & 1ULL) == 0)
                                        {
                                                continue;
                                        }
                                        if (!b[i])
                                        {
                                                b[i] = x;
                                                ++rk;
                                                return true;
                                        }
                                        x ^= b[i];
                                }
                                return false;
                        }
                        bool can(unsigned long long x) const
                        {
                                for (int i = LG; i >= 0; --i)
                                {
                                        if (((x >> i) & 1ULL) == 0)
                                        {
                                                continue;
                                        }
                                        if (!b[i])
                                        {
                                                return false;
                                        }
                                        x ^= b[i];
                                }
                                return true;
                        }
                        unsigned long long mx(unsigned long long x = 0) const
                        {
                                unsigned long long r = x;
                                for (int i = LG; i >= 0; --i)
                                {
                                        r = max(r, r ^ b[i]);
                                }
                                return r;
                        }
                        unsigned long long mn_non_zero() const
                        {
                                unsigned long long r = 0;
                                for (int i = 0; i <= LG; ++i)
                                {
                                        if (b[i])
                                        {
                                                r = b[i];
                                                break;
                                        }
                                }
                                if (!r)
                                {
                                        return 0;
                                }
                                for (int i = LG; i >= 0; --i)
                                {
                                        if (b[i] and (r ^ b[i]) < r)
                                        {
                                                r ^= b[i];
                                        }
                                }
                                return r;
                        }
                        vector<unsigned long long> vec() const
                        {
                                Basis t = *this;
                                for (int i = 0; i <= LG; ++i)
                                {
                                        if (!t.b[i])
                                        {
                                                continue;
                                        }
                                        for (int j = i - 1; j >= 0; --j)
                                        {
                                                if ((t.b[i] >> j) & 1ULL)
                                                {
                                                        t.b[i] ^= t.b[j];
                                                }
                                        }
                                }
                                vector<unsigned long long> v;
                                for (int i = 0; i <= LG; ++i)
                                {
                                        if (t.b[i])
                                        {
                                                v.push_back(t.b[i]);
                                        }
                                }
                                return v;
                        }
                        bool kth(unsigned long long k, unsigned long long &r) const
                        {
                                vector<unsigned long long> v = vec();
                                if (v.size() < 64 and k >= (1ULL << v.size()))
                                {
                                        return false;
                                }
                                r = 0;
                                for (int i = 0; i < (int)v.size(); ++i)
                                {
                                        if ((k >> i) & 1ULL)
                                        {
                                                r ^= v[i];
                                        }
                                }
                                return true;
                        }
                        void merge(const Basis &o)
                        {
                                for (int i = 0; i <= LG; ++i)
                                {
                                        if (o.b[i])
                                        {
                                                add(o.b[i]);
                                        }
                                }
                        }
                };
        }
}

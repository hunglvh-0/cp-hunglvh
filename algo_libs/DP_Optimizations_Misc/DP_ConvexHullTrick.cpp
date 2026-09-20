// Source: https://cp-algorithms.com/geometry/convex_hull_trick.html

namespace DP_ConvexHullTrick
{
        namespace DPConvexHullTrick
        {
                struct Line
                {
                        long long m;
                        long long b;
                        long long f(long long x) const
                        {
                                return (long long)((__int128)m * x + b);
                        }
                };
                bool bad(const Line &a, const Line &b, const Line &c)
                {
                        __int128 x1 = (__int128)(a.b - b.b) * (c.m - b.m);
                        __int128 x2 = (__int128)(b.b - c.b) * (b.m - a.m);
                        return x1 >= x2;
                }
                struct MonotoneCHTMin
                {
                        deque<Line> q;
                        void add(long long m, long long b)
                        {
                                Line ln{
                                    m, b};
                                while ((int)q.size() >= 2 and bad(q[(int)q.size() - 2], q.back(), ln))
                                {
                                        q.pop_back();
                                }
                                q.push_back(ln);
                        }
                        long long query(long long x)
                        {
                                while ((int)q.size() >= 2 and q[0].f(x) >= q[1].f(x))
                                {
                                        q.pop_front();
                                }
                                return q.front().f(x);
                        }
                };
                struct LineDyn
                {
                        mutable long long k, m, p;
                        bool operator<(const LineDyn &o) const
                        {
                                return k < o.k;
                        }
                        bool operator<(long long x) const
                        {
                                return p < x;
                        }
                };
                struct LineContainerMax : multiset<LineDyn, less<>>
                {
                        static const long long INF = (long long)4e18;
                        long long div_floor(long long a, long long b)
                        {
                                if (b < 0)
                                {
                                        a = -a;
                                        b = -b;
                                }
                                if (a >= 0)
                                {
                                        return a / b;
                                }
                                return -(((-a) + b - 1) / b);
                        }
                        bool isect(iterator x, iterator y)
                        {
                                if (y == end())
                                {
                                        x->p = INF;
                                        return false;
                                }
                                if (x->k == y->k)
                                {
                                        x->p = (x->m > y->m ? INF : -INF);
                                }
                                else
                                {
                                        x->p = div_floor(y->m - x->m, x->k - y->k);
                                }
                                return x->p >= y->p;
                        }
                        void add(long long k, long long m)
                        {
                                auto z = insert(
                                         {k, m, 0}),
                                     y = z++, x = y;
                                while (isect(y, z))
                                {
                                        z = erase(z);
                                }
                                if (x != begin() and isect(--x, y))
                                {
                                        isect(x, y = erase(y));
                                }
                                while ((y = x) != begin() and (--x)->p >= y->p)
                                {
                                        isect(x, erase(y));
                                }
                        }
                        long long query(long long x)
                        {
                                auto l = *lower_bound(x);
                                return (long long)((__int128)l.k * x + l.m);
                        }
                };
        }
}

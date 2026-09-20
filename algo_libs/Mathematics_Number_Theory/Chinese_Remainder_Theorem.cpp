// Source: https://cp-algorithms.com/algebra/chinese-remainder-theorem.html

namespace Chinese_Remainder_Theorem
{
    namespace ChineseRemainderTheorem
    {
        struct Eq
    {
            long long r;
            long long m;

    }
    ;
        long long exg(long long a, long long b, long long &x, long long &y)
    {
            if (b == 0)
    {
                x = 1;
                y = 0;
                return a;

    }
            long long x1 = 0;
            long long y1 = 0;
            long long g = exg(b, a % b, x1, y1);
            x = y1;
            y = x1 - y1 * (a / b);
            return g;

    }
        long long norm(long long x, long long m)
    {
            x %= m;
            if (x < 0)
    {
                x += m;

    }
            return x;

    }
        pair<long long, long long> crt2(long long r1, long long m1, long long r2, long long m2)
    {
            r1 = norm(r1, m1);
            r2 = norm(r2, m2);
            long long x = 0;
            long long y = 0;
            long long g = exg(m1, m2, x, y);
            if ((r2 - r1) % g != 0)
    {
                return
    {
    -1, -1
    }
    ;

    }
            long long l = m2 / g;
            long long t = norm((r2 - r1) / g, l);
            long long k = (long long)((__int128)t * norm(x, l) % l);
            long long m = m1 / g * m2;
            long long r = norm(r1 + (long long)((__int128)m1 * k % m), m);
            return
    {
    r, m
    }
    ;

    }
        pair<long long, long long> crt(const vector<Eq> &a)
    {
            if (a.empty())
    {
                return
    {
    0, 1
    }
    ;

    }
            long long r = norm(a[0].r, a[0].m);
            long long m = a[0].m;
            for (int i = 1; i < (int)a.size(); i++)
    {
                auto t = crt2(r, m, a[i].r, a[i].m);
                if (t.first == -1)
    {
                    return
    {
    -1, -1
    }
    ;

    }
                r = t.first;
                m = t.second;

    }
            return
    {
    r, m
    }
    ;

    }
        pair<long long, long long> excrt(const vector<Eq> &a)
    {
            if (a.empty())
    {
                return
    {
    0, 1
    }
    ;

    }
            long long r = norm(a[0].r, a[0].m);
            long long m = a[0].m;
            for (int i = 1; i < (int)a.size(); i++)
    {
                auto t = crt2(r, m, a[i].r, a[i].m);
                if (t.first == -1)
    {
                    return
    {
    -1, -1
    }
    ;

    }
                r = t.first;
                m = t.second;

    }
            return
    {
    r, m
    }
    ;

    }
    }
}

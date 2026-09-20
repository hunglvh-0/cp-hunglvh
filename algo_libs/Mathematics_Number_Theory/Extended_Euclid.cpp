// Source: https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

namespace Extended_Euclid
{
    namespace ExtendedEuclid
    {
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
        long long exg_it(long long a, long long b, long long &x, long long &y)
    {
            x = 1;
            y = 0;
            long long x1 = 0;
            long long y1 = 1;
            long long a1 = a;
            long long b1 = b;
            while (b1)
    {
                long long q = a1 / b1;
                long long nx = x1;
                long long ny = y1;
                x1 = x - q * x1;
                y1 = y - q * y1;
                x = nx;
                y = ny;
                long long nb = a1 - q * b1;
                a1 = b1;
                b1 = nb;

    }
            return a1;

    }
        long long inv_mod(long long a, long long m)
    {
            long long x = 0;
            long long y = 0;
            long long g = exg(a, m, x, y);
            if (g != 1)
    {
                return -1;

    }
            x %= m;
            if (x < 0)
    {
                x += m;

    }
            return x;

    }
        bool lin(long long a, long long b, long long c, long long &x, long long &y, long long &g)
    {
            g = exg(a, b, x, y);
            if (c % g)
    {
                return false;

    }
            x *= c / g;
            y *= c / g;
            return true;

    }
    }
}

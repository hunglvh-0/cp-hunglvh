// Source: Local/Reconstructed

namespace MinimumEnclosingCircle_Welzl
{
    namespace geom_mec
    {
        const long double EPS = 1e-12L;
        struct Pt
    {
            long double x = 0, y = 0;
            Pt() = default;
            Pt(long double _x, long double _y) : x(_x), y(_y)
    {
    }
            Pt operator+(const Pt &o) const
    {
     return Pt(x + o.x, y + o.y); 
    }
            Pt operator-(const Pt &o) const
    {
     return Pt(x - o.x, y - o.y); 
    }
            Pt operator*(long double k) const
    {
     return Pt(x * k, y * k); 
    }
            Pt operator/(long double k) const
    {
     return Pt(x / k, y / k); 
    }

    }
    ;
        long double dot(Pt a, Pt b)
    {
     return a.x * b.x + a.y * b.y; 
    }
        long double cross(Pt a, Pt b)
    {
     return a.x * b.y - a.y * b.x; 
    }
        long double norm2(Pt a)
    {
     return dot(a, a); 
    }
        struct Circle
    {
            Pt c;
            long double r = -1;

    }
    ;
        bool inside(const Circle &C, Pt p)
    {
            if (C.r < 0)
                return false;
            return norm2(p - C.c) <= C.r * C.r + 1e-10L;

    }
        Circle circle2(Pt a, Pt b)
    {
            Pt c = (a + b) / 2;
            return
    {
    c, sqrtl(norm2(a - c))
    }
    ;

    }
        Circle circle3(Pt a, Pt b, Pt c)
    {
            long double d = 2 * cross(b - a, c - a);
            if (fabsl(d) <= EPS)
                return
    {
    {
    0, 0
    }
    , -1
    }
    ;
            long double a2 = norm2(a), b2 = norm2(b), c2 = norm2(c);
            long double ux = (a2 * (b.y - c.y) + b2 * (c.y - a.y) + c2 * (a.y - b.y)) / d;
            long double uy = (a2 * (c.x - b.x) + b2 * (a.x - c.x) + c2 * (b.x - a.x)) / d;
            Pt o(ux, uy);
            return
    {
    o, sqrtl(norm2(o - a))
    }
    ;

    }
        Circle minimumEnclosingCircle(vector<Pt> p)
    {
            mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
            shuffle(p.begin(), p.end(), rng);
            Circle C
    {
    {0, 0
    }
    , -1
    }
    ;
            for (int i = 0; i < (int)p.size(); ++i)
    {
                if (inside(C, p[i]))
                    continue;
                C =
    {
    p[i], 0
    }
    ;
                for (int j = 0; j < i; ++j)
    {
                    if (inside(C, p[j]))
                        continue;
                    C = circle2(p[i], p[j]);
                    for (int k = 0; k < j; ++k)
    {
                        if (inside(C, p[k]))
                            continue;
                        Circle D = circle3(p[i], p[j], p[k]);
                        if (D.r >= 0)
                            C = D;

    }

    }

    }
            return C;

    }
    }
     // namespace geom_mec
}

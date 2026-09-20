// Source: Local/Reconstructed

namespace Point_Vector_2D
{
    namespace geom2d
    {
        const long double EPS = 1e-12L;
        const long double PI = acosl(-1.0L);
        struct P
    {
            long double x = 0, y = 0;
            P() = default;
            P(long double _x, long double _y) : x(_x), y(_y)
    {
    }
            P operator+(const P &o) const
    {
     return P(x + o.x, y + o.y); 
    }
            P operator-(const P &o) const
    {
     return P(x - o.x, y - o.y); 
    }
            P operator*(long double k) const
    {
     return P(x * k, y * k); 
    }
            P operator/(long double k) const
    {
     return P(x / k, y / k); 
    }

    }
    ;
        long double dot(P a, P b)
    {
     return a.x * b.x + a.y * b.y; 
    }
        long double cross(P a, P b)
    {
     return a.x * b.y - a.y * b.x; 
    }
        long double norm2(P a)
    {
     return dot(a, a); 
    }
        long double norm(P a)
    {
     return sqrtl(max((long double)0, norm2(a))); 
    }
        P unit(P a)
    {
            long double n = norm(a);
            if (n <= EPS)
                return P(0, 0);
            return a / n;

    }
        P rotate(P a, long double ang)
    {
            long double c = cosl(ang), s = sinl(ang);
            return P(a.x * c - a.y * s, a.x * s + a.y * c);

    }
        P rotate90(P a)
    {
     return P(-a.y, a.x); 
    }
        long double angle(P a, P b)
    {
            long double v = dot(a, b) / max((long double)EPS, norm(a) * norm(b));
            v = max((long double)-1, min((long double)1, v));
            return acosl(v);

    }
        P projectionPointLine(P p, P a, P b)
    {
            P ab = b - a;
            long double t = dot(p - a, ab) / max((long double)EPS, norm2(ab));
            return a + ab * t;

    }
        P projectionPointSegment(P p, P a, P b)
    {
            P ab = b - a;
            long double t = dot(p - a, ab) / max((long double)EPS, norm2(ab));
            t = max((long double)0, min((long double)1, t));
            return a + ab * t;

    }
        P reflectPointLine(P p, P a, P b)
    {
            P q = projectionPointLine(p, a, b);
            return q * 2 - p;

    }
        long double distancePointLine(P p, P a, P b)
    {
            return fabsl(cross(b - a, p - a)) / max((long double)EPS, norm(b - a));

    }
        long double distancePointSegment(P p, P a, P b)
    {
            P q = projectionPointSegment(p, a, b);
            return norm(p - q);

    }
        int ccw(P a, P b, P c)
    {
            long double v = cross(b - a, c - a);
            if (v > EPS)
                return 1;
            if (v < -EPS)
                return -1;
            return 0;

    }
    }
     // namespace geom2d
}

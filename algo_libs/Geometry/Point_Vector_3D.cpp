// Source: Local/Reconstructed

namespace Point_Vector_3D
{
    namespace geom3d
    {
        const long double EPS = 1e-12L;
        struct P
    {
            long double x = 0, y = 0, z = 0;
            P() = default;
            P(long double _x, long double _y, long double _z) : x(_x), y(_y), z(_z)
    {
    }
            P operator+(const P &o) const
    {
     return P(x + o.x, y + o.y, z + o.z); 
    }
            P operator-(const P &o) const
    {
     return P(x - o.x, y - o.y, z - o.z); 
    }
            P operator*(long double k) const
    {
     return P(x * k, y * k, z * k); 
    }
            P operator/(long double k) const
    {
     return P(x / k, y / k, z / k); 
    }

    }
    ;
        long double dot(P a, P b)
    {
     return a.x * b.x + a.y * b.y + a.z * b.z; 
    }
        P cross(P a, P b)
    {
            return P(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);

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
                return P(0, 0, 0);
            return a / n;

    }
        struct Plane
    {
            P n;
            long double d = 0; // n.x*x + n.y*y + n.z*z + d = 0

    }
    ;
        Plane planeFromPoints(P a, P b, P c)
    {
            P n = cross(b - a, c - a);
            long double d = -dot(n, a);
            return
    {
    n, d
    }
    ;

    }
        long double signedDistancePointPlane(P p, const Plane &pl)
    {
            return (dot(pl.n, p) + pl.d) / max((long double)EPS, norm(pl.n));

    }
        long double distancePointPlane(P p, const Plane &pl)
    {
            return fabsl(signedDistancePointPlane(p, pl));

    }
        long double volume6(P a, P b, P c, P d)
    {
            return dot(cross(b - a, c - a), d - a);

    }
        long double tetraVolume(P a, P b, P c, P d)
    {
            return fabsl(volume6(a, b, c, d)) / 6.0L;

    }
    }
     // namespace geom3d
}

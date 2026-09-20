// Source: Local/Reconstructed

namespace Polygon_Area_PickTheorem
{
    namespace geom_pick
    {
        struct P
    {
            long long x = 0, y = 0;

    }
    ;
        long long cross(P a, P b)
    {
     return a.x * b.y - a.y * b.x; 
    }
        P operator-(P a, P b)
    {
     return
    {
    a.x - b.x, a.y - b.y
    }
    ; 
    }
        long long polygonArea2Signed(const vector<P> &poly)
    {
            int n = (int)poly.size();
            long long s = 0;
            for (int i = 0; i < n; ++i)
    {
                int j = (i + 1) % n;
                s += cross(poly[i], poly[j]);

    }
            return s;

    }
        long long polygonArea2(const vector<P> &poly)
    {
            long long a = polygonArea2Signed(poly);
            return a >= 0 ? a : -a;

    }
        long double polygonArea(const vector<P> &poly)
    {
            return (long double)polygonArea2(poly) / 2.0L;

    }
        long long boundaryLatticePoints(const vector<P> &poly)
    {
            int n = (int)poly.size();
            long long b = 0;
            for (int i = 0; i < n; ++i)
    {
                int j = (i + 1) % n;
                long long dx = llabs(poly[j].x - poly[i].x);
                long long dy = llabs(poly[j].y - poly[i].y);
                b += std::gcd(dx, dy);

    }
            return b;

    }
        long long interiorLatticePoints(const vector<P> &poly)
    {
            long long A2 = polygonArea2(poly);
            long long B = boundaryLatticePoints(poly);
            return (A2 - B + 2) / 2;

    }
    }
     // namespace geom_pick
}

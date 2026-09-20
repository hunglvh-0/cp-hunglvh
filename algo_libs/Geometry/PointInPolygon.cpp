// Source: Local/Reconstructed

namespace PointInPolygon
{
    namespace geom_pip
    {
        const long double EPS = 1e-12L;
        struct Pt
    {
            long double x = 0, y = 0;

    }
    ;
        Pt operator-(Pt a, Pt b)
    {
     return
    {
    a.x - b.x, a.y - b.y
    }
    ; 
    }
        long double cross(Pt a, Pt b)
    {
     return a.x * b.y - a.y * b.x; 
    }
        long double cross(Pt a, Pt b, Pt c)
    {
     return cross(b - a, c - a); 
    }
        bool onSegment(Pt a, Pt b, Pt p)
    {
            if (fabsl(cross(a, b, p)) > EPS)
                return false;
            return min(a.x, b.x) - EPS <= p.x and p.x <= max(a.x, b.x) + EPS and
                   min(a.y, b.y) - EPS <= p.y and p.y <= max(a.y, b.y) + EPS;

    }
        int pointInPolygonRayCasting(const vector<Pt> &poly, Pt p)
    {
            int n = (int)poly.size();
            bool in = false;
            for (int i = 0, j = n - 1; i < n; j = i++)
    {
                Pt a = poly[j], b = poly[i];
                if (onSegment(a, b, p))
                    return 1;
                bool cond = ((a.y > p.y) != (b.y > p.y));
                if (cond)
    {
                    long double xint = a.x + (b.x - a.x) * (p.y - a.y) / (b.y - a.y);
                    if (xint > p.x - EPS)
                        in = !in;

    }

    }
            return in ? 2 : 0;

    }
        int windingNumber(const vector<Pt> &poly, Pt p)
    {
            int wn = 0, n = (int)poly.size();
            for (int i = 0; i < n; ++i)
    {
                Pt a = poly[i], b = poly[(i + 1) % n];
                if (onSegment(a, b, p))
                    return INT_MAX;
                if (a.y <= p.y)
    {
                    if (b.y > p.y and cross(a, b, p) > EPS)
                        ++wn;

    }
    else
    {
                    if (b.y <= p.y and cross(a, b, p) < -EPS)
                        --wn;

    }

    }
            return wn;

    }
    }
     // namespace geom_pip
}

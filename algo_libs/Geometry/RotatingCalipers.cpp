// Source: Local/Reconstructed

namespace RotatingCalipers
{
    namespace geom_calipers
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
        long double cross(Pt a, Pt b, Pt c)
    {
     return cross(b - a, c - a); 
    }
        long double norm(Pt a)
    {
     return sqrtl(max((long double)0, dot(a, a))); 
    }
        long double dist2(Pt a, Pt b)
    {
     return dot(a - b, a - b); 
    }
        long double diameter2ConvexPolygon(const vector<Pt> &p)
    {
            int n = (int)p.size();
            if (n <= 1)
                return 0;
            if (n == 2)
                return dist2(p[0], p[1]);
            int j = 1;
            long double best = 0;
            for (int i = 0; i < n; ++i)
    {
                int ni = (i + 1) % n;
                while (fabsl(cross(p[ni] - p[i], p[(j + 1) % n] - p[i])) > fabsl(cross(p[ni] - p[i], p[j] - p[i])) + EPS)
    {
                    j = (j + 1) % n;

    }
                best = max(best, dist2(p[i], p[j]));
                best = max(best, dist2(p[ni], p[j]));

    }
            return best;

    }
        long double minAreaBoundingBox(const vector<Pt> &p)
    {
            int n = (int)p.size();
            if (n <= 2)
                return 0;
            int j = 1, k = 1, l = 1;
            long double ans = 1e100L;
            for (int i = 0; i < n; ++i)
    {
                int ni = (i + 1) % n;
                Pt e = p[ni] - p[i];
                long double len = norm(e);
                if (len <= EPS)
                    continue;
                while (fabsl(cross(e, p[(j + 1) % n] - p[i])) > fabsl(cross(e, p[j] - p[i])) + EPS)
                    j = (j + 1) % n;
                while (dot(e, p[(k + 1) % n]) > dot(e, p[k]) + EPS)
                    k = (k + 1) % n;
                while (dot(e, p[(l + 1) % n]) < dot(e, p[l]) - EPS)
                    l = (l + 1) % n;
                long double height = fabsl(cross(e, p[j] - p[i])) / len;
                long double width = (dot(e, p[k]) - dot(e, p[l])) / len;
                ans = min(ans, width * height);

    }
            return ans;

    }
    }
     // namespace geom_calipers
}

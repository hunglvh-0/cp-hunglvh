// Source: Local/Reconstructed

namespace Circle_Intersections
{
    namespace geom_circle
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
        long double norm(Pt a)
    {
     return sqrtl(max((long double)0, norm2(a))); 
    }
        Pt perp(Pt a)
    {
     return Pt(-a.y, a.x); 
    }
        struct Circle
    {
            Pt c;
            long double r = 0;

    }
    ;
        vector<Pt> lineCircleIntersection(Pt A, Pt B, Circle O)
    {
            Pt d = B - A;
            Pt f = A - O.c;
            long double a = dot(d, d);
            long double b = 2 * dot(f, d);
            long double c = dot(f, f) - O.r * O.r;
            long double D = b * b - 4 * a * c;
            vector<Pt> ans;
            if (D < -EPS)
                return ans;
            if (fabsl(D) <= EPS)
    {
                long double t = -b / (2 * a);
                ans.push_back(A + d * t);
                return ans;

    }
            long double sq = sqrtl(max((long double)0, D));
            long double t1 = (-b - sq) / (2 * a);
            long double t2 = (-b + sq) / (2 * a);
            ans.push_back(A + d * t1);
            ans.push_back(A + d * t2);
            return ans;

    }
        vector<Pt> circleCircleIntersection(Circle A, Circle B)
    {
            vector<Pt> ans;
            Pt d = B.c - A.c;
            long double dist2 = norm2(d);
            long double dist = sqrtl(max((long double)0, dist2));
            if (dist < EPS and fabsl(A.r - B.r) < EPS)
                return ans; // infinite
            if (dist > A.r + B.r + EPS)
                return ans;
            if (dist + min(A.r, B.r) + EPS < max(A.r, B.r))
                return ans;
            long double x = (dist2 + A.r * A.r - B.r * B.r) / (2 * dist);
            long double y2 = A.r * A.r - x * x;
            if (y2 < -EPS)
                return ans;
            y2 = max((long double)0, y2);
            long double y = sqrtl(y2);
            Pt v = d / dist;
            Pt p = A.c + v * x;
            Pt off = perp(v) * y;
            if (y <= EPS)
                ans.push_back(p);
            else
    {
                ans.push_back(p - off);
                ans.push_back(p + off);

    }
            return ans;

    }
    }
     // namespace geom_circle
}

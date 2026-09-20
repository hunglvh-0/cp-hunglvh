// Source: Local/Reconstructed

namespace ConvexHull_MonotoneChain
{
    namespace geom_hull2d
    {
        const long double EPS = 1e-12L;
        struct Pt
    {
            long double x = 0, y = 0;
            bool operator<(const Pt &o) const
    {
                if (fabsl(x - o.x) > EPS)
                    return x < o.x;
                return y < o.y;

    }
            bool operator==(const Pt &o) const
    {
                return fabsl(x - o.x) <= EPS and fabsl(y - o.y) <= EPS;

    }

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
        vector<Pt> convexHullMonotoneChain(vector<Pt> p, bool keepCollinear = false)
    {
            sort(p.begin(), p.end());
            p.erase(unique(p.begin(), p.end()), p.end());
            if ((int)p.size() <= 1)
                return p;
            vector<Pt> lo, up;
            for (auto pt : p)
    {
                while ((int)lo.size() >= 2)
    {
                    long double cr = cross(lo[(int)lo.size() - 2], lo.back(), pt);
                    if (cr > EPS or (keepCollinear and fabsl(cr) <= EPS))
                        break;
                    lo.pop_back();

    }
                lo.push_back(pt);

    }
            for (int i = (int)p.size() - 1; i >= 0; --i)
    {
                Pt pt = p[i];
                while ((int)up.size() >= 2)
    {
                    long double cr = cross(up[(int)up.size() - 2], up.back(), pt);
                    if (cr > EPS or (keepCollinear and fabsl(cr) <= EPS))
                        break;
                    up.pop_back();

    }
                up.push_back(pt);

    }
            lo.pop_back();
            up.pop_back();
            lo.insert(lo.end(), up.begin(), up.end());
            if (lo.empty())
                lo.push_back(p[0]);
            return lo;

    }
    }
     // namespace geom_hull2d
}

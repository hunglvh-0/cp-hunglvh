// Source: Local/Reconstructed

namespace HalfPlaneIntersection
{
    namespace geom_hpi
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
        long double cross(Pt a, Pt b)
    {
     return a.x * b.y - a.y * b.x; 
    }
        struct Line
    {
            Pt p, v;
            long double ang;
            Line() = default;
            Line(Pt _p, Pt _v) : p(_p), v(_v), ang(atan2l(v.y, v.x))
    {
    }
            bool operator<(const Line &o) const
    {
                if (fabsl(ang - o.ang) > EPS)
                    return ang < o.ang;
                return cross(v, o.p - p) < 0;

    }

    }
    ;
        bool parallel(const Line &a, const Line &b)
    {
            return fabsl(cross(a.v, b.v)) <= EPS;

    }
        Pt lineIntersection(const Line &a, const Line &b)
    {
            Pt u = b.p - a.p;
            long double t = cross(u, b.v) / cross(a.v, b.v);
            return a.p + a.v * t;

    }
        bool onLeft(const Line &l, const Pt &q)
    {
            return cross(l.v, q - l.p) >= -EPS;

    }
        vector<Pt> halfPlaneIntersection(vector<Line> ln)
    {
            sort(ln.begin(), ln.end());
            deque<Line> q;
            deque<Pt> p;
            for (auto l : ln)
    {
                if (!q.empty() and parallel(q.back(), l))
    {
                    if (onLeft(l, q.back().p))
                        q.back() = l;
                    continue;

    }
                while (!p.empty() and !onLeft(l, p.back()))
    {
                    p.pop_back();
                    q.pop_back();

    }
                while (!p.empty() and !onLeft(l, p.front()))
    {
                    p.pop_front();
                    q.pop_front();

    }
                if (!q.empty())
                    p.push_back(lineIntersection(q.back(), l));
                q.push_back(l);

    }
            while (p.size() and !onLeft(q.front(), p.back()))
    {
                p.pop_back();
                q.pop_back();

    }
            while (p.size() and !onLeft(q.back(), p.front()))
    {
                p.pop_front();
                q.pop_front();

    }
            if ((int)q.size() < 3)
                return
    {
    }
    ;
            p.push_back(lineIntersection(q.back(), q.front()));
            return vector<Pt>(p.begin(), p.end());

    }
    }
     // namespace geom_hpi
}

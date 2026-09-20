// Source: Local/Reconstructed

namespace Line_Sweep
{
    namespace geom_line_sweep
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
        int sgn(long double x)
    {
            if (x > EPS)
                return 1;
            if (x < -EPS)
                return -1;
            return 0;

    }
        bool onSeg(Pt a, Pt b, Pt p)
    {
            if (sgn(cross(a, b, p)) != 0)
                return false;
            return min(a.x, b.x) - EPS <= p.x and p.x <= max(a.x, b.x) + EPS and
                   min(a.y, b.y) - EPS <= p.y and p.y <= max(a.y, b.y) + EPS;

    }
        bool segInter(Pt a, Pt b, Pt c, Pt d)
    {
            int o1 = sgn(cross(a, b, c));
            int o2 = sgn(cross(a, b, d));
            int o3 = sgn(cross(c, d, a));
            int o4 = sgn(cross(c, d, b));
            if (o1 == 0 and onSeg(a, b, c))
                return true;
            if (o2 == 0 and onSeg(a, b, d))
                return true;
            if (o3 == 0 and onSeg(c, d, a))
                return true;
            if (o4 == 0 and onSeg(c, d, b))
                return true;
            return o1 * o2 < 0 and o3 * o4 < 0;

    }
        struct Segment
    {
            Pt a, b;
            int id = -1;
            long double getY(long double x) const
    {
                if (fabsl(a.x - b.x) <= EPS)
                    return min(a.y, b.y);
                long double t = (x - a.x) / (b.x - a.x);
                return a.y + (b.y - a.y) * t;

    }

    }
    ;
        struct Event
    {
            long double x;
            int tp; // 0 add, 1 remove
            int id;
            bool operator<(const Event &o) const
    {
                if (fabsl(x - o.x) > EPS)
                    return x < o.x;
                if (tp != o.tp)
                    return tp < o.tp;
                return id < o.id;

    }

    }
    ;
        struct Sweep
    {
            vector<Segment> s;
            long double curX = 0;
            struct Cmp
    {
                const Sweep *sw;
                Cmp(const Sweep *_sw = nullptr) : sw(_sw)
    {
    }
                bool operator()(int i, int j) const
    {
                    if (i == j)
                        return false;
                    long double y1 = sw->s[i].getY(sw->curX);
                    long double y2 = sw->s[j].getY(sw->curX);
                    if (fabsl(y1 - y2) > EPS)
                        return y1 < y2;
                    return i < j;

    }

    }
    ;
            pair<int, int> anyIntersection(vector<Segment> seg)
    {
                s = seg;
                vector<Event> ev;
                for (int i = 0; i < (int)s.size(); ++i)
    {
                    if (s[i].b.x < s[i].a.x)
                        swap(s[i].a, s[i].b);
                    s[i].id = i;
                    ev.push_back(
    {
    s[i].a.x, 0, i
    }
    );
                    ev.push_back(
    {
    s[i].b.x, 1, i
    }
    );

    }
                sort(ev.begin(), ev.end());
                set<int, Cmp> st((Cmp(this)));
                vector<set<int, Cmp>::iterator> it(s.size());
                auto check = [&](set<int, Cmp>::iterator A, set<int, Cmp>::iterator B)
    {
                    if (A == st.end() or B == st.end())
                        return pair<int, int>
    {
    -1, -1
    }
    ;
                    int i = *A, j = *B;
                    if (segInter(s[i].a, s[i].b, s[j].a, s[j].b))
                        return
    {
    i, j
    }
    ;
                    return pair<int, int>
    {
    -1, -1
    }
    ;

    }
    ;
                for (auto e : ev)
    {
                    curX = e.x;
                    int id = e.id;
                    if (e.tp == 0)
    {
                        auto pos = st.lower_bound(id);
                        auto prv = pos;
                        if (prv != st.begin())
                            --prv;
                        auto nx = pos;
                        it[id] = st.insert(pos, id);
                        auto r1 = check(it[id], nx);
                        if (r1.first != -1)
                            return r1;
                        if (it[id] != st.begin())
    {
                            auto pv = it[id];
                            --pv;
                            auto r2 = check(pv, it[id]);
                            if (r2.first != -1)
                                return r2;

    }

    }
    else
    {
                        auto cur = it[id];
                        auto nx = next(cur);
                        auto pv = cur;
                        bool hasPv = (cur != st.begin());
                        if (hasPv)
                            --pv;
                        if (hasPv and nx != st.end())
    {
                            auto r = check(pv, nx);
                            if (r.first != -1)
                                return r;

    }
                        st.erase(cur);

    }

    }
                return
    {
    -1, -1
    }
    ;

    }

    }
    ;
    }
     // namespace geom_line_sweep
}

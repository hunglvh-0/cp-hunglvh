// Source: Local/Reconstructed

namespace DelaunayTriangulation_Voronoi
{
    namespace geom_delaunay
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
        long double cross(Pt a, Pt b, Pt c)
    {
     return cross(b - a, c - a); 
    }
        long double norm2(Pt a)
    {
     return a.x * a.x + a.y * a.y; 
    }
        struct Tri
    {
            int a = -1, b = -1, c = -1;
            Pt cen;
            long double r2 = -1;
            bool bad = false;

    }
    ;
        struct DelaunayVoronoi
    {
            vector<Pt> p;
            vector<Tri> tri;
            pair<Pt, long double> circumcircle(Pt A, Pt B, Pt C)
    {
                long double d = 2 * cross(A - C, B - C);
                if (fabsl(d) <= EPS)
                    return
    {
    Pt(0, 0), -1
    }
    ;
                long double a2 = norm2(A), b2 = norm2(B), c2 = norm2(C);
                long double ux = (a2 * (B.y - C.y) + b2 * (C.y - A.y) + c2 * (A.y - B.y)) / d;
                long double uy = (a2 * (C.x - B.x) + b2 * (A.x - C.x) + c2 * (B.x - A.x)) / d;
                Pt o(ux, uy);
                return
    {
    o, norm2(o - A)
    }
    ;

    }
            Tri makeTri(int a, int b, int c)
    {
                if (cross(p[a], p[b], p[c]) < 0)
                    swap(b, c);
                Tri t
    {
    a, b, c, Pt(), -1, false
    }
    ;
                auto cc = circumcircle(p[t.a], p[t.b], p[t.c]);
                t.cen = cc.first;
                t.r2 = cc.second;
                return t;

    }
            bool inCirc(const Tri &t, Pt q) const
    {
                if (t.r2 < 0)
                    return false;
                return norm2(q - t.cen) <= t.r2 + 1e-10L;

    }
            vector<array<int, 3>> build(vector<Pt> in)
    {
                p = in;
                tri.clear();
                int n = (int)p.size();
                if (n < 3)
                    return
    {
    }
    ;
                mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
                shuffle(p.begin(), p.end(), rng);
                long double minx = p[0].x, maxx = p[0].x, miny = p[0].y, maxy = p[0].y;
                for (auto q : p)
    {
                    minx = min(minx, q.x);
                    maxx = max(maxx, q.x);
                    miny = min(miny, q.y);
                    maxy = max(maxy, q.y);

    }
                long double dx = maxx - minx, dy = maxy - miny;
                long double d = max(dx, dy) + 1;
                Pt c((minx + maxx) / 2, (miny + maxy) / 2);
                int s1 = (int)p.size();
                p.push_back(Pt(c.x - 20 * d, c.y - d));
                int s2 = (int)p.size();
                p.push_back(Pt(c.x, c.y + 20 * d));
                int s3 = (int)p.size();
                p.push_back(Pt(c.x + 20 * d, c.y - d));
                tri.push_back(makeTri(s1, s2, s3));
                for (int i = 0; i < n; ++i)
    {
                    for (auto &t : tri)
                        t.bad = false;
                    vector<int> bad;
                    for (int j = 0; j < (int)tri.size(); ++j)
    {
                        if (inCirc(tri[j], p[i]))
    {
                            tri[j].bad = true;
                            bad.push_back(j);

    }

    }
                    map<pair<int, int>, int> edge;
                    auto addUndir = [&](int a, int b)
    {
                        if (a > b)
                            swap(a, b);
                        edge[
    {
    a, b
    }
    ]++;

    }
    ;
                    for (int id : bad)
    {
                        auto &t = tri[id];
                        addUndir(t.a, t.b);
                        addUndir(t.b, t.c);
                        addUndir(t.c, t.a);

    }
                    vector<Tri> nxt;
                    nxt.reserve(tri.size() + edge.size());
                    for (auto &t : tri)
                        if (!t.bad)
                            nxt.push_back(t);
                    for (auto [e, cnt] : edge)
    {
                        if (cnt != 1)
                            continue;
                        nxt.push_back(makeTri(e.first, e.second, i));

    }
                    tri.swap(nxt);

    }
                vector<array<int, 3>> ans;
                for (auto &t : tri)
    {
                    if (t.a >= n or t.b >= n or t.c >= n)
                        continue;
                    ans.push_back(
    {
    t.a, t.b, t.c
    }
    );

    }
                return ans;

    }
            vector<vector<Pt>> buildVoronoiCells(int origN)
    {
                vector<vector<int>> inc(origN);
                for (int i = 0; i < (int)tri.size(); ++i)
    {
                    auto &t = tri[i];
                    if (t.a < origN)
                        inc[t.a].push_back(i);
                    if (t.b < origN)
                        inc[t.b].push_back(i);
                    if (t.c < origN)
                        inc[t.c].push_back(i);

    }
                vector<vector<Pt>> cells(origN);
                for (int i = 0; i < origN; ++i)
    {
                    auto &ids = inc[i];
                    sort(ids.begin(), ids.end(), [&](int u, int v)
    {
    				Pt a = tri[u].cen - p[i];
    				Pt b = tri[v].cen - p[i];
    				return atan2l(a.y, a.x) < atan2l(b.y, b.x); 
    }
    );
                    for (int id : ids)
                        cells[i].push_back(tri[id].cen);

    }
                return cells;

    }

    }
    ;
    }
     // namespace geom_delaunay
}

// Source: Local/Reconstructed

namespace ClosestPairOfPoints
{
    namespace geom_closest_pair
    {
        struct Pt
    {
            long double x = 0, y = 0;
            int id = -1;

    }
    ;
        long double dist2(const Pt &a, const Pt &b)
    {
            long double dx = a.x - b.x;
            long double dy = a.y - b.y;
            return dx * dx + dy * dy;

    }
        struct ClosestPair
    {
            vector<Pt> p, tmp;
            long double best;
            pair<int, int> who;
            void upd(const Pt &a, const Pt &b)
    {
                long double d = dist2(a, b);
                if (d < best)
    {
                    best = d;
                    who =
    {
    a.id, b.id
    }
    ;

    }

    }
            void rec(int l, int r)
    {
                if (r - l <= 3)
    {
                    for (int i = l; i <= r; ++i)
    {
                        for (int j = i + 1; j <= r; ++j)
                            upd(p[i], p[j]);

    }
                    sort(p.begin() + l, p.begin() + r + 1, [](const Pt &a, const Pt &b)
    {
    				if (a.y != b.y) return a.y < b.y;
    				return a.x < b.x; 
    }
    );
                    return;

    }
                int m = (l + r) >> 1;
                long double midx = p[m].x;
                rec(l, m);
                rec(m + 1, r);
                merge(p.begin() + l, p.begin() + m + 1, p.begin() + m + 1, p.begin() + r + 1, tmp.begin() + l,
                      [](const Pt &a, const Pt &b)
    {
                          if (a.y != b.y)
                              return a.y < b.y;
                          return a.x < b.x;

    }
    );
                for (int i = l; i <= r; ++i)
                    p[i] = tmp[i];
                vector<Pt> strip;
                strip.reserve(r - l + 1);
                for (int i = l; i <= r; ++i)
    {
                    long double dx = p[i].x - midx;
                    if (dx * dx < best)
                        strip.push_back(p[i]);

    }
                for (int i = 0; i < (int)strip.size(); ++i)
    {
                    for (int j = i + 1; j < (int)strip.size(); ++j)
    {
                        long double dy = strip[j].y - strip[i].y;
                        if (dy * dy >= best)
                            break;
                        upd(strip[i], strip[j]);

    }

    }

    }
            pair<long double, pair<int, int>> solve(vector<Pt> a)
    {
                int n = (int)a.size();
                p = a;
                tmp.assign(n, Pt());
                sort(p.begin(), p.end(), [](const Pt &A, const Pt &B)
    {
    			if (A.x != B.x) return A.x < B.x;
    			return A.y < B.y; 
    }
    );
                best = 1e100L;
                who =
    {
    -1, -1
    }
    ;
                if (n >= 2)
                    rec(0, n - 1);
                return
    {
    best, who
    }
    ;

    }

    }
    ;
    }
     // namespace geom_closest_pair
}

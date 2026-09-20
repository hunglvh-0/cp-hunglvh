// Source: Local/Reconstructed

namespace ConvexHull_3D
{
    namespace geom_hull3d
    {
        const long double EPS = 1e-12L;
        struct P3
    {
            long double x = 0, y = 0, z = 0;
            P3() = default;
            P3(long double _x, long double _y, long double _z) : x(_x), y(_y), z(_z)
    {
    }
            P3 operator+(const P3 &o) const
    {
     return P3(x + o.x, y + o.y, z + o.z); 
    }
            P3 operator-(const P3 &o) const
    {
     return P3(x - o.x, y - o.y, z - o.z); 
    }
            P3 operator*(long double k) const
    {
     return P3(x * k, y * k, z * k); 
    }
            P3 operator/(long double k) const
    {
     return P3(x / k, y / k, z / k); 
    }

    }
    ;
        P3 cross(P3 a, P3 b)
    {
            return P3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);

    }
        long double dot(P3 a, P3 b)
    {
     return a.x * b.x + a.y * b.y + a.z * b.z; 
    }
        long double vol6(P3 a, P3 b, P3 c, P3 d)
    {
     return dot(cross(b - a, c - a), d - a); 
    }
        struct Face
    {
            int a = -1, b = -1, c = -1;
            bool dead = false;

    }
    ;
        struct ConvexHull3D
    {
            vector<P3> p;
            vector<Face> f;
            P3 inside;
            void orientFace(Face &x)
    {
                if (vol6(p[x.a], p[x.b], p[x.c], inside) > 0)
                    swap(x.b, x.c);

    }
            bool visible(const Face &x, int i) const
    {
                return vol6(p[x.a], p[x.b], p[x.c], p[i]) > EPS;

    }
            vector<array<int, 3>> build(vector<P3> pts)
    {
                p = pts;
                f.clear();
                int n = (int)p.size();
                if (n < 4)
                    return
    {
    }
    ;
                mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
                shuffle(p.begin(), p.end(), rng);
                int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
                for (int i = 1; i < n; ++i)
    {
                    if (fabsl(p[i].x - p[0].x) > EPS or fabsl(p[i].y - p[0].y) > EPS or fabsl(p[i].z - p[0].z) > EPS)
    {
                        i1 = 0;
                        i2 = i;
                        break;

    }

    }
                if (i1 == -1)
                    return
    {
    }
    ;
                for (int i = 0; i < n; ++i)
    {
                    if (i == i1 or i == i2)
                        continue;
                    P3 v1 = p[i2] - p[i1], v2 = p[i] - p[i1];
                    P3 cr = cross(v1, v2);
                    if (fabsl(cr.x) > EPS or fabsl(cr.y) > EPS or fabsl(cr.z) > EPS)
    {
                        i3 = i;
                        break;

    }

    }
                if (i3 == -1)
                    return
    {
    }
    ;
                for (int i = 0; i < n; ++i)
    {
                    if (i == i1 or i == i2 or i == i3)
                        continue;
                    if (fabsl(vol6(p[i1], p[i2], p[i3], p[i])) > EPS)
    {
                        i4 = i;
                        break;

    }

    }
                if (i4 == -1)
                    return
    {
    }
    ;
                swap(p[1], p[i2]);
                swap(p[2], p[i3]);
                swap(p[3], p[i4]);
                inside = (p[0] + p[1] + p[2] + p[3]) / 4.0L;
                f.push_back(
    {
    0, 1, 2, false
    }
    );
                f.push_back(
    {
    0, 2, 3, false
    }
    );
                f.push_back(
    {
    0, 3, 1, false
    }
    );
                f.push_back(
    {
    1, 3, 2, false
    }
    );
                for (auto &x : f)
                    orientFace(x);
                for (int i = 4; i < n; ++i)
    {
                    vector<int> vis;
                    for (int j = 0; j < (int)f.size(); ++j)
    {
                        if (!f[j].dead and visible(f[j], i))
                            vis.push_back(j);

    }
                    if (vis.empty())
                        continue;
                    map<pair<int, int>, int> edge;
                    auto addEdge = [&](int a, int b)
    {
                        auto it = edge.find(
    {
    b, a
    }
    );
                        if (it != edge.end())
    {
                            if (--it->second == 0)
                                edge.erase(it);

    }
    else
                            edge[
    {
    a, b
    }
    ]++;

    }
    ;
                    for (int id : vis)
    {
                        f[id].dead = true;
                        addEdge(f[id].a, f[id].b);
                        addEdge(f[id].b, f[id].c);
                        addEdge(f[id].c, f[id].a);

    }
                    for (auto [e, cnt] : edge)
    {
                        while (cnt--)
    {
                            Face nf
    {
    e.first, e.second, i, false
    }
    ;
                            orientFace(nf);
                            f.push_back(nf);

    }

    }

    }
                vector<array<int, 3>> ans;
                for (auto &x : f)
                    if (!x.dead)
                        ans.push_back(
    {
    x.a, x.b, x.c
    }
    );
                return ans;

    }

    }
    ;
    }
     // namespace geom_hull3d
}

// Source: https://cp-algorithms.com/data_structures/disjoint_set_union.html#support-the-parity-of-the-path-length--checking-bipartiteness-online

namespace DSU_Bipartite
{
    namespace DSUBipartite
    {
        struct DSU
    {
            int n;
            vector<int> p;
            vector<int> sz;
            vector<int> xr;
            vector<char> ok;
            DSU(int _n = 0)
    {
                init(_n);

    }
            void init(int _n)
    {
                n = _n;
                p.resize(n + 1);
                sz.assign(n + 1, 1);
                xr.assign(n + 1, 0);
                ok.assign(n + 1, 1);
                for (int i = 0; i <= n; ++i)
    {
                    p[i] = i;

    }

    }
            pair<int, int> find(int x)
    {
                if (p[x] == x)
    {
                    return
    {
    x, 0
    }
    ;

    }
                auto got = find(p[x]);
                p[x] = got.first;
                xr[x] ^= got.second;
                return
    {
    p[x], xr[x]
    }
    ;

    }
            void add_edge(int u, int v)
    {
                auto fu = find(u);
                auto fv = find(v);
                int ru = fu.first;
                int rv = fv.first;
                int pu = fu.second;
                int pv = fv.second;
                if (ru == rv)
    {
                    if ((pu ^ pv) != 1)
    {
                        ok[ru] = 0;

    }
                    return;

    }
                if (sz[ru] < sz[rv])
    {
                    swap(ru, rv);
                    swap(pu, pv);

    }
                p[rv] = ru;
                xr[rv] = pu ^ pv ^ 1;
                sz[ru] += sz[rv];
                ok[ru] = (ok[ru] and ok[rv]);

    }
            bool is_bipartite(int x)
    {
                return ok[find(x).first];

    }
            bool same_color(int u, int v)
    {
                auto fu = find(u);
                auto fv = find(v);
                if (fu.first != fv.first)
    {
                    return false;

    }
                return fu.second == fv.second;

    }

    }
    ;
    }
}

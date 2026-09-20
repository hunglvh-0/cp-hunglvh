// Source: https://cp-algorithms.com/data_structures/disjoint_set_union.html

namespace DSU_Standard
{
        namespace DSUStandard
        {
                struct DSU
                {
                        int n;
                        vector<int> p;
                        vector<int> sz;
                        DSU(int _n = 0)
                        {
                                init(_n);
                        }
                        void init(int _n)
                        {
                                n = _n;
                                p.resize(n + 1);
                                sz.assign(n + 1, 1);
                                for (int i = 0; i <= n; ++i)
                                {
                                        p[i] = i;
                                }
                        }
                        int find(int x)
                        {
                                if (p[x] == x)
                                {
                                        return x;
                                }
                                return p[x] = find(p[x]);
                        }
                        bool unite(int a, int b)
                        {
                                a = find(a);
                                b = find(b);
                                if (a == b)
                                {
                                        return false;
                                }
                                if (sz[a] < sz[b])
                                {
                                        swap(a, b);
                                }
                                p[b] = a;
                                sz[a] += sz[b];
                                return true;
                        }
                        bool same(int a, int b)
                        {
                                return find(a) == find(b);
                        }
                        int size(int x)
                        {
                                return sz[find(x)];
                        }
                };
        }
}

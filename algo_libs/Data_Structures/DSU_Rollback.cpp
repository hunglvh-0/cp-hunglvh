// Source: https://cp-algorithms.com/data_structures/deleting_in_log_n.html

namespace DSU_Rollback
{
    namespace DSURollback
    {
        struct DSU
    {
            int n;
            int comps;
            vector<int> p;
            vector<int> sz;
            struct Change
    {
                int b;
                int old_parent_b;
                int a;
                int old_size_a;
                bool merged;

    }
    ;
            vector<Change> st;
            DSU(int _n = 0)
    {
                init(_n);

    }
            void init(int _n)
    {
                n = _n;
                comps = n;
                p.resize(n + 1);
                sz.assign(n + 1, 1);
                for (int i = 0; i <= n; ++i)
    {
                    p[i] = i;

    }
                st.clear();

    }
            int find(int x) const
    {
                while (x != p[x])
    {
                    x = p[x];

    }
                return x;

    }
            bool unite(int x, int y)
    {
                int a = find(x);
                int b = find(y);
                if (a == b)
    {
                    st.push_back(Change
    {
    -1, -1, -1, -1, false
    }
    );
                    return false;

    }
                if (sz[a] < sz[b])
    {
                    swap(a, b);

    }
                st.push_back(Change
    {
    b, p[b], a, sz[a], true
    }
    );
                p[b] = a;
                sz[a] += sz[b];
                --comps;
                return true;

    }
            int snapshot() const
    {
                return (int)st.size();

    }
            void rollback_one()
    {
                if (st.empty())
    {
                    return;

    }
                Change c = st.back();
                st.pop_back();
                if (!c.merged)
    {
                    return;

    }
                p[c.b] = c.old_parent_b;
                sz[c.a] = c.old_size_a;
                ++comps;

    }
            void rollback(int snap)
    {
                while ((int)st.size() > snap)
    {
                    rollback_one();

    }

    }
            bool same(int a, int b) const
    {
                return find(a) == find(b);

    }

    }
    ;
    }
}

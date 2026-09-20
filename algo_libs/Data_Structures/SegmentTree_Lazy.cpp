// Source: https://cp-algorithms.com/data_structures/segment_tree.html#range-updates-lazy-propagation

namespace SegmentTree_Lazy
{
    namespace SegmentTreeLazy
    {
        struct SegTree
    {
            int n;
            vector<long long> st;
            vector<long long> lz;
            SegTree(int _n = 0)
    {
                init(_n);

    }
            void init(int _n)
    {
                n = _n;
                st.assign(4 * max(1, n), 0);
                lz.assign(4 * max(1, n), 0);

    }
            void build(int p, int l, int r, const vector<long long> &a)
    {
                if (l == r)
    {
                    st[p] = a[l];
                    return;

    }
                int m = (l + r) >> 1;
                build(p << 1, l, m, a);
                build(p << 1 | 1, m + 1, r, a);
                st[p] = st[p << 1] + st[p << 1 | 1];

    }
            void build(const vector<long long> &a)
    {
                init((int)a.size() - 1);
                if (n > 0)
    {
                    build(1, 1, n, a);

    }

    }
            void apply(int p, int l, int r, long long v)
    {
                st[p] += 1LL * (r - l + 1) * v;
                lz[p] += v;

    }
            void push(int p, int l, int r)
    {
                if (!lz[p] or l == r)
    {
                    return;

    }
                int m = (l + r) >> 1;
                apply(p << 1, l, m, lz[p]);
                apply(p << 1 | 1, m + 1, r, lz[p]);
                lz[p] = 0;

    }
            void range_add(int p, int l, int r, int ql, int qr, long long v)
    {
                if (qr < l or r < ql)
    {
                    return;

    }
                if (ql <= l and r <= qr)
    {
                    apply(p, l, r, v);
                    return;

    }
                push(p, l, r);
                int m = (l + r) >> 1;
                range_add(p << 1, l, m, ql, qr, v);
                range_add(p << 1 | 1, m + 1, r, ql, qr, v);
                st[p] = st[p << 1] + st[p << 1 | 1];

    }
            long long query(int p, int l, int r, int ql, int qr)
    {
                if (qr < l or r < ql)
    {
                    return 0;

    }
                if (ql <= l and r <= qr)
    {
                    return st[p];

    }
                push(p, l, r);
                int m = (l + r) >> 1;
                return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);

    }
            void range_add(int l, int r, long long v)
    {
                if (l > r)
    {
                    return;

    }
                range_add(1, 1, n, l, r, v);

    }
            long long query(int l, int r)
    {
                if (l > r)
    {
                    return 0;

    }
                return query(1, 1, n, l, r);

    }

    }
    ;
    }
}

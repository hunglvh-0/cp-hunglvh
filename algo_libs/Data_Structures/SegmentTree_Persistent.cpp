// Source: https://cp-algorithms.com/data_structures/segment_tree.html#preserving-the-history-persistent-segment-tree

namespace SegmentTree_Persistent
{
    namespace SegmentTreePersistent
    {
        struct Node
    {
            int l;
            int r;
            long long sum;
            Node(int _l = 0, int _r = 0, long long _sum = 0)
    {
                l = _l;
                r = _r;
                sum = _sum;

    }

    }
    ;
        struct PersistentSegTree
    {
            int n;
            vector<Node> t;
            vector<int> root;
            PersistentSegTree(int _n = 0)
    {
                init(_n);

    }
            void init(int _n)
    {
                n = _n;
                t.clear();
                t.reserve(40 * max(1, n));
                t.push_back(Node());
                root.clear();
                root.push_back(build(1, n));

    }
            int new_node(const Node &x)
    {
                t.push_back(x);
                return (int)t.size() - 1;

    }
            int build(int l, int r)
    {
                int p = new_node(Node(0, 0, 0));
                if (l == r)
    {
                    return p;

    }
                int m = (l + r) >> 1;
                t[p].l = build(l, m);
                t[p].r = build(m + 1, r);
                return p;

    }
            int point_add(int p, int l, int r, int idx, long long val)
    {
                int np = new_node(t[p]);
                if (l == r)
    {
                    t[np].sum += val;
                    return np;

    }
                int m = (l + r) >> 1;
                if (idx <= m)
    {
                    t[np].l = point_add(t[np].l, l, m, idx, val);

    }
    else
    {
                    t[np].r = point_add(t[np].r, m + 1, r, idx, val);

    }
                t[np].sum = t[t[np].l].sum + t[t[np].r].sum;
                return np;

    }
            void apply_point_add_new_version(int idx, long long val)
    {
                root.push_back(point_add(root.back(), 1, n, idx, val));

    }
            long long query(int p, int l, int r, int ql, int qr) const
    {
                if (!p or qr < l or r < ql)
    {
                    return 0;

    }
                if (ql <= l and r <= qr)
    {
                    return t[p].sum;

    }
                int m = (l + r) >> 1;
                return query(t[p].l, l, m, ql, qr) + query(t[p].r, m + 1, r, ql, qr);

    }
            long long query_version(int ver, int l, int r) const
    {
                return query(root[ver], 1, n, l, r);

    }
            int kth_between(int pL, int pR, int l, int r, int k) const
    {
                if (l == r)
    {
                    return l;

    }
                int cntLeft = (int)(t[t[pR].l].sum - t[t[pL].l].sum);
                int m = (l + r) >> 1;
                if (k <= cntLeft)
    {
                    return kth_between(t[pL].l, t[pR].l, l, m, k);

    }
                return kth_between(t[pL].r, t[pR].r, m + 1, r, k - cntLeft);

    }
            int kth_query_versions(int left_ver, int right_ver, int k) const
    {
                return kth_between(root[left_ver], root[right_ver], 1, n, k);

    }

    }
    ;
    }
}

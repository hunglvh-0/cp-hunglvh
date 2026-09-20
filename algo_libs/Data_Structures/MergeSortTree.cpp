// Source: https://cp-algorithms.com/data_structures/segment_tree.html#saving-the-entire-subarrays-in-each-vertex

namespace MergeSortTree
{
    namespace MergeSortTreeDS
    {
        struct MergeSortTree
    {
            int n;
            vector<vector<int>> st;
            MergeSortTree(int _n = 0)
    {
                init(_n);

    }
            void init(int _n)
    {
                n = _n;
                st.assign(4 * max(1, n),
    {
    }
    );

    }
            void build(int p, int l, int r, const vector<int> &a)
    {
                if (l == r)
    {
                    st[p] =
    {
    a[l]
    }
    ;
                    return;

    }
                int m = (l + r) >> 1;
                build(p << 1, l, m, a);
                build(p << 1 | 1, m + 1, r, a);
                st[p].resize((int)st[p << 1].size() + (int)st[p << 1 | 1].size());
                merge(st[p << 1].begin(), st[p << 1].end(), st[p << 1 | 1].begin(), st[p << 1 | 1].end(), st[p].begin());

    }
            void build(const vector<int> &a)
    {
                init((int)a.size() - 1);
                if (n > 0)
    {
                    build(1, 1, n, a);

    }

    }
            int count_leq(int p, int l, int r, int ql, int qr, int x) const
    {
                if (qr < l or r < ql)
    {
                    return 0;

    }
                if (ql <= l and r <= qr)
    {
                    return (int)(upper_bound(st[p].begin(), st[p].end(), x) - st[p].begin());

    }
                int m = (l + r) >> 1;
                return count_leq(p << 1, l, m, ql, qr, x) + count_leq(p << 1 | 1, m + 1, r, ql, qr, x);

    }
            int count_lt(int p, int l, int r, int ql, int qr, int x) const
    {
                if (qr < l or r < ql)
    {
                    return 0;

    }
                if (ql <= l and r <= qr)
    {
                    return (int)(lower_bound(st[p].begin(), st[p].end(), x) - st[p].begin());

    }
                int m = (l + r) >> 1;
                return count_lt(p << 1, l, m, ql, qr, x) + count_lt(p << 1 | 1, m + 1, r, ql, qr, x);

    }
            int count_between(int l, int r, int lo, int hi) const
    {
                if (l > r or lo > hi)
    {
                    return 0;

    }
                return count_leq(1, 1, n, l, r, hi) - count_lt(1, 1, n, l, r, lo);

    }

    }
    ;
    }
}

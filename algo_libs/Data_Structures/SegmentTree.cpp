// Source: https://cp-algorithms.com/data_structures/segment_tree.html

namespace SegmentTree
{
        namespace SegmentTreeStandard
        {
                struct SegTree
                {
                        int n;
                        vector<long long> st;
                        SegTree(int _n = 0)
                        {
                                init(_n);
                        }
                        void init(int _n)
                        {
                                n = _n;
                                st.assign(4 * max(1, n), 0);
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
                        void point_set(int p, int l, int r, int i, long long v)
                        {
                                if (l == r)
                                {
                                        st[p] = v;
                                        return;
                                }
                                int m = (l + r) >> 1;
                                if (i <= m)
                                {
                                        point_set(p << 1, l, m, i, v);
                                }
                                else
                                {
                                        point_set(p << 1 | 1, m + 1, r, i, v);
                                }
                                st[p] = st[p << 1] + st[p << 1 | 1];
                        }
                        void point_add(int p, int l, int r, int i, long long v)
                        {
                                if (l == r)
                                {
                                        st[p] += v;
                                        return;
                                }
                                int m = (l + r) >> 1;
                                if (i <= m)
                                {
                                        point_add(p << 1, l, m, i, v);
                                }
                                else
                                {
                                        point_add(p << 1 | 1, m + 1, r, i, v);
                                }
                                st[p] = st[p << 1] + st[p << 1 | 1];
                        }
                        long long query(int p, int l, int r, int ql, int qr) const
                        {
                                if (qr < l or r < ql)
                                {
                                        return 0;
                                }
                                if (ql <= l and r <= qr)
                                {
                                        return st[p];
                                }
                                int m = (l + r) >> 1;
                                return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);
                        }
                        void point_set(int i, long long v)
                        {
                                point_set(1, 1, n, i, v);
                        }
                        void point_add(int i, long long v)
                        {
                                point_add(1, 1, n, i, v);
                        }
                        long long query(int l, int r) const
                        {
                                if (l > r)
                                {
                                        return 0;
                                }
                                return query(1, 1, n, l, r);
                        }
                };
        }
}

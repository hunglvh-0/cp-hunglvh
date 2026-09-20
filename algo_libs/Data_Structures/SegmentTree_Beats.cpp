// Source: https://codeforces.com/blog/entry/57319

namespace SegmentTree_Beats
{
        namespace SegmentTreeBeatsDS
        {
                const long long INF64 = (long long)4e18;
                struct Node
                {
                        long long sum;
                        long long mx1, mx2;
                        int mxc;
                        long long mn1, mn2;
                        int mnc;
                        long long add;
                };
                struct SegTreeBeats
                {
                        int n;
                        vector<Node> st;
                        SegTreeBeats(int _n = 0)
                        {
                                init(_n);
                        }
                        Node make_node(long long v)
                        {
                                Node x;
                                x.sum = v;
                                x.mx1 = x.mn1 = v;
                                x.mx2 = -INF64;
                                x.mn2 = INF64;
                                x.mxc = x.mnc = 1;
                                x.add = 0;
                                return x;
                        }
                        void init(int _n)
                        {
                                n = _n;
                                st.assign(4 * max(1, n), make_node(0));
                        }
                        void merge(int p)
                        {
                                Node &a = st[p << 1];
                                Node &b = st[p << 1 | 1];
                                Node &c = st[p];
                                c.sum = a.sum + b.sum;
                                if (a.mx1 > b.mx1)
                                {
                                        c.mx1 = a.mx1;
                                        c.mxc = a.mxc;
                                        c.mx2 = max(a.mx2, b.mx1);
                                }
                                else if (a.mx1 < b.mx1)
                                {
                                        c.mx1 = b.mx1;
                                        c.mxc = b.mxc;
                                        c.mx2 = max(a.mx1, b.mx2);
                                }
                                else
                                {
                                        c.mx1 = a.mx1;
                                        c.mxc = a.mxc + b.mxc;
                                        c.mx2 = max(a.mx2, b.mx2);
                                }
                                if (a.mn1 < b.mn1)
                                {
                                        c.mn1 = a.mn1;
                                        c.mnc = a.mnc;
                                        c.mn2 = min(a.mn2, b.mn1);
                                }
                                else if (a.mn1 > b.mn1)
                                {
                                        c.mn1 = b.mn1;
                                        c.mnc = b.mnc;
                                        c.mn2 = min(a.mn1, b.mn2);
                                }
                                else
                                {
                                        c.mn1 = a.mn1;
                                        c.mnc = a.mnc + b.mnc;
                                        c.mn2 = min(a.mn2, b.mn2);
                                }
                                c.add = 0;
                        }
                        void apply_add(int p, int l, int r, long long v)
                        {
                                Node &x = st[p];
                                x.sum += 1LL * (r - l + 1) * v;
                                x.mx1 += v;
                                if (x.mx2 > -INF64 / 2)
                                {
                                        x.mx2 += v;
                                }
                                x.mn1 += v;
                                if (x.mn2 < INF64 / 2)
                                {
                                        x.mn2 += v;
                                }
                                x.add += v;
                        }
                        void apply_chmin(int p, long long v)
                        {
                                Node &x = st[p];
                                if (x.mx1 <= v)
                                {
                                        return;
                                }
                                x.sum += (v - x.mx1) * x.mxc;
                                if (x.mn1 == x.mx1)
                                {
                                        x.mn1 = v;
                                }
                                else if (x.mn2 == x.mx1)
                                {
                                        x.mn2 = v;
                                }
                                x.mx1 = v;
                        }
                        void apply_chmax(int p, long long v)
                        {
                                Node &x = st[p];
                                if (x.mn1 >= v)
                                {
                                        return;
                                }
                                x.sum += (v - x.mn1) * x.mnc;
                                if (x.mx1 == x.mn1)
                                {
                                        x.mx1 = v;
                                }
                                else if (x.mx2 == x.mn1)
                                {
                                        x.mx2 = v;
                                }
                                x.mn1 = v;
                        }
                        void push(int p, int l, int r)
                        {
                                if (l == r)
                                {
                                        st[p].add = 0;
                                        return;
                                }
                                int lc = p << 1;
                                int rc = p << 1 | 1;
                                if (st[p].add)
                                {
                                        int m = (l + r) >> 1;
                                        apply_add(lc, l, m, st[p].add);
                                        apply_add(rc, m + 1, r, st[p].add);
                                        st[p].add = 0;
                                }
                                if (st[lc].mx1 > st[p].mx1)
                                {
                                        apply_chmin(lc, st[p].mx1);
                                }
                                if (st[rc].mx1 > st[p].mx1)
                                {
                                        apply_chmin(rc, st[p].mx1);
                                }
                                if (st[lc].mn1 < st[p].mn1)
                                {
                                        apply_chmax(lc, st[p].mn1);
                                }
                                if (st[rc].mn1 < st[p].mn1)
                                {
                                        apply_chmax(rc, st[p].mn1);
                                }
                        }
                        void build(int p, int l, int r, const vector<long long> &a)
                        {
                                if (l == r)
                                {
                                        st[p] = make_node(a[l]);
                                        return;
                                }
                                int m = (l + r) >> 1;
                                build(p << 1, l, m, a);
                                build(p << 1 | 1, m + 1, r, a);
                                merge(p);
                        }
                        void build(const vector<long long> &a)
                        {
                                init((int)a.size() - 1);
                                if (n > 0)
                                {
                                        build(1, 1, n, a);
                                }
                        }
                        void range_add(int p, int l, int r, int ql, int qr, long long v)
                        {
                                if (qr < l or r < ql)
                                {
                                        return;
                                }
                                if (ql <= l and r <= qr)
                                {
                                        apply_add(p, l, r, v);
                                        return;
                                }
                                push(p, l, r);
                                int m = (l + r) >> 1;
                                range_add(p << 1, l, m, ql, qr, v);
                                range_add(p << 1 | 1, m + 1, r, ql, qr, v);
                                merge(p);
                        }
                        void range_chmin(int p, int l, int r, int ql, int qr, long long v)
                        {
                                if (qr < l or r < ql or st[p].mx1 <= v)
                                {
                                        return;
                                }
                                if (ql <= l and r <= qr and st[p].mx2 < v)
                                {
                                        apply_chmin(p, v);
                                        return;
                                }
                                push(p, l, r);
                                int m = (l + r) >> 1;
                                range_chmin(p << 1, l, m, ql, qr, v);
                                range_chmin(p << 1 | 1, m + 1, r, ql, qr, v);
                                merge(p);
                        }
                        void range_chmax(int p, int l, int r, int ql, int qr, long long v)
                        {
                                if (qr < l or r < ql or st[p].mn1 >= v)
                                {
                                        return;
                                }
                                if (ql <= l and r <= qr and st[p].mn2 > v)
                                {
                                        apply_chmax(p, v);
                                        return;
                                }
                                push(p, l, r);
                                int m = (l + r) >> 1;
                                range_chmax(p << 1, l, m, ql, qr, v);
                                range_chmax(p << 1 | 1, m + 1, r, ql, qr, v);
                                merge(p);
                        }
                        long long query_sum(int p, int l, int r, int ql, int qr)
                        {
                                if (qr < l or r < ql)
                                {
                                        return 0;
                                }
                                if (ql <= l and r <= qr)
                                {
                                        return st[p].sum;
                                }
                                push(p, l, r);
                                int m = (l + r) >> 1;
                                return query_sum(p << 1, l, m, ql, qr) + query_sum(p << 1 | 1, m + 1, r, ql, qr);
                        }
                        long long query_min(int p, int l, int r, int ql, int qr)
                        {
                                if (qr < l or r < ql)
                                {
                                        return INF64;
                                }
                                if (ql <= l and r <= qr)
                                {
                                        return st[p].mn1;
                                }
                                push(p, l, r);
                                int m = (l + r) >> 1;
                                return min(query_min(p << 1, l, m, ql, qr), query_min(p << 1 | 1, m + 1, r, ql, qr));
                        }
                        long long query_max(int p, int l, int r, int ql, int qr)
                        {
                                if (qr < l or r < ql)
                                {
                                        return -INF64;
                                }
                                if (ql <= l and r <= qr)
                                {
                                        return st[p].mx1;
                                }
                                push(p, l, r);
                                int m = (l + r) >> 1;
                                return max(query_max(p << 1, l, m, ql, qr), query_max(p << 1 | 1, m + 1, r, ql, qr));
                        }
                        void range_add(int l, int r, long long v)
                        {
                                if (l <= r)
                                {
                                        range_add(1, 1, n, l, r, v);
                                }
                        }
                        void range_chmin(int l, int r, long long v)
                        {
                                if (l <= r)
                                {
                                        range_chmin(1, 1, n, l, r, v);
                                }
                        }
                        void range_chmax(int l, int r, long long v)
                        {
                                if (l <= r)
                                {
                                        range_chmax(1, 1, n, l, r, v);
                                }
                        }
                        long long query_sum(int l, int r)
                        {
                                if (l > r)
                                {
                                        return 0;
                                }
                                return query_sum(1, 1, n, l, r);
                        }
                        long long query_min(int l, int r)
                        {
                                if (l > r)
                                {
                                        return INF64;
                                }
                                return query_min(1, 1, n, l, r);
                        }
                        long long query_max(int l, int r)
                        {
                                if (l > r)
                                {
                                        return -INF64;
                                }
                                return query_max(1, 1, n, l, r);
                        }
                };
        }
}

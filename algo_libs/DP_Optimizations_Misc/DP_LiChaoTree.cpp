// Source: https://cp-algorithms.com/geometry/convex_hull_trick.html

namespace DP_LiChaoTree
{
        namespace DPLiChaoTree
        {
                const long long INF64 = (long long)4e18;
                struct Line
                {
                        long long m;
                        long long b;
                        Line(long long _m = 0, long long _b = INF64)
                        {
                                m = _m;
                                b = _b;
                        }
                        long long f(long long x) const
                        {
                                return (long long)((__int128)m * x + b);
                        }
                };
                struct Node
                {
                        Line ln;
                        Node *l;
                        Node *r;
                        Node()
                        {
                                ln = Line();
                                l = nullptr;
                                r = nullptr;
                        }
                };
                struct LiChaoMin
                {
                        long long X_L;
                        long long X_R;
                        Node *root;
                        LiChaoMin(long long xl, long long xr)
                        {
                                X_L = xl;
                                X_R = xr;
                                root = new Node();
                        }
                        void add_line(Line nw)
                        {
                                add_line(root, X_L, X_R, nw);
                        }
                        long long query(long long x) const
                        {
                                return query(root, X_L, X_R, x);
                        }
                        void add_segment(Line nw, long long ql, long long qr)
                        {
                                if (ql > qr)
                                {
                                        return;
                                }
                                add_segment(root, X_L, X_R, ql, qr, nw);
                        }
                        void add_line(Node *nd, long long l, long long r, Line nw)
                        {
                                long long mid = (l + r) >> 1;
                                bool lef = nw.f(l) < nd->ln.f(l);
                                bool cen = nw.f(mid) < nd->ln.f(mid);
                                if (cen)
                                {
                                        swap(nd->ln, nw);
                                }
                                if (l == r)
                                {
                                        return;
                                }
                                if (lef != cen)
                                {
                                        if (!nd->l)
                                        {
                                                nd->l = new Node();
                                        }
                                        add_line(nd->l, l, mid, nw);
                                }
                                else
                                {
                                        if (!nd->r)
                                        {
                                                nd->r = new Node();
                                        }
                                        add_line(nd->r, mid + 1, r, nw);
                                }
                        }
                        long long query(Node *nd, long long l, long long r, long long x) const
                        {
                                if (!nd)
                                {
                                        return INF64;
                                }
                                long long ans = nd->ln.f(x);
                                if (l == r)
                                {
                                        return ans;
                                }
                                long long mid = (l + r) >> 1;
                                if (x <= mid)
                                {
                                        return min(ans, query(nd->l, l, mid, x));
                                }
                                return min(ans, query(nd->r, mid + 1, r, x));
                        }
                        void add_segment(Node *nd, long long l, long long r, long long ql, long long qr, Line nw)
                        {
                                if (!nd or qr < l or r < ql)
                                {
                                        return;
                                }
                                if (ql <= l and r <= qr)
                                {
                                        add_line(nd, l, r, nw);
                                        return;
                                }
                                long long mid = (l + r) >> 1;
                                if (!nd->l)
                                {
                                        nd->l = new Node();
                                }
                                if (!nd->r)
                                {
                                        nd->r = new Node();
                                }
                                add_segment(nd->l, l, mid, ql, qr, nw);
                                add_segment(nd->r, mid + 1, r, ql, qr, nw);
                        }
                };
        }
}

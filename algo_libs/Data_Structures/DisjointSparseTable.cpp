// Source: https://codeforces.com/blog/entry/78931

namespace DisjointSparseTable
{
        namespace DisjointSparseTableDS
        {
                template <class T>
                struct DisjointSparseTable
                {
                        int n;
                        int lg;
                        vector<vector<T>> st;
                        function<T(const T &, const T &)> op;
                        DisjointSparseTable()
                        {
                                n = 0;
                                lg = 0;
                        }
                        DisjointSparseTable(const vector<T> &a, function<T(const T &, const T &)> _op)
                        {
                                build(a, _op);
                        }
                        void build(const vector<T> &a, function<T(const T &, const T &)> _op)
                        {
                                op = _op;
                                n = (int)a.size();
                                if (!n)
                                {
                                        lg = 0;
                                        st.clear();
                                        return;
                                }
                                lg = 32 - __builtin_clz(n);
                                st.assign(lg, vector<T>(n));
                                st[0] = a;
                                for (int k = 1; k < lg; ++k)
                                {
                                        int len = 1 << k;
                                        for (int b = 0; b < n; b += (len << 1))
                                        {
                                                int mid = min(b + len, n);
                                                int r = min(b + (len << 1), n);
                                                if (mid == b)
                                                {
                                                        continue;
                                                }
                                                st[k][mid - 1] = a[mid - 1];
                                                for (int i = mid - 2; i >= b; --i)
                                                {
                                                        st[k][i] = op(a[i], st[k][i + 1]);
                                                }
                                                if (mid < r)
                                                {
                                                        st[k][mid] = a[mid];
                                                        for (int i = mid + 1; i < r; ++i)
                                                        {
                                                                st[k][i] = op(st[k][i - 1], a[i]);
                                                        }
                                                }
                                        }
                                }
                        }
                        T query(int l, int r) const
                        {
                                if (l == r)
                                {
                                        return st[0][l];
                                }
                                int k = 31 - __builtin_clz(l ^ r);
                                return op(st[k + 1][l], st[k + 1][r]);
                        }
                };
        }
}

// Source: https://cp-algorithms.com/data_structures/sparse-table.html

namespace SparseTable
{
        namespace SparseTableDS
        {
                template <class T>
                struct SparseTable
                {
                        int n;
                        int lg;
                        vector<int> lg2;
                        vector<vector<T>> st;
                        function<T(const T &, const T &)> op;
                        SparseTable()
                        {
                                n = 0;
                                lg = 0;
                        }
                        SparseTable(const vector<T> &a, function<T(const T &, const T &)> _op)
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
                                        lg2.clear();
                                        st.clear();
                                        return;
                                }
                                lg2.assign(n + 1, 0);
                                for (int i = 2; i <= n; ++i)
                                {
                                        lg2[i] = lg2[i >> 1] + 1;
                                }
                                lg = lg2[n] + 1;
                                st.assign(lg, vector<T>(n));
                                for (int i = 0; i < n; ++i)
                                {
                                        st[0][i] = a[i];
                                }
                                for (int k = 1; k < lg; ++k)
                                {
                                        int len = 1 << k;
                                        for (int i = 0; i + len <= n; ++i)
                                        {
                                                st[k][i] = op(st[k - 1][i], st[k - 1][i + (len >> 1)]);
                                        }
                                }
                        }
                        T query(int l, int r) const
                        {
                                int k = lg2[r - l + 1];
                                return op(st[k][l], st[k][r - (1 << k) + 1]);
                        }
                };
                template <class T>
                SparseTable<T> make_min_sparse_table(const vector<T> &a)
                {
                        return SparseTable<T>(a, [](const T &x, const T &y)

                                              { return min(x, y); });
                }
        }
}

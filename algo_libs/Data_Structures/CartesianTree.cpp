// Source: https://cp-algorithms.com/graph/rmq_linear.html

namespace CartesianTree
{
        namespace CartesianTreeDS
        {
                struct Cartesian
                {
                        int n;
                        vector<int> parent;
                        vector<int> left;
                        vector<int> right;
                        int root;
                        Cartesian()
                        {
                                n = 0;
                                root = -1;
                        }
                };
                Cartesian build_min(const vector<long long> &a)
                {
                        int n = (int)a.size();
                        Cartesian t;
                        t.n = n;
                        t.parent.assign(n, -1);
                        t.left.assign(n, -1);
                        t.right.assign(n, -1);
                        vector<int> st;
                        st.reserve(n);
                        for (int i = 0; i < n; ++i)
                        {
                                int last = -1;
                                while (!st.empty() and a[st.back()] > a[i])
                                {
                                        last = st.back();
                                        st.pop_back();
                                }
                                if (!st.empty())
                                {
                                        t.parent[i] = st.back();
                                        t.right[st.back()] = i;
                                }
                                if (last != -1)
                                {
                                        t.parent[last] = i;
                                        t.left[i] = last;
                                }
                                st.push_back(i);
                        }
                        while ((int)st.size() > 1)
                        {
                                st.pop_back();
                        }
                        t.root = (st.empty() ? -1 : st.back());
                        return t;
                }
                Cartesian build_max(const vector<long long> &a)
                {
                        int n = (int)a.size();
                        Cartesian t;
                        t.n = n;
                        t.parent.assign(n, -1);
                        t.left.assign(n, -1);
                        t.right.assign(n, -1);
                        vector<int> st;
                        st.reserve(n);
                        for (int i = 0; i < n; ++i)
                        {
                                int last = -1;
                                while (!st.empty() and a[st.back()] < a[i])
                                {
                                        last = st.back();
                                        st.pop_back();
                                }
                                if (!st.empty())
                                {
                                        t.parent[i] = st.back();
                                        t.right[st.back()] = i;
                                }
                                if (last != -1)
                                {
                                        t.parent[last] = i;
                                        t.left[i] = last;
                                }
                                st.push_back(i);
                        }
                        while ((int)st.size() > 1)
                        {
                                st.pop_back();
                        }
                        t.root = (st.empty() ? -1 : st.back());
                        return t;
                }
        }
}

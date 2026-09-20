// Source: Local/Reconstructed

namespace HeavyLightDecomposition
{
    struct SegTreeLazy
    {
        int n;
        vector<long long> st, lz;
        void init(int n_)
        {
            n = 1;
            while (n < n_)
                n <<= 1;
            st.assign(2 * n, 0);
            lz.assign(2 * n, 0);
        }
        void apply(int p, int len, long long v)
        {
            st[p] += v * len;
            lz[p] += v;
        }
        void push(int p, int len)
        {
            if (lz[p] == 0 or p >= n)
                return;
            apply(p << 1, len >> 1, lz[p]);
            apply(p << 1 | 1, len >> 1, lz[p]);
            lz[p] = 0;
        }
        void rangeAdd(int l, int r, long long v, int p, int tl, int tr)
        {
            if (r <= tl or tr <= l)
                return;
            if (l <= tl and tr <= r)
            {
                apply(p, tr - tl, v);
                return;
            }
            push(p, tr - tl);
            int tm = (tl + tr) >> 1;
            rangeAdd(l, r, v, p << 1, tl, tm);
            rangeAdd(l, r, v, p << 1 | 1, tm, tr);
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
        long long rangeSum(int l, int r, int p, int tl, int tr)
        {
            if (r <= tl or tr <= l)
                return 0;
            if (l <= tl and tr <= r)
                return st[p];
            push(p, tr - tl);
            int tm = (tl + tr) >> 1;
            return rangeSum(l, r, p << 1, tl, tm) + rangeSum(l, r, p << 1 | 1, tm, tr);
        }
        void rangeAdd(int l, int r, long long v)
        {
            rangeAdd(l, r, v, 1, 0, n);
        }
        long long rangeSum(int l, int r)
        {
            return rangeSum(l, r, 1, 0, n);
        }
    };
    struct HeavyLightDecomposition
    {
        int n, curPos;
        vector<vector<int>> g;
        vector<int> parent, depth, heavy, head, pos, sz;
        SegTreeLazy seg;
        HeavyLightDecomposition(int n_ = 0)
        {
            init(n_);
        }
        void init(int n_)
        {
            n = n_;
            curPos = 0;
            g.assign(n + 1,
                     {});
            parent.assign(n + 1, 0);
            depth.assign(n + 1, 0);
            heavy.assign(n + 1, -1);
            head.assign(n + 1, 0);
            pos.assign(n + 1, 0);
            sz.assign(n + 1, 0);
        }
        void addEdge(int u, int v)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int dfs(int v, int p)
        {
            parent[v] = p;
            sz[v] = 1;
            int bestSize = 0;
            for (int to : g[v])
            {
                if (to == p)
                    continue;
                depth[to] = depth[v] + 1;
                int sub = dfs(to, v);
                sz[v] += sub;
                if (sub > bestSize)
                {
                    bestSize = sub;
                    heavy[v] = to;
                }
            }
            return sz[v];
        }
        void decompose(int v, int h)
        {
            head[v] = h;
            pos[v] = curPos++;
            if (heavy[v] != -1)
                decompose(heavy[v], h);
            for (int to : g[v])
            {
                if (to == parent[v] or to == heavy[v])
                    continue;
                decompose(to, to);
            }
        }
        void build(int root = 1, const vector<long long> &val =
                                     {})

        {
            curPos = 0;
            depth[root] = 0;
            dfs(root, 0);
            decompose(root, root);
            seg.init(n);
            if (!val.empty())
            {
                for (int v = 1; v <= n; ++v)
                {
                    seg.rangeAdd(pos[v], pos[v] + 1, val[v]);
                }
            }
        }
        void pathAdd(int a, int b, long long delta)
        {
            while (head[a] != head[b])
            {
                if (depth[head[a]] < depth[head[b]])
                    swap(a, b);
                seg.rangeAdd(pos[head[a]], pos[a] + 1, delta);
                a = parent[head[a]];
            }
            if (depth[a] > depth[b])
                swap(a, b);
            seg.rangeAdd(pos[a], pos[b] + 1, delta);
        }
        long long pathQuery(int a, int b)
        {
            long long ans = 0;
            while (head[a] != head[b])
            {
                if (depth[head[a]] < depth[head[b]])
                    swap(a, b);
                ans += seg.rangeSum(pos[head[a]], pos[a] + 1);
                a = parent[head[a]];
            }
            if (depth[a] > depth[b])
                swap(a, b);
            ans += seg.rangeSum(pos[a], pos[b] + 1);
            return ans;
        }
        void subtreeAdd(int v, long long delta)
        {
            seg.rangeAdd(pos[v], pos[v] + sz[v], delta);
        }
        long long subtreeQuery(int v)
        {
            return seg.rangeSum(pos[v], pos[v] + sz[v]);
        }
    };
}

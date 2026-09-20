// Source: Local/Reconstructed

namespace EulerTourTree
{
    struct Fenwick
    {
        int n;
        vector<long long> bit;
        void init(int n_)
        {
            n = n_;
            bit.assign(n + 1, 0);
        }
        void add(int idx, long long val)
        {
            for (++idx; idx <= n; idx += idx & -idx)
                bit[idx] += val;
        }
        long long sumPrefix(int idx) const
        {
            long long s = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                s += bit[idx];
            return s;
        }
        long long sumRange(int l, int r) const
        {
            if (l >= r)
                return 0;
            return sumPrefix(r - 1) - (l ? sumPrefix(l - 1) : 0);
        }
    };
    struct EulerTourTree
    {
        int n, lg, timer;
        vector<vector<int>> g;
        vector<vector<int>> up;
        vector<int> tin, tout, depth;
        vector<long long> val;
        Fenwick fw;
        EulerTourTree(int n_ = 0)
        {
            init(n_);
        }
        void init(int n_)
        {
            n = n_;
            lg = 1;
            while ((1 << lg) <= n)
                ++lg;
            timer = 0;
            g.assign(n + 1,
                     {});
            up.assign(lg, vector<int>(n + 1, 1));
            tin.assign(n + 1, 0);
            tout.assign(n + 1, 0);
            depth.assign(n + 1, 0);
            val.assign(n + 1, 0);
        }
        void addEdge(int u, int v)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        void dfs(int v, int p)
        {
            tin[v] = timer++;
            up[0][v] = p;
            for (int i = 1; i < lg; ++i)
                up[i][v] = up[i - 1][up[i - 1][v]];
            for (int to : g[v])
            {
                if (to == p)
                    continue;
                depth[to] = depth[v] + 1;
                dfs(to, v);
            }
            tout[v] = timer - 1;
        }
        void build(int root = 1, const vector<long long> &initVal =
                                     {})

        {
            timer = 0;
            depth[root] = 0;
            dfs(root, root);
            fw.init(n);
            if (!initVal.empty())
            {
                for (int v = 1; v <= n; ++v)
                {
                    val[v] = initVal[v];
                    fw.add(tin[v], val[v]);
                }
            }
        }
        bool isAncestor(int u, int v) const
        {
            return tin[u] <= tin[v] and tout[v] <= tout[u];
        }
        int lca(int u, int v) const
        {
            if (isAncestor(u, v))
                return u;
            if (isAncestor(v, u))
                return v;
            for (int i = lg - 1; i >= 0; --i)
            {
                int x = up[i][u];
                if (!isAncestor(x, v))
                    u = x;
            }
            return up[0][u];
        }
        int dist(int u, int v) const
        {
            int w = lca(u, v);
            return depth[u] + depth[v] - 2 * depth[w];
        }
        void addNode(int v, long long delta)
        {
            val[v] += delta;
            fw.add(tin[v], delta);
        }
        long long subtreeSum(int v) const
        {
            return fw.sumRange(tin[v], tout[v] + 1);
        }
    };
}

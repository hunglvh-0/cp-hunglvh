// Source: Local/Reconstructed

namespace Mo_On_Tree
{
    template <class Ans = long long>
    struct MoOnTree
    {
        struct Query
        {
            int l, r, idx, lca;
        };
        int n, lg, timer;
        vector<vector<int>> g, up;
        vector<int> st, en, euler, depth;
        vector<Query> qs;
        vector<char> vis;
        MoOnTree(int n_ = 0)
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
            st.assign(n + 1, 0);
            en.assign(n + 1, 0);
            euler.assign(2 * n, 0);
            depth.assign(n + 1, 0);
            qs.clear();
        }
        void addEdge(int u, int v)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        void dfs(int v, int p)
        {
            up[0][v] = p;
            for (int i = 1; i < lg; ++i)
                up[i][v] = up[i - 1][up[i - 1][v]];
            st[v] = timer;
            euler[timer++] = v;
            for (int to : g[v])
            {
                if (to == p)
                    continue;
                depth[to] = depth[v] + 1;
                dfs(to, v);
            }
            en[v] = timer;
            euler[timer++] = v;
        }
        void build(int root = 1)
        {
            timer = 0;
            depth[root] = 0;
            dfs(root, root);
        }
        bool isAncestor(int u, int v) const
        {
            return st[u] <= st[v] and en[v] <= en[u];
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
        void addQuery(int u, int v)
        {
            if (st[u] > st[v])
                swap(u, v);
            int w = lca(u, v);
            if (w == u)
                qs.push_back(
                    {st[u], st[v], (int)qs.size(), 0});
            else
                qs.push_back(
                    {en[u], st[v], (int)qs.size(), w});
        }
        template <class AddNode, class RemoveNode, class Get>
        vector<Ans> process(AddNode addNode, RemoveNode removeNode, Get getAnswer)
        {
            int q = (int)qs.size();
            int B = max(1, (int)pow(max(1, 2 * n), 2.0 / 3.0));
            vector<Query> ord = qs;
            sort(ord.begin(), ord.end(), [&](const Query &a, const Query &b)
                 {
    			int ab = a.l / B, bb = b.l / B;
    			if (ab != bb) return ab < bb;
    			int ar = a.r / B, br = b.r / B;
    			if (ar != br) return ar < br;
    			return a.r < b.r; });
            vis.assign(n + 1, 0);
            vector<Ans> ans(q);
            auto toggle = [&](int p)
            {
                int x = euler[p];
                if (vis[x])
                    removeNode(x);
                else
                    addNode(x);
                vis[x] ^= 1;
            };
            int L = 0, R = -1;
            for (auto qu : ord)
            {
                while (L > qu.l)
                    toggle(--L);
                while (R < qu.r)
                    toggle(++R);
                while (L < qu.l)
                    toggle(L++);
                while (R > qu.r)
                    toggle(R--);
                if (qu.lca)
                    addNode(qu.lca);
                ans[qu.idx] = getAnswer();
                if (qu.lca)
                    removeNode(qu.lca);
            }
            return ans;
        }
    };
}

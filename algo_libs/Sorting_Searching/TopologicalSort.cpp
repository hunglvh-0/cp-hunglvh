// Source: https://en.oi-wiki.org/graph/topo/

namespace TopologicalSort
{
        namespace TopologicalSort
        {
                vector<int> kahn(int n, const vector<vector<int>> &g)
                {
                        vector<int> in(n, 0);
                        for (int u = 0; u < n; u++)
                        {
                                for (int v : g[u])
                                {
                                        in[v]++;
                                }
                        }
                        queue<int> q;
                        for (int i = 0; i < n; i++)
                        {
                                if (in[i] == 0)
                                {
                                        q.push(i);
                                }
                        }
                        vector<int> o;
                        o.reserve(n);
                        while (!q.empty())
                        {
                                int u = q.front();
                                q.pop();
                                o.push_back(u);
                                for (int v : g[u])
                                {
                                        in[v]--;
                                        if (in[v] == 0)
                                        {
                                                q.push(v);
                                        }
                                }
                        }
                        if ((int)o.size() != n)
                        {
                                return vector<int>();
                        }
                        return o;
                }
                bool dfs(int u, const vector<vector<int>> &g, vector<int> &st, vector<int> &o)
                {
                        st[u] = 1;
                        for (int v : g[u])
                        {
                                if (st[v] == 1)
                                {
                                        return false;
                                }
                                if (st[v] == 0)
                                {
                                        if (!dfs(v, g, st, o))
                                        {
                                                return false;
                                        }
                                }
                        }
                        st[u] = 2;
                        o.push_back(u);
                        return true;
                }
                vector<int> dfs_ts(int n, const vector<vector<int>> &g)
                {
                        vector<int> st(n, 0);
                        vector<int> o;
                        o.reserve(n);
                        for (int i = 0; i < n; i++)
                        {
                                if (st[i] == 0)
                                {
                                        if (!dfs(i, g, st, o))
                                        {
                                                return vector<int>();
                                        }
                                }
                        }
                        reverse(o.begin(), o.end());
                        return o;
                }
        }
}

// Source: https://cp-algorithms.com/graph/pruefer_code.html

namespace Prufer_Code
{
        namespace PruferCode
        {
                long long pw_mod(long long a, long long e, long long mod)
                {
                        long long r = 1 % mod;
                        a %= mod;
                        while (e)
                        {
                                if (e & 1)
                                {
                                        r = (long long)((__int128)r * a % mod);
                                }
                                a = (long long)((__int128)a * a % mod);
                                e >>= 1;
                        }
                        return r;
                }
                vector<int> encode(const vector<vector<int>> &g)
                {
                        int n = (int)g.size();
                        if (n <= 2)
                        {
                                return {};
                        }
                        vector<int> deg(n, 0);
                        set<int> leaves;
                        for (int i = 0; i < n; ++i)
                        {
                                deg[i] = (int)g[i].size();
                                if (deg[i] == 1)
                                {
                                        leaves.insert(i);
                                }
                        }
                        vector<int> code;
                        code.reserve(n - 2);
                        for (int it = 0; it < n - 2; ++it)
                        {
                                int leaf = *leaves.begin();
                                leaves.erase(leaves.begin());
                                int par = -1;
                                for (int v : g[leaf])
                                {
                                        if (deg[v])
                                        {
                                                par = v;
                                                break;
                                        }
                                }
                                code.push_back(par);
                                deg[leaf] = 0;
                                --deg[par];
                                if (deg[par] == 1)
                                {
                                        leaves.insert(par);
                                }
                        }
                        return code;
                }
                vector<pair<int, int>> decode(const vector<int> &code)
                {
                        int n = (int)code.size() + 2;
                        vector<int> deg(n, 1);
                        for (int x : code)
                        {
                                ++deg[x];
                        }
                        set<int> leaves;
                        for (int i = 0; i < n; ++i)
                        {
                                if (deg[i] == 1)
                                {
                                        leaves.insert(i);
                                }
                        }
                        vector<pair<int, int>> edges;
                        edges.reserve(max(0, n - 1));
                        for (int v : code)
                        {
                                int leaf = *leaves.begin();
                                leaves.erase(leaves.begin());
                                edges.push_back(
                                    {leaf, v});
                                --deg[leaf];
                                --deg[v];
                                if (deg[v] == 1)
                                {
                                        leaves.insert(v);
                                }
                        }
                        int u = *leaves.begin();
                        leaves.erase(leaves.begin());
                        int v = *leaves.begin();
                        edges.push_back(
                            {u, v});
                        return edges;
                }
                long long cayley_mod(long long n, long long mod)
                {
                        if (n <= 1)
                        {
                                return 1 % mod;
                        }
                        return pw_mod(n % mod, n - 2, mod);
                }
                __int128 cayley_i128(int n)
                {
                        if (n <= 1)
                        {
                                return 1;
                        }
                        __int128 r = 1;
                        for (int i = 0; i < n - 2; ++i)
                        {
                                r *= n;
                        }
                        return r;
                }
        }
}

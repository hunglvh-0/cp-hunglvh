// Source: https://cp-algorithms.com/graph/kirchhoff-theorem.html

namespace Matrix_Tree_Theorem
{
    namespace MatrixTreeTheorem
    {
        long long norm(long long x, long long mod)
    {
            x %= mod;
            if (x < 0)
    {
                x += mod;

    }
            return x;

    }
        long long pw(long long a, long long e, long long mod)
    {
            long long r = 1 % mod;
            a = norm(a, mod);
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
        long long inv(long long a, long long mod)
    {
            return pw(a, mod - 2, mod);

    }
        long long det_mod(vector<vector<long long>> a, long long mod)
    {
            int n = (int)a.size();
            long long ans = 1;
            for (int i = 0; i < n; ++i)
    {
                int piv = -1;
                for (int r = i; r < n; ++r)
    {
                    if (norm(a[r][i], mod) != 0)
    {
                        piv = r;
                        break;

    }

    }
                if (piv == -1)
    {
                    return 0;

    }
                if (piv != i)
    {
                    swap(a[piv], a[i]);
                    ans = norm(-ans, mod);

    }
                long long v = norm(a[i][i], mod);
                ans = (long long)((__int128)ans * v % mod);
                long long iv = inv(v, mod);
                for (int r = i + 1; r < n; ++r)
    {
                    long long coef = (long long)((__int128)norm(a[r][i], mod) * iv % mod);
                    if (!coef)
    {
                        continue;

    }
                    for (int c = i; c < n; ++c)
    {
                        a[r][c] = norm(a[r][c] - (long long)((__int128)coef * norm(a[i][c], mod) % mod), mod);

    }

    }

    }
            return ans;

    }
        vector<vector<long long>> cofactor_matrix(const vector<vector<long long>> &a, int skip_r, int skip_c)
    {
            int n = (int)a.size();
            vector<vector<long long>> m;
            m.reserve(n - 1);
            for (int i = 0; i < n; ++i)
    {
                if (i == skip_r)
    {
                    continue;

    }
                vector<long long> row;
                row.reserve(n - 1);
                for (int j = 0; j < n; ++j)
    {
                    if (j == skip_c)
    {
                        continue;

    }
                    row.push_back(a[i][j]);

    }
                m.push_back(row);

    }
            return m;

    }
        long long count_spanning_trees_undirected(int n, const vector<pair<int, int>> &edges, long long mod = 1000000007LL)
    {
            if (n == 0)
    {
                return 0;

    }
            if (n == 1)
    {
                return 1 % mod;

    }
            vector<vector<long long>> lap(n, vector<long long>(n, 0));
            for (auto [u, v] : edges)
    {
                if (u == v)
    {
                    continue;

    }
                lap[u][u] = norm(lap[u][u] + 1, mod);
                lap[v][v] = norm(lap[v][v] + 1, mod);
                lap[u][v] = norm(lap[u][v] - 1, mod);
                lap[v][u] = norm(lap[v][u] - 1, mod);

    }
            auto cof = cofactor_matrix(lap, n - 1, n - 1);
            return det_mod(cof, mod);

    }
        long long count_in_arborescences_directed(int n, int root, const vector<pair<int, int>> &edges, long long mod = 1000000007LL)
    {
            if (n == 0)
    {
                return 0;

    }
            if (n == 1)
    {
                return 1 % mod;

    }
            vector<vector<long long>> lap(n, vector<long long>(n, 0));
            for (auto [u, v] : edges)
    {
                if (u == v)
    {
                    continue;

    }
                lap[v][v] = norm(lap[v][v] + 1, mod);
                lap[v][u] = norm(lap[v][u] - 1, mod);

    }
            auto cof = cofactor_matrix(lap, root, root);
            return det_mod(cof, mod);

    }
    }
}

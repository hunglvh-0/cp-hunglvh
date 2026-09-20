// Source: https://oi-wiki.org/math/number-theory/dirichlet/

namespace Dirichlet_Convolution
{
    namespace DirichletConvolution
    {
        vector<long long> conv(const vector<long long> &f, const vector<long long> &g, int n, long long mod = 0)
    {
            vector<long long> h(n + 1, 0);
            for (int i = 1; i <= n; i++)
    {
                for (int j = 1; i * j <= n; j++)
    {
                    if (mod == 0)
    {
                        h[i * j] += (long long)((__int128)f[i] * g[j]);

    }
    else
    {
                        h[i * j] = (h[i * j] + (long long)((__int128)f[i] * g[j] % mod)) % mod;

    }

    }

    }
            return h;

    }
        vector<int> mu(int n)
    {
            vector<int> pr;
            vector<int> mk(n + 1, 0);
            vector<int> u(n + 1, 0);
            u[1] = 1;
            for (int i = 2; i <= n; i++)
    {
                if (!mk[i])
    {
                    pr.push_back(i);
                    u[i] = -1;

    }
                for (int p : pr)
    {
                    if (1LL * i * p > n)
    {
                        break;

    }
                    mk[i * p] = 1;
                    if (i % p == 0)
    {
                        u[i * p] = 0;
                        break;

    }
                    u[i * p] = -u[i];

    }

    }
            return u;

    }
        vector<long long> one(int n)
    {
            vector<long long> f(n + 1, 1);
            f[0] = 0;
            return f;

    }
        vector<long long> id(int n)
    {
            vector<long long> f(n + 1, 0);
            for (int i = 1; i <= n; i++)
    {
                f[i] = i;

    }
            return f;

    }
        vector<long long> mobius_inv(const vector<long long> &F, int n, long long mod = 0)
    {
            vector<int> u = mu(n);
            vector<long long> m(n + 1, 0);
            for (int i = 1; i <= n; i++)
    {
                m[i] = u[i];

    }
            return conv(F, m, n, mod);

    }
        vector<long long> tau(int n)
    {
            vector<long long> o = one(n);
            return conv(o, o, n);

    }
        vector<long long> sigma(int n)
    {
            vector<long long> o = one(n);
            vector<long long> i = id(n);
            return conv(o, i, n);

    }
    }
}

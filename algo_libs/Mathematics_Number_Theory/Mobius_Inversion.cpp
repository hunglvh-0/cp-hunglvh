// Source: https://oi-wiki.org/math/number-theory/mobius/

namespace Mobius_Inversion
{
        namespace MobiusInversion
        {
                struct MobiusSieve
                {
                        int n;
                        vector<int> p;
                        vector<int> lp;
                        vector<int> mu;
                        vector<int> pre_mu;
                        MobiusSieve(int _n = 0)
                        {
                                n = 0;
                                if (_n)
                                {
                                        init(_n);
                                }
                        }
                        void init(int _n)
                        {
                                n = _n;
                                p.clear();
                                lp.assign(n + 1, 0);
                                mu.assign(n + 1, 0);
                                pre_mu.assign(n + 1, 0);
                                mu[1] = 1;
                                for (int i = 2; i <= n; ++i)
                                {
                                        if (!lp[i])
                                        {
                                                lp[i] = i;
                                                p.push_back(i);
                                                mu[i] = -1;
                                        }
                                        for (int x : p)
                                        {
                                                long long v = 1LL * i * x;
                                                if (v > n)
                                                {
                                                        break;
                                                }
                                                lp[v] = x;
                                                if (x == lp[i])
                                                {
                                                        mu[v] = 0;
                                                        break;
                                                }
                                                mu[v] = -mu[i];
                                        }
                                }
                                for (int i = 1; i <= n; ++i)
                                {
                                        pre_mu[i] = pre_mu[i - 1] + mu[i];
                                }
                        }
                };
                template <class T>
                vector<T> divisor_zeta(const vector<T> &f)
                {
                        int n = (int)f.size() - 1;
                        vector<T> F(n + 1, 0);
                        for (int d = 1; d <= n; ++d)
                        {
                                for (int k = 1; 1LL * d * k <= n; ++k)
                                {
                                        F[d * k] += f[d];
                                }
                        }
                        return F;
                }
                template <class T>
                vector<T> mobius_invert_divisor_sum(const vector<T> &F, const vector<int> &mu)
                {
                        int n = min((int)F.size() - 1, (int)mu.size() - 1);
                        vector<T> f(n + 1, 0);
                        for (int d = 1; d <= n; ++d)
                        {
                                if (!mu[d])
                                {
                                        continue;
                                }
                                for (int k = 1; 1LL * d * k <= n; ++k)
                                {
                                        f[d * k] += (T)mu[d] * F[k];
                                }
                        }
                        return f;
                }
                template <class T>
                vector<T> multiple_zeta(const vector<T> &f)
                {
                        int n = (int)f.size() - 1;
                        vector<T> F(n + 1, 0);
                        for (int i = 1; i <= n; ++i)
                        {
                                for (int k = 1; 1LL * i * k <= n; ++k)
                                {
                                        F[i] += f[i * k];
                                }
                        }
                        return F;
                }
                template <class T>
                vector<T> mobius_invert_multiple_sum(const vector<T> &F, const vector<int> &mu)
                {
                        int n = min((int)F.size() - 1, (int)mu.size() - 1);
                        vector<T> f(n + 1, 0);
                        for (int k = 1; k <= n; ++k)
                        {
                                if (!mu[k])
                                {
                                        continue;
                                }
                                for (int i = 1; 1LL * i * k <= n; ++i)
                                {
                                        f[i] += (T)mu[k] * F[i * k];
                                }
                        }
                        return f;
                }
        }
}

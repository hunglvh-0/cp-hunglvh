// Source: https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html

namespace DP_DivideAndConquer
{
    namespace DPDivideAndConquer
    {
        const long long INF64 = (long long)4e18;
        struct Solver
        {
            int n;
            vector<long long> prv;
            vector<long long> cur;
            function<long long(int, int)> cost;
            void compute(int l, int r, int optL, int optR)
            {
                if (l > r)
                {
                    return;
                }
                int mid = (l + r) >> 1;
                pair<long long, int> best =
                    {
                        INF64, -1};
                int up = min(mid, optR);
                for (int k = optL; k <= up; ++k)
                {
                    long long cand = prv[k - 1] + cost(k, mid);
                    if (cand < best.first)
                    {
                        best =
                            {
                                cand, k};
                    }
                }
                cur[mid] = best.first;
                int opt = best.second;
                compute(l, mid - 1, optL, opt);
                compute(mid + 1, r, opt, optR);
            }
            vector<long long> solve_layers(int groups, int _n, const function<long long(int, int)> &_cost)
            {
                n = _n;
                cost = _cost;
                prv.assign(n + 1, INF64);
                cur.assign(n + 1, INF64);
                prv[0] = 0;
                for (int i = 1; i <= n; ++i)
                {
                    prv[i] = cost(1, i);
                }
                for (int g = 2; g <= groups; ++g)
                {
                    fill(cur.begin(), cur.end(), INF64);
                    compute(1, n, 1, n);
                    prv.swap(cur);
                }
                return prv;
            }
        };
    }
}

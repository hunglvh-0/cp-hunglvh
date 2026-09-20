// Source: https://en.wikipedia.org/wiki/Hill_climbing

namespace HillClimbing
{
        namespace HillClimbing
        {
                using Vec = vector<double>;
                struct Solver
                {
                        mt19937_64 rng;
                        Solver(uint64_t seed = chrono::steady_clock::now().time_since_epoch().count()) : rng(seed)
                        {
                        }
                        double rnd(double l, double r)
                        {
                                uniform_real_distribution<double> dist(l, r);
                                return dist(rng);
                        }
                        int rndi(int l, int r)
                        {
                                uniform_int_distribution<int> dist(l, r);
                                return dist(rng);
                        }
                        pair<Vec, double> maximize(
                            const Vec &start,
                            const function<double(const Vec &)> &objective,
                            double step = 1.0,
                            int iters = 30000,
                            double decay = 0.9995,
                            double grow = 1.01)
                        {
                                Vec cur = start;
                                double curv = objective(cur);
                                Vec best = cur;
                                double bestv = curv;
                                for (int it = 0; it < iters; ++it)
                                {
                                        Vec cand = cur;
                                        int id = rndi(0, (int)cand.size() - 1);
                                        cand[id] += rnd(-step, step);
                                        double val = objective(cand);
                                        if (val >= curv)
                                        {
                                                cur = cand;
                                                curv = val;
                                                step *= grow;
                                                if (curv > bestv)
                                                {
                                                        best = cur;
                                                        bestv = curv;
                                                }
                                        }
                                        else
                                        {
                                                step *= decay;
                                        }
                                }
                                return {
                                    best, bestv};
                        }
                        pair<Vec, double> maximize_with_restarts(
                            int dims,
                            const function<double(const Vec &)> &objective,
                            const vector<pair<double, double>> &bounds,
                            int restarts = 20,
                            double step = 1.0,
                            int iters = 30000)
                        {
                                Vec best;
                                double bestv = -1e300;
                                for (int r = 0; r < restarts; ++r)
                                {
                                        Vec start(dims, 0.0);
                                        for (int i = 0; i < dims; ++i)
                                        {
                                                start[i] = rnd(bounds[i].first, bounds[i].second);
                                        }
                                        auto got = maximize(start, objective, step, iters);
                                        if (got.second > bestv)
                                        {
                                                best = got.first;
                                                bestv = got.second;
                                        }
                                }
                                return {
                                    best, bestv};
                        }
                };
        }
}

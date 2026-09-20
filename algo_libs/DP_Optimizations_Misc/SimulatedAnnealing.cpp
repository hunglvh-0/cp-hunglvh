// Source: https://en.wikipedia.org/wiki/Simulated_annealing

namespace SimulatedAnnealing
{
        namespace SimulatedAnnealing
        {
                using State = vector<double>;
                struct Solver
                {
                        mt19937_64 rng;
                        Solver(uint64_t seed = chrono::steady_clock::now().time_since_epoch().count()) : rng(seed)
                        {
                        }
                        double rnd01()
                        {
                                uniform_real_distribution<double> dist(0.0, 1.0);
                                return dist(rng);
                        }
                        double rnd(double l, double r)
                        {
                                uniform_real_distribution<double> dist(l, r);
                                return dist(rng);
                        }
                        pair<State, double> minimize(
                            const State &start,
                            const function<double(const State &)> &energy,
                            const function<void(State &, mt19937_64 &, double)> &mutate,
                            double T0 = 1e3,
                            double Tend = 1e-4,
                            double alpha = 0.995,
                            int inner = 100)
                        {
                                State cur = start;
                                double curE = energy(cur);
                                State best = cur;
                                double bestE = curE;
                                for (double T = T0; T > Tend; T *= alpha)
                                {
                                        for (int rep = 0; rep < inner; ++rep)
                                        {
                                                State cand = cur;
                                                mutate(cand, rng, T);
                                                double nxtE = energy(cand);
                                                double d = nxtE - curE;
                                                if (d <= 0 or exp(-d / T) > rnd01())
                                                {
                                                        cur = cand;
                                                        curE = nxtE;
                                                        if (curE < bestE)
                                                        {
                                                                best = cur;
                                                                bestE = curE;
                                                        }
                                                }
                                        }
                                }
                                return {
                                    best, bestE};
                        }
                        pair<State, double> minimize_with_restarts(
                            int dims,
                            const vector<pair<double, double>> &bounds,
                            const function<double(const State &)> &energy,
                            const function<void(State &, mt19937_64 &, double)> &mutate,
                            int restarts = 20)
                        {
                                State best;
                                double bestE = 1e300;
                                for (int r = 0; r < restarts; ++r)
                                {
                                        State start(dims, 0.0);
                                        for (int i = 0; i < dims; ++i)
                                        {
                                                start[i] = rnd(bounds[i].first, bounds[i].second);
                                        }
                                        auto cur = minimize(start, energy, mutate);
                                        if (cur.second < bestE)
                                        {
                                                best = cur.first;
                                                bestE = cur.second;
                                        }
                                }
                                return {
                                    best, bestE};
                        }
                };
        }
}

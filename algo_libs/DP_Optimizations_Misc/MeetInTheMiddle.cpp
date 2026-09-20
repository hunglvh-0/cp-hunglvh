// Source: https://cp-algorithms.com/algebra/all-submasks.html

namespace MeetInTheMiddle
{
        namespace MeetInTheMiddle
        {
                vector<long long> subset_sums(const vector<long long> &a, int l, int r)
                {
                        int len = r - l;
                        vector<long long> s(1 << len, 0);
                        for (int mask = 0; mask < (1 << len); ++mask)
                        {
                                long long cur = 0;
                                for (int i = 0; i < len; ++i)
                                {
                                        if ((mask >> i) & 1)
                                        {
                                                cur += a[l + i];
                                        }
                                }
                                s[mask] = cur;
                        }
                        return s;
                }
                long long max_subset_sum_leq(const vector<long long> &a, long long S)
                {
                        int n = (int)a.size();
                        int m = n >> 1;
                        auto L = subset_sums(a, 0, m);
                        auto R = subset_sums(a, m, n);
                        sort(R.begin(), R.end());
                        long long ans = (long long)-4e18;
                        for (long long x : L)
                        {
                                if (x > S)
                                {
                                        continue;
                                }
                                auto it = upper_bound(R.begin(), R.end(), S - x);
                                if (it == R.begin())
                                {
                                        continue;
                                }
                                --it;
                                ans = max(ans, x + *it);
                        }
                        return ans;
                }
                long long count_subset_sum_eq(const vector<long long> &a, long long target)
                {
                        int n = (int)a.size();
                        int m = n >> 1;
                        auto L = subset_sums(a, 0, m);
                        auto R = subset_sums(a, m, n);
                        unordered_map<long long, long long> freq;
                        for (long long x : R)
                        {
                                ++freq[x];
                        }
                        long long ans = 0;
                        for (long long x : L)
                        {
                                auto it = freq.find(target - x);
                                if (it != freq.end())
                                {
                                        ans += it->second;
                                }
                        }
                        return ans;
                }
                long long min_abs_diff_to_target(const vector<long long> &a, long long target)
                {
                        int n = (int)a.size();
                        int m = n >> 1;
                        auto L = subset_sums(a, 0, m);
                        auto R = subset_sums(a, m, n);
                        sort(R.begin(), R.end());
                        long long best = (long long)4e18;
                        for (long long x : L)
                        {
                                long long need = target - x;
                                auto it = lower_bound(R.begin(), R.end(), need);
                                if (it != R.end())
                                {
                                        best = min(best, llabs(x + *it - target));
                                }
                                if (it != R.begin())
                                {
                                        --it;
                                        best = min(best, llabs(x + *it - target));
                                }
                        }
                        return best;
                }
        }
}

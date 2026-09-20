// Source: https://mamnoonsiam.github.io/posts/attack-on-aliens.html

namespace DP_AlienTrick_WQS
{
    namespace DPAlienTrickWQS
    {
        struct State
    {
            long long val;
            int cnt;

    }
    ;
        State better(const State &a, const State &b)
    {
            if (a.val != b.val)
    {
                return (a.val > b.val ? a : b);

    }
            return (a.cnt > b.cnt ? a : b);

    }
        State eval_with_penalty(const vector<long long> &a, long long lambda)
    {
            const long long NEG = (long long)-4e18;
            State dp0
    {
    0, 0
    }
    ;
            State dp1
    {
    NEG, -1000000000
    }
    ;
            for (long long x : a)
    {
                State ndp1 = better(
                    State
    {
    dp1.val + x, dp1.cnt
    }
    ,
                    State
    {
    dp0.val + x - lambda, dp0.cnt + 1
    }
    );
                State ndp0 = better(dp0, ndp1);
                dp0 = ndp0;
                dp1 = ndp1;

    }
            return better(dp0, dp1);

    }
        long long max_sum_exact_k_segments(const vector<long long> &a, int k)
    {
            long long lo = -1000000000000000LL;
            long long hi = 1000000000000000LL;
            long long best_lambda = lo;
            while (lo <= hi)
    {
                long long mid = lo + ((hi - lo) >> 1);
                State cur = eval_with_penalty(a, mid);
                if (cur.cnt >= k)
    {
                    best_lambda = mid;
                    lo = mid + 1;

    }
    else
    {
                    hi = mid - 1;

    }

    }
            State ans = eval_with_penalty(a, best_lambda);
            return ans.val + 1LL * best_lambda * k;

    }
    }
}

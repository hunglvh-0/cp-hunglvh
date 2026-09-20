// Source: https://atcoder.github.io/ac-library/production/document_en/math.html

namespace Floor_Sum
{
        namespace FloorSum
        {
                using u64 = unsigned long long;
                u64 floor_sum_u(u64 n, u64 m, u64 a, u64 b)
                {
                        u64 ans = 0;
                        while (true)
                        {
                                if (a >= m)
                                {
                                        ans += (n - 1) * n * (a / m) / 2;
                                        a %= m;
                                }
                                if (b >= m)
                                {
                                        ans += n * (b / m);
                                        b %= m;
                                }
                                u64 y = a * n + b;
                                if (y < m)
                                {
                                        break;
                                }
                                n = y / m;
                                b = y % m;
                                swap(m, a);
                        }
                        return ans;
                }
                long long floor_sum(long long n, long long m, long long a, long long b)
                {
                        if (n <= 0 or m <= 0)
                        {
                                return 0;
                        }
                        __int128 ans = 0;
                        auto norm = [&](long long x)
                        {
                                x %= m;
                                if (x < 0)
                                {
                                        x += m;
                                }
                                return x;
                        };
                        if (a < 0)
                        {
                                long long aa = norm(a);
                                ans -= (__int128)n * (n - 1) / 2 * ((aa - a) / m);
                                a = aa;
                        }
                        if (b < 0)
                        {
                                long long bb = norm(b);
                                ans -= (__int128)n * ((bb - b) / m);
                                b = bb;
                        }
                        ans += floor_sum_u((u64)n, (u64)m, (u64)a, (u64)b);
                        return (long long)ans;
                }
        }
}

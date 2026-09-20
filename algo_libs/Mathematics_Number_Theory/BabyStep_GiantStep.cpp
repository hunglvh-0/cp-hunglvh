// Source: https://cp-algorithms.com/algebra/discrete-log.html

namespace BabyStep_GiantStep
{
        namespace BabyStepGiantStep
        {
                long long pw(long long a, long long e, long long m)
                {
                        long long r = 1 % m;
                        a %= m;
                        while (e > 0)
                        {
                                if (e & 1)
                                {
                                        r = (long long)((__int128)r * a % m);
                                }
                                a = (long long)((__int128)a * a % m);
                                e >>= 1;
                        }
                        return r;
                }
                long long exg(long long a, long long b, long long &x, long long &y)
                {
                        if (b == 0)
                        {
                                x = 1;
                                y = 0;
                                return a;
                        }
                        long long x1 = 0;
                        long long y1 = 0;
                        long long g = exg(b, a % b, x1, y1);
                        x = y1;
                        y = x1 - y1 * (a / b);
                        return g;
                }
                long long inv(long long a, long long m)
                {
                        long long x = 0;
                        long long y = 0;
                        long long g = exg(a, m, x, y);
                        if (g != 1)
                        {
                                return -1;
                        }
                        x %= m;
                        if (x < 0)
                        {
                                x += m;
                        }
                        return x;
                }
                long long bsgs(long long a, long long b, long long m)
                {
                        a %= m;
                        b %= m;
                        if (m == 1)
                        {
                                return 0;
                        }
                        if (b == 1)
                        {
                                return 0;
                        }
                        int n = (int)sqrt((long double)m) + 1;
                        unordered_map<long long, int> mp;
                        mp.reserve((size_t)n * 2 + 7);
                        long long cur = b;
                        for (int q = 0; q <= n; q++)
                        {
                                mp[cur] = q;
                                cur = (long long)((__int128)cur * a % m);
                        }
                        long long an = 1;
                        for (int i = 0; i < n; i++)
                        {
                                an = (long long)((__int128)an * a % m);
                        }
                        cur = 1;
                        for (int p = 1; p <= n + 1; p++)
                        {
                                cur = (long long)((__int128)cur * an % m);
                                auto it = mp.find(cur);
                                if (it != mp.end())
                                {
                                        long long x = 1LL * p * n - it->second;
                                        if (x >= 0)
                                        {
                                                return x;
                                        }
                                }
                        }
                        return -1;
                }
                long long ex_bsgs(long long a, long long b, long long m)
                {
                        a %= m;
                        b %= m;
                        if (m == 1)
                        {
                                return 0;
                        }
                        if (b == 1)
                        {
                                return 0;
                        }
                        if (a == 0)
                        {
                                return b == 0 ? 1 : -1;
                        }
                        long long k = 1;
                        long long ad = 0;
                        long long g = 0;
                        while ((g = gcd(a, m)) > 1)
                        {
                                if (b == k)
                                {
                                        return ad;
                                }
                                if (b % g)
                                {
                                        return -1;
                                }
                                b /= g;
                                m /= g;
                                ad++;
                                k = (long long)((__int128)k * (a / g) % m);
                        }
                        long long ik = inv(k, m);
                        if (ik == -1)
                        {
                                return -1;
                        }
                        long long t = (long long)((__int128)b * ik % m);
                        long long x = bsgs(a, t, m);
                        if (x == -1)
                        {
                                return -1;
                        }
                        return x + ad;
                }
        }
}

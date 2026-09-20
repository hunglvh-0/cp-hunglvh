// Source: Local/Reconstructed

namespace String_Hashing
{
    struct DoubleHash
    {
        static const int MOD1 = 1000000007;
        static const int MOD2 = 1000000009;
        static const int BASE1 = 911382323;
        static const int BASE2 = 972663749;
        int h1 = 0, h2 = 0;
        DoubleHash() = default;
        DoubleHash(int a, int b) : h1(a), h2(b)
    {
    }
        bool operator==(const DoubleHash &o) const
    {
            return h1 == o.h1 and h2 == o.h2;

    }
        bool operator!=(const DoubleHash &o) const
    {
            return !(*this == o);

    }
    }
    ;
    struct StringHashing
    {
        int n = 0;
        string s;
        vector<int> p1, p2, pref1, pref2;
        StringHashing() = default;
        StringHashing(const string &t)
    {
     build(t); 
    }
        void build(const string &t)
    {
            s = t;
            n = (int)s.size();
            p1.assign(n + 1, 1);
            p2.assign(n + 1, 1);
            pref1.assign(n + 1, 0);
            pref2.assign(n + 1, 0);
            for (int i = 0; i < n; ++i)
    {
                p1[i + 1] = (long long)p1[i] * DoubleHash::BASE1 % DoubleHash::MOD1;
                p2[i + 1] = (long long)p2[i] * DoubleHash::BASE2 % DoubleHash::MOD2;
                pref1[i + 1] = ((long long)pref1[i] * DoubleHash::BASE1 + (unsigned char)s[i] + 1) % DoubleHash::MOD1;
                pref2[i + 1] = ((long long)pref2[i] * DoubleHash::BASE2 + (unsigned char)s[i] + 1) % DoubleHash::MOD2;

    }

    }
        DoubleHash get(int l, int r) const
    {
            long long x1 = pref1[r] - (long long)pref1[l] * p1[r - l] % DoubleHash::MOD1;
            if (x1 < 0)
                x1 += DoubleHash::MOD1;
            long long x2 = pref2[r] - (long long)pref2[l] * p2[r - l] % DoubleHash::MOD2;
            if (x2 < 0)
                x2 += DoubleHash::MOD2;
            return DoubleHash((int)x1, (int)x2);

    }
        bool equalSubstr(int l1, int r1, int l2, int r2) const
    {
            if (r1 - l1 != r2 - l2)
                return false;
            return get(l1, r1) == get(l2, r2);

    }
        int lcp(int i, int j) const
    {
            int lo = 0, hi = n - max(i, j), ans = 0;
            while (lo <= hi)
    {
                int mid = (lo + hi) >> 1;
                if (get(i, i + mid) == get(j, j + mid))
    {
                    ans = mid;
                    lo = mid + 1;

    }
    else
                    hi = mid - 1;

    }
            return ans;

    }
    }
    ;
}

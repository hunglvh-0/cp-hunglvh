// Source: Local/Reconstructed

namespace RabinKarp
{
    struct RabinKarp
    {
        static const int MOD1 = 1000000007;
        static const int MOD2 = 1000000009;
        static const int BASE1 = 911382323;
        static const int BASE2 = 972663749;
        vector<int> p1, p2, h1, h2;
        string s;
        void build(const string &t)
    {
            s = t;
            int n = (int)s.size();
            p1.assign(n + 1, 1);
            p2.assign(n + 1, 1);
            h1.assign(n + 1, 0);
            h2.assign(n + 1, 0);
            for (int i = 0; i < n; ++i)
    {
                p1[i + 1] = (long long)p1[i] * BASE1 % MOD1;
                p2[i + 1] = (long long)p2[i] * BASE2 % MOD2;
                h1[i + 1] = ((long long)h1[i] * BASE1 + (unsigned char)s[i] + 1) % MOD1;
                h2[i + 1] = ((long long)h2[i] * BASE2 + (unsigned char)s[i] + 1) % MOD2;

    }

    }
        pair<int, int> getHash(int l, int r) const
    {
            long long x1 = h1[r] - (long long)h1[l] * p1[r - l] % MOD1;
            if (x1 < 0)
                x1 += MOD1;
            long long x2 = h2[r] - (long long)h2[l] * p2[r - l] % MOD2;
            if (x2 < 0)
                x2 += MOD2;
            return
    {
    (int)x1, (int)x2
    }
    ;

    }
        static pair<int, int> hashString(const string &t)
    {
            long long a = 0, b = 0;
            for (char c : t)
    {
                a = (a * BASE1 + (unsigned char)c + 1) % MOD1;
                b = (b * BASE2 + (unsigned char)c + 1) % MOD2;

    }
            return
    {
    (int)a, (int)b
    }
    ;

    }
        vector<int> findAll(const string &text, const string &pat)
    {
            vector<int> ans;
            int n = (int)text.size(), m = (int)pat.size();
            if (m == 0)
    {
                for (int i = 0; i <= n; ++i)
                    ans.push_back(i);
                return ans;

    }
            if (m > n)
                return ans;
            build(text);
            auto hp = hashString(pat);
            for (int i = 0; i + m <= n; ++i)
    {
                if (getHash(i, i + m) == hp)
                    ans.push_back(i);

    }
            return ans;

    }
    }
    ;
}

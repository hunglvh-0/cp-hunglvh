// Source: Local/Reconstructed

namespace Manacher
{
    struct Manacher
    {
        string s;
        vector<int> d1, d2;
        Manacher() = default;
        Manacher(const string &t)
    {
     build(t); 
    }
        void build(const string &t)
    {
            s = t;
            int n = (int)s.size();
            d1.assign(n, 0);
            d2.assign(n, 0);
            for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
                int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
                while (i - k >= 0 and i + k < n and s[i - k] == s[i + k])
                    ++k;
                d1[i] = k--;
                if (i + k > r)
    {
                    l = i - k;
                    r = i + k;

    }

    }
            for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
                int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
                while (i - k - 1 >= 0 and i + k < n and s[i - k - 1] == s[i + k])
                    ++k;
                d2[i] = k--;
                if (i + k > r)
    {
                    l = i - k - 1;
                    r = i + k;

    }

    }

    }
        int longestPalindromeLength() const
    {
            int ans = 0;
            for (int x : d1)
                ans = max(ans, 2 * x - 1);
            for (int x : d2)
                ans = max(ans, 2 * x);
            return ans;

    }
    }
    ;
}

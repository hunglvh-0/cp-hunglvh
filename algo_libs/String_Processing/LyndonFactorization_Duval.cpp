// Source: Local/Reconstructed

namespace LyndonFactorization_Duval
{
    vector<pair<int, int>> duvalFactorization(const string &s)
    {
        int n = (int)s.size();
        vector<pair<int, int>> fac;
        for (int i = 0; i < n;)
    {
            int j = i + 1, k = i;
            while (j < n and s[k] <= s[j])
    {
                if (s[k] < s[j])
                    k = i;
                else
                    ++k;
                ++j;

    }
            while (i <= k)
    {
                fac.push_back(
    {
    i, i + (j - k)
    }
    );
                i += j - k;

    }

    }
        return fac;
    }
    vector<string> duvalFactorStrings(const string &s)
    {
        vector<string> out;
        auto fac = duvalFactorization(s);
        for (auto [l, r] : fac)
            out.push_back(s.substr(l, r - l));
        return out;
    }
}

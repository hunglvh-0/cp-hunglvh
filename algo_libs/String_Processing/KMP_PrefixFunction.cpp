// Source: Local/Reconstructed

namespace KMP_PrefixFunction
{
    vector<int> prefixFunction(const string &s)
    {
        int n = (int)s.size();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; ++i)
    {
            int j = pi[i - 1];
            while (j > 0 and s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                ++j;
            pi[i] = j;

    }
        return pi;
    }
    vector<int> kmpSearch(const string &text, const string &pat)
    {
        vector<int> ans;
        if (pat.empty())
    {
            for (int i = 0; i <= (int)text.size(); ++i)
                ans.push_back(i);
            return ans;

    }
        vector<int> pi = prefixFunction(pat);
        int j = 0;
        for (int i = 0; i < (int)text.size(); ++i)
    {
            while (j > 0 and text[i] != pat[j])
                j = pi[j - 1];
            if (text[i] == pat[j])
                ++j;
            if (j == (int)pat.size())
    {
                ans.push_back(i - j + 1);
                j = pi[j - 1];

    }

    }
        return ans;
    }
}

// Source: Local/Reconstructed

namespace Z_Function
{
    vector<int> zFunction(const string &s)
    {
        int n = (int)s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i)
    {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n and s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
    {
                l = i;
                r = i + z[i] - 1;

    }

    }
        z[0] = n;
        return z;
    }
    vector<int> zSearch(const string &text, const string &pat)
    {
        vector<int> ans;
        if (pat.empty())
    {
            for (int i = 0; i <= (int)text.size(); ++i)
                ans.push_back(i);
            return ans;

    }
        string s = pat + "#" + text;
        vector<int> z = zFunction(s);
        int m = (int)pat.size();
        for (int i = m + 1; i < (int)s.size(); ++i)
    {
            if (z[i] >= m)
                ans.push_back(i - m - 1);

    }
        return ans;
    }
}

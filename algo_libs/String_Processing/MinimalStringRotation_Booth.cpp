// Source: Local/Reconstructed

namespace MinimalStringRotation_Booth
{
    int boothMinRotationIndex(const string &s)
    {
        if (s.empty())
            return 0;
        string t = s + s;
        int n = (int)s.size();
        vector<int> f(2 * n, -1);
        int k = 0;
        for (int j = 1; j < 2 * n; ++j)
    {
            int i = f[j - k - 1];
            while (i != -1 and t[j] != t[k + i + 1])
    {
                if (t[j] < t[k + i + 1])
                    k = j - i - 1;
                i = f[i];

    }
            if (t[j] != t[k + i + 1])
    {
                if (t[j] < t[k])
                    k = j;
                f[j - k] = -1;

    }
    else
                f[j - k] = i + 1;
            if (k >= n)
                break;

    }
        return k % n;
    }
    string minimalRotation(const string &s)
    {
        if (s.empty())
            return s;
        int k = boothMinRotationIndex(s);
        return s.substr(k) + s.substr(0, k);
    }
}

// Source: Local/Reconstructed

namespace SuffixArray_LCP
{
    struct SuffixArrayLCP
    {
        string s;
        vector<int> sa, rk, lcp;
        SuffixArrayLCP() = default;
        SuffixArrayLCP(const string &t)
    {
     build(t); 
    }
        void build(const string &t)
    {
            s = t;
            int n = (int)s.size();
            sa.resize(n);
            rk.resize(n);
            for (int i = 0; i < n; ++i)
    {
                sa[i] = i;
                rk[i] = (unsigned char)s[i];

    }
            vector<int> tmp(n);
            for (int k = 1;; k <<= 1)
    {
                auto cmp = [&](int i, int j)
    {
                    if (rk[i] != rk[j])
                        return rk[i] < rk[j];
                    int ri = (i + k < n ? rk[i + k] : -1);
                    int rj = (j + k < n ? rk[j + k] : -1);
                    return ri < rj;

    }
    ;
                sort(sa.begin(), sa.end(), cmp);
                tmp[sa[0]] = 0;
                for (int i = 1; i < n; ++i)
    {
                    tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);

    }
                rk = tmp;
                if (rk[sa[n - 1]] == n - 1)
                    break;

    }
            buildLCP();

    }
        void buildLCP()
    {
            int n = (int)s.size();
            lcp.assign(max(0, n - 1), 0);
            vector<int> pos(n, 0);
            for (int i = 0; i < n; ++i)
                pos[sa[i]] = i;
            int k = 0;
            for (int i = 0; i < n; ++i)
    {
                if (pos[i] == n - 1)
    {
                    k = 0;
                    continue;

    }
                int j = sa[pos[i] + 1];
                while (i + k < n and j + k < n and s[i + k] == s[j + k])
                    ++k;
                lcp[pos[i]] = k;
                if (k)
                    --k;

    }

    }
    }
    ;
}

// Source: Local/Reconstructed

namespace MainLorentz_TandemRepeats
{
    struct MainLorentzTandemRepeats
    {
        struct Block
    {
            int l, r, p;

    }
    ;
        using ull = unsigned long long;
        static const ull BASE = 1315423911ULL;
        string s, rs;
        int n = 0;
        vector<ull> pw, h, rh;
        void buildHash(const string &t)
    {
            s = t;
            n = (int)s.size();
            rs = s;
            reverse(rs.begin(), rs.end());
            pw.assign(n + 1, 1);
            h.assign(n + 1, 0);
            rh.assign(n + 1, 0);
            for (int i = 0; i < n; ++i)
    {
                pw[i + 1] = pw[i] * BASE;
                h[i + 1] = h[i] * BASE + (unsigned char)s[i] + 1;
                rh[i + 1] = rh[i] * BASE + (unsigned char)rs[i] + 1;

    }

    }
        ull getHash(const vector<ull> &pref, int l, int r) const
    {
            return pref[r] - pref[l] * pw[r - l];

    }
        int lcp(int i, int j) const
    {
            int lo = 0, hi = n - max(i, j), ans = 0;
            while (lo <= hi)
    {
                int mid = (lo + hi) >> 1;
                if (getHash(h, i, i + mid) == getHash(h, j, j + mid))
    {
                    ans = mid;
                    lo = mid + 1;

    }
    else
                    hi = mid - 1;

    }
            return ans;

    }
        int lcs(int i, int j) const
    {
            if (i < 0 or j < 0)
                return 0;
            int ri = n - 1 - i;
            int rj = n - 1 - j;
            int lo = 0, hi = min(i, j) + 1, ans = 0;
            while (lo <= hi)
    {
                int mid = (lo + hi) >> 1;
                if (getHash(rh, ri, ri + mid) == getHash(rh, rj, rj + mid))
    {
                    ans = mid;
                    lo = mid + 1;

    }
    else
                    hi = mid - 1;

    }
            return ans;

    }
        vector<Block> findBlocks(const string &t)
    {
            buildHash(t);
            vector<Block> out;
            for (int p = 1; 2 * p <= n; ++p)
    {
                for (int x = 0; x + p < n; ++x)
    {
                    int R = lcp(x, x + p);
                    int L = lcs(x - 1, x + p - 1);
                    if (L + R < p)
                        continue;
                    int stL = max(0, x - L + 1);
                    int stR = min(x, x + R - p);
                    if (stL <= stR)
                        out.push_back(
    {
    stL, stR, p
    }
    );

    }

    }
            sort(out.begin(), out.end(), [](const Block &a, const Block &b)
    {
    			if (a.p != b.p) return a.p < b.p;
    			if (a.l != b.l) return a.l < b.l;
    			return a.r < b.r; 
    }
    );
            out.erase(unique(out.begin(), out.end(), [](const Block &a, const Block &b)

    {
     return a.p == b.p and a.l == b.l and a.r == b.r; 
    }
    ),
                      out.end());
            return out;

    }
    }
    ;
}

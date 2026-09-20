// Source: Local/Reconstructed

namespace WaveletMatrix
{
    struct WaveletBitVector
    {
        int n = 0;
        vector<int> pref;
        void build(const vector<int> &bit)
        {
            n = (int)bit.size();
            pref.assign(n + 1, 0);
            for (int i = 0; i < n; ++i)
                pref[i + 1] = pref[i] + bit[i];
        }
        int rank1(int r) const
        {
            return pref[r];
        }
        int rank0(int r) const
        {
            return r - pref[r];
        }
    };
    template <class T = int, int MAXLOG = int(sizeof(T) * 8 - 1)>
    struct WaveletMatrix
    {
        using U = typename make_unsigned<T>::type;
        static constexpr U BIAS = is_signed<T>::value ? (U(1) << MAXLOG) : U(0);
        int n = 0;
        vector<WaveletBitVector> bv;
        vector<int> zeroCnt;
        static U encode(T x)
        {
            U y = (U)x;
            if constexpr (is_signed<T>::value)
                y ^= BIAS;
            return y;
        }
        static T decode(U x)
        {
            if constexpr (is_signed<T>::value)
                x ^= BIAS;
            return (T)x;
        }
        WaveletMatrix() = default;
        WaveletMatrix(const vector<T> &a)
        {
            build(a);
        }
        void build(const vector<T> &a)
        {
            n = (int)a.size();
            bv.assign(MAXLOG + 1, WaveletBitVector());
            zeroCnt.assign(MAXLOG + 1, 0);
            vector<U> cur(n), nxt(n);
            for (int i = 0; i < n; ++i)
                cur[i] = encode(a[i]);
            for (int lv = MAXLOG; lv >= 0; --lv)
            {
                vector<int> bit(n, 0);
                int z = 0;
                for (int i = 0; i < n; ++i)
                    if (((cur[i] >> lv) & 1) == 0)
                        ++z;
                zeroCnt[lv] = z;
                int p0 = 0, p1 = z;
                for (int i = 0; i < n; ++i)
                {
                    if (((cur[i] >> lv) & 1) == 0)
                        nxt[p0++] = cur[i];
                    else
                    {
                        bit[i] = 1;
                        nxt[p1++] = cur[i];
                    }
                }
                bv[lv].build(bit);
                cur.swap(nxt);
            }
        }
        int countLessEncoded(int l, int r, U x) const
        {
            int ans = 0;
            for (int lv = MAXLOG; lv >= 0; --lv)
            {
                int b = (x >> lv) & 1;
                int l0 = bv[lv].rank0(l), r0 = bv[lv].rank0(r);
                if (b)
                {
                    ans += r0 - l0;
                    l = zeroCnt[lv] + bv[lv].rank1(l);
                    r = zeroCnt[lv] + bv[lv].rank1(r);
                }
                else
                {
                    l = l0;
                    r = r0;
                }
            }
            return ans;
        }
        int countLess(int l, int r, T x) const
        {
            if (l < 0)
                l = 0;
            if (r > n)
                r = n;
            if (l >= r)
                return 0;
            return countLessEncoded(l, r, encode(x));
        }
        int countEqual(int l, int r, T x) const
        {
            if (l < 0)
                l = 0;
            if (r > n)
                r = n;
            if (l >= r)
                return 0;
            U y = encode(x);
            for (int lv = MAXLOG; lv >= 0; --lv)
            {
                int b = (y >> lv) & 1;
                if (!b)
                {
                    l = bv[lv].rank0(l);
                    r = bv[lv].rank0(r);
                }
                else
                {
                    l = zeroCnt[lv] + bv[lv].rank1(l);
                    r = zeroCnt[lv] + bv[lv].rank1(r);
                }
            }
            return r - l;
        }
        int rangeFreq(int l, int r, T low, T high) const
        {
            if (low >= high)
                return 0;
            return countLess(l, r, high) - countLess(l, r, low);
        }
        T kth(int l, int r, int k) const
        {
            if (l < 0)
                l = 0;
            if (r > n)
                r = n;
            if (l >= r or k < 0 or k >= r - l)
                return T();
            U y = 0;
            for (int lv = MAXLOG; lv >= 0; --lv)
            {
                int l0 = bv[lv].rank0(l), r0 = bv[lv].rank0(r);
                int cnt0 = r0 - l0;
                if (k < cnt0)
                {
                    l = l0;
                    r = r0;
                }
                else
                {
                    y |= (U(1) << lv);
                    k -= cnt0;
                    l = zeroCnt[lv] + bv[lv].rank1(l);
                    r = zeroCnt[lv] + bv[lv].rank1(r);
                }
            }
            return decode(y);
        }
        T prevValue(int l, int r, T x) const
        {
            int cnt = countLess(l, r, x);
            if (cnt == 0)
                return numeric_limits<T>::min();
            return kth(l, r, cnt - 1);
        }
        T nextValue(int l, int r, T x) const
        {
            int cnt = countLess(l, r, x);
            if (cnt >= r - l)
                return numeric_limits<T>::max();
            return kth(l, r, cnt);
        }
    };
}

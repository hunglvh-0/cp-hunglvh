// Source: Local/Reconstructed

namespace SuffixAutomaton_SAM
{
    struct SuffixAutomaton
    {
        struct State
    {
            array<int, 26> next;
            int link = -1;
            int len = 0;
            long long occ = 0;
            State()
    {
     next.fill(-1); 
    }

    }
    ;
        vector<State> st;
        int last = 0;
        SuffixAutomaton()
    {
            st.reserve(1 << 20);
            st.push_back(State());
            st[0].link = -1;

    }
        void clear()
    {
            st.clear();
            st.push_back(State());
            st[0].link = -1;
            last = 0;

    }
        void extend(char ch)
    {
            int c = ch - 'a';
            int cur = (int)st.size();
            st.push_back(State());
            st[cur].len = st[last].len + 1;
            st[cur].occ = 1;
            int p = last;
            while (p != -1 and st[p].next[c] == -1)
    {
                st[p].next[c] = cur;
                p = st[p].link;

    }
            if (p == -1)
                st[cur].link = 0;
            else
    {
                int q = st[p].next[c];
                if (st[p].len + 1 == st[q].len)
                    st[cur].link = q;
                else
    {
                    int clone = (int)st.size();
                    st.push_back(st[q]);
                    st[clone].len = st[p].len + 1;
                    st[clone].occ = 0;
                    while (p != -1 and st[p].next[c] == q)
    {
                        st[p].next[c] = clone;
                        p = st[p].link;

    }
                    st[q].link = st[cur].link = clone;

    }

    }
            last = cur;

    }
        void build(const string &s)
    {
            clear();
            for (char c : s)
                extend(c);

    }
        void computeOccurrences()
    {
            int mx = 0;
            for (auto &x : st)
                mx = max(mx, x.len);
            vector<int> cnt(mx + 1, 0), ord(st.size());
            for (auto &x : st)
                cnt[x.len]++;
            for (int i = 1; i <= mx; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = (int)st.size() - 1; i >= 0; --i)
                ord[--cnt[st[i].len]] = i;
            for (int i = (int)ord.size() - 1; i > 0; --i)
    {
                int v = ord[i], p = st[v].link;
                if (p >= 0)
                    st[p].occ += st[v].occ;

    }

    }
        bool contains(const string &t) const
    {
            int v = 0;
            for (char ch : t)
    {
                int c = ch - 'a';
                if (c < 0 or c >= 26)
                    return false;
                v = st[v].next[c];
                if (v == -1)
                    return false;

    }
            return true;

    }
        long long countDistinctSubstrings() const
    {
            long long ans = 0;
            for (int v = 1; v < (int)st.size(); ++v)
    {
                ans += st[v].len - st[st[v].link].len;

    }
            return ans;

    }
    }
    ;
}

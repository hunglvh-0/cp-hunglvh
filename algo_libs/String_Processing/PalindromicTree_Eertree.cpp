// Source: Local/Reconstructed

namespace PalindromicTree_Eertree
{
    struct PalindromicTree
    {
        struct Node
    {
            array<int, 26> next;
            int len = 0;
            int link = 0;
            int occ = 0;
            Node()
    {
     next.fill(0); 
    }

    }
    ;
        vector<Node> t;
        string s;
        int suff = 0;
        PalindromicTree()
    {
     init(); 
    }
        void init()
    {
            t.assign(2, Node());
            t[0].len = -1;
            t[0].link = 0;
            t[1].len = 0;
            t[1].link = 0;
            s.clear();
            suff = 1;

    }
        int getLink(int v, int pos) const
    {
            while (true)
    {
                int curlen = t[v].len;
                if (pos - 1 - curlen >= 0 and s[pos - 1 - curlen] == s[pos])
                    return v;
                v = t[v].link;

    }

    }
        void addChar(char ch)
    {
            s.push_back(ch);
            int pos = (int)s.size() - 1;
            int cur = getLink(suff, pos);
            int c = ch - 'a';
            if (!t[cur].next[c])
    {
                int now = (int)t.size();
                t.push_back(Node());
                t[now].len = t[cur].len + 2;
                if (t[now].len == 1)
                    t[now].link = 1;
                else
    {
                    int linkCand = getLink(t[cur].link, pos);
                    t[now].link = t[linkCand].next[c];

    }
                t[cur].next[c] = now;

    }
            suff = t[cur].next[c];
            t[suff].occ++;

    }
        void build(const string &str)
    {
            init();
            for (char c : str)
                addChar(c);
            for (int i = (int)t.size() - 1; i >= 2; --i)
                t[t[i].link].occ += t[i].occ;

    }
        int longestPalindromeLength() const
    {
            int ans = 0;
            for (int i = 2; i < (int)t.size(); ++i)
                ans = max(ans, t[i].len);
            return ans;

    }
    }
    ;
}

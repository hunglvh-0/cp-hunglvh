// Source: Local/Reconstructed

namespace SuffixTree_Ukkonen
{
    struct SuffixTreeUkkonen
    {
        struct Node
    {
            map<char, int> next;
            int l = 0, r = 0, par = -1, link = -1;
            int suffixIndex = -1;
            Node() = default;
            Node(int _l, int _r, int _p) : l(_l), r(_r), par(_p)
    {
    }
            int len(int pos) const
    {
     return min(r, pos + 1) - l; 
    }

    }
    ;
        string s;
        vector<Node> t;
        int n = 0;
        int activeNode = 0, activeEdge = -1, activeLen = 0;
        int rem = 0;
        int lastNew = -1;
        const int INF = (int)1e9;
        SuffixTreeUkkonen()
    {
     clear(); 
    }
        void clear()
    {
            t.clear();
            t.push_back(Node(0, 0, -1));
            t[0].link = 0;
            s.clear();
            n = 0;
            activeNode = 0;
            activeEdge = -1;
            activeLen = 0;
            rem = 0;
            lastNew = -1;

    }
        int newNode(int l, int r, int p)
    {
            t.push_back(Node(l, r, p));
            return (int)t.size() - 1;

    }
        void setSuffixIndexDfs(int v, int depth)
    {
            bool leaf = true;
            for (auto [c, to] : t[v].next)
    {
                leaf = false;
                setSuffixIndexDfs(to, depth + t[to].len(n - 1));

    }
            if (leaf)
                t[v].suffixIndex = n - depth;

    }
        void extend(int pos)
    {
            rem++;
            lastNew = -1;
            while (rem > 0)
    {
                if (activeLen == 0)
                    activeEdge = pos;
                char ec = s[activeEdge];
                if (!t[activeNode].next.count(ec))
    {
                    int leaf = newNode(pos, INF, activeNode);
                    t[activeNode].next[ec] = leaf;
                    if (lastNew != -1)
    {
                        t[lastNew].link = activeNode;
                        lastNew = -1;

    }

    }
    else
    {
                    int nxt = t[activeNode].next[ec];
                    int edgeLen = t[nxt].len(pos);
                    if (activeLen >= edgeLen)
    {
                        activeEdge += edgeLen;
                        activeLen -= edgeLen;
                        activeNode = nxt;
                        continue;

    }
                    if (s[t[nxt].l + activeLen] == s[pos])
    {
                        activeLen++;
                        if (lastNew != -1)
    {
                            t[lastNew].link = activeNode;
                            lastNew = -1;

    }
                        break;

    }
                    int split = newNode(t[nxt].l, t[nxt].l + activeLen, activeNode);
                    t[activeNode].next[ec] = split;
                    int leaf = newNode(pos, INF, split);
                    t[split].next[s[pos]] = leaf;
                    t[nxt].l += activeLen;
                    t[nxt].par = split;
                    t[split].next[s[t[nxt].l]] = nxt;
                    if (lastNew != -1)
                        t[lastNew].link = split;
                    lastNew = split;

    }
                rem--;
                if (activeNode == 0 and activeLen > 0)
    {
                    activeLen--;
                    activeEdge = pos - rem + 1;

    }
    else if (activeNode != 0)
    {
                    activeNode = t[activeNode].link == -1 ? 0 : t[activeNode].link;

    }

    }

    }
        void build(string str)
    {
            clear();
            if (str.empty() or str.back() != '$')
                str.push_back('$');
            s = str;
            n = (int)s.size();
            for (int i = 0; i < n; ++i)
                extend(i);
            setSuffixIndexDfs(0, 0);

    }
    }
    ;
}

// Source: Local/Reconstructed

namespace Trie_Standard
{
    struct TrieStandard
    {
        struct Node
    {
            array<int, 26> nxt;
            int pass = 0;
            int end = 0;
            Node()
    {
     nxt.fill(-1); 
    }

    }
    ;
        vector<Node> tr;
        TrieStandard()
    {
     tr.push_back(Node()); 
    }
        int newNode()
    {
            tr.push_back(Node());
            return (int)tr.size() - 1;

    }
        void insert(const string &s)
    {
            int u = 0;
            tr[u].pass++;
            for (char c : s)
    {
                int x = c - 'a';
                if (tr[u].nxt[x] == -1)
                    tr[u].nxt[x] = newNode();
                u = tr[u].nxt[x];
                tr[u].pass++;

    }
            tr[u].end++;

    }
        bool contains(const string &s) const
    {
            int u = 0;
            for (char c : s)
    {
                int x = c - 'a';
                if (x < 0 or x >= 26)
                    return false;
                if (tr[u].nxt[x] == -1)
                    return false;
                u = tr[u].nxt[x];

    }
            return tr[u].end > 0;

    }
        int countPrefix(const string &p) const
    {
            int u = 0;
            for (char c : p)
    {
                int x = c - 'a';
                if (x < 0 or x >= 26)
                    return 0;
                if (tr[u].nxt[x] == -1)
                    return 0;
                u = tr[u].nxt[x];

    }
            return tr[u].pass;

    }
        bool eraseOne(const string &s)
    {
            if (!contains(s))
                return false;
            int u = 0;
            tr[u].pass--;
            for (char c : s)
    {
                int x = c - 'a';
                u = tr[u].nxt[x];
                tr[u].pass--;

    }
            tr[u].end--;
            return true;

    }
    }
    ;
}

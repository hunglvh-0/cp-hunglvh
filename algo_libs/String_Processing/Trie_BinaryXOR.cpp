// Source: Local/Reconstructed

namespace Trie_BinaryXOR
{
    template <class T = int, int LOG = 31>
    struct BinaryXORTrie
    {
        struct Node
    {
            int ch[2] =
    {
    -1, -1
    }
    ;
            int cnt = 0;

    }
    ;
        vector<Node> tr;
        BinaryXORTrie()
    {
     tr.push_back(Node()); 
    }
        int newNode()
    {
            tr.push_back(Node());
            return (int)tr.size() - 1;

    }
        void insert(T x, int delta = 1)
    {
            int u = 0;
            tr[u].cnt += delta;
            for (int b = LOG; b >= 0; --b)
    {
                int bit = (x >> b) & 1;
                if (tr[u].ch[bit] == -1)
                    tr[u].ch[bit] = newNode();
                u = tr[u].ch[bit];
                tr[u].cnt += delta;

    }

    }
        bool eraseOne(T x)
    {
            if (tr[0].cnt == 0)
                return false;
            int u = 0;
            vector<int> path =
    {
    0
    }
    ;
            for (int b = LOG; b >= 0; --b)
    {
                int bit = (x >> b) & 1;
                int v = tr[u].ch[bit];
                if (v == -1 or tr[v].cnt == 0)
                    return false;
                u = v;
                path.push_back(u);

    }
            for (int id : path)
                tr[id].cnt--;
            return true;

    }
        bool empty() const
    {
            return tr[0].cnt == 0;

    }
        T maxXor(T x) const
    {
            if (empty())
                return 0;
            int u = 0;
            T y = 0;
            for (int b = LOG; b >= 0; --b)
    {
                int bit = (x >> b) & 1;
                int want = bit ^ 1;
                int v = tr[u].ch[want];
                if (v != -1 and tr[v].cnt > 0)
    {
                    y |= (T(1) << b);
                    u = v;

    }
    else
                    u = tr[u].ch[bit];

    }
            return y;

    }
        T minXor(T x) const
    {
            if (empty())
                return 0;
            int u = 0;
            T y = 0;
            for (int b = LOG; b >= 0; --b)
    {
                int bit = (x >> b) & 1;
                int v = tr[u].ch[bit];
                if (v != -1 and tr[v].cnt > 0)
                    u = v;
                else
    {
                    y |= (T(1) << b);
                    u = tr[u].ch[bit ^ 1];

    }

    }
            return y;

    }
    }
    ;
}

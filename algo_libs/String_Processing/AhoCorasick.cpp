// Source: Local/Reconstructed

namespace AhoCorasick
{
    struct AhoCorasick
    {
        struct Node
    {
            array<int, 26> nxt;
            int link = 0;
            vector<int> out;
            Node()
    {
     nxt.fill(-1); 
    }

    }
    ;
        vector<Node> t;
        vector<int> patLen;
        AhoCorasick()
    {
     t.push_back(Node()); 
    }
        void clear()
    {
            t.clear();
            t.push_back(Node());
            patLen.clear();

    }
        int addPattern(const string &s)
    {
            int u = 0;
            for (char c : s)
    {
                int x = c - 'a';
                if (t[u].nxt[x] == -1)
    {
                    t[u].nxt[x] = (int)t.size();
                    t.push_back(Node());

    }
                u = t[u].nxt[x];

    }
            int id = (int)patLen.size();
            patLen.push_back((int)s.size());
            t[u].out.push_back(id);
            return id;

    }
        void build()
    {
            queue<int> q;
            for (int c = 0; c < 26; ++c)
    {
                int v = t[0].nxt[c];
                if (v == -1)
                    t[0].nxt[c] = 0;
                else
    {
                    t[v].link = 0;
                    q.push(v);

    }

    }
            while (!q.empty())
    {
                int v = q.front();
                q.pop();
                int lk = t[v].link;
                for (int id : t[lk].out)
                    t[v].out.push_back(id);
                for (int c = 0; c < 26; ++c)
    {
                    int to = t[v].nxt[c];
                    if (to == -1)
                        t[v].nxt[c] = t[lk].nxt[c];
                    else
    {
                        t[to].link = t[lk].nxt[c];
                        q.push(to);

    }

    }

    }

    }
        vector<vector<int>> findAll(const string &text) const
    {
            vector<vector<int>> pos(patLen.size());
            int u = 0;
            for (int i = 0; i < (int)text.size(); ++i)
    {
                char ch = text[i];
                if (ch < 'a' or ch > 'z')
    {
                    u = 0;
                    continue;

    }
                u = t[u].nxt[ch - 'a'];
                for (int id : t[u].out)
                    pos[id].push_back(i - patLen[id] + 1);

    }
            return pos;

    }
    }
    ;
}

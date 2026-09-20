// Source: Local/Reconstructed

namespace LinkCutTree
{
    struct LinkCutTree
    {
        struct Node
    {
            int ch[2] =
    {
    0, 0
    }
    ;
            int p = 0;
            bool rev = false;
            long long val = 0, sum = 0;

    }
    ;
        vector<Node> t;
        LinkCutTree(int n = 0)
    {
     init(n); 
    }
        void init(int n)
    {
            t.assign(n + 1, Node());

    }
        bool isRoot(int x) const
    {
            int p = t[x].p;
            return p == 0 or (t[p].ch[0] != x and t[p].ch[1] != x);

    }
        void pull(int x)
    {
            t[x].sum = t[x].val;
            if (t[x].ch[0])
                t[x].sum += t[t[x].ch[0]].sum;
            if (t[x].ch[1])
                t[x].sum += t[t[x].ch[1]].sum;

    }
        void push(int x)
    {
            if (!x or !t[x].rev)
                return;
            swap(t[x].ch[0], t[x].ch[1]);
            if (t[x].ch[0])
                t[t[x].ch[0]].rev = !t[t[x].ch[0]].rev;
            if (t[x].ch[1])
                t[t[x].ch[1]].rev = !t[t[x].ch[1]].rev;
            t[x].rev = false;

    }
        void rotate(int x)
    {
            int p = t[x].p, g = t[p].p;
            push(p);
            push(x);
            int dir = (t[p].ch[1] == x);
            int b = t[x].ch[dir ^ 1];
            if (!isRoot(p))
                t[g].ch[t[g].ch[1] == p] = x;
            t[x].p = g;
            t[x].ch[dir ^ 1] = p;
            t[p].p = x;
            t[p].ch[dir] = b;
            if (b)
                t[b].p = p;
            pull(p);
            pull(x);

    }
        void splay(int x)
    {
            vector<int> st;
            int y = x;
            st.push_back(y);
            while (!isRoot(y))
    {
                y = t[y].p;
                st.push_back(y);

    }
            for (int i = (int)st.size() - 1; i >= 0; --i)
                push(st[i]);
            while (!isRoot(x))
    {
                int p = t[x].p, g = t[p].p;
                if (!isRoot(p))
    {
                    if ((t[p].ch[0] == x) ^ (t[g].ch[0] == p))
                        rotate(x);
                    else
                        rotate(p);

    }
                rotate(x);

    }

    }
        int access(int x)
    {
            int last = 0;
            for (int y = x; y; y = t[y].p)
    {
                splay(y);
                t[y].ch[1] = last;
                pull(y);
                last = y;

    }
            splay(x);
            return last;

    }
        void makeRoot(int x)
    {
            access(x);
            t[x].rev = !t[x].rev;
            push(x);

    }
        int findRoot(int x)
    {
            access(x);
            while (t[x].ch[0])
    {
                push(x);
                x = t[x].ch[0];

    }
            splay(x);
            return x;

    }
        bool connected(int u, int v)
    {
            return findRoot(u) == findRoot(v);

    }
        bool link(int u, int v)
    {
            makeRoot(u);
            if (findRoot(v) == u)
                return false;
            t[u].p = v;
            return true;

    }
        bool cut(int u, int v)
    {
            makeRoot(u);
            access(v);
            if (t[v].ch[0] != u or t[u].ch[1] != 0)
                return false;
            t[v].ch[0] = 0;
            t[u].p = 0;
            pull(v);
            return true;

    }
        void setValue(int x, long long v)
    {
            access(x);
            t[x].val = v;
            pull(x);

    }
        long long pathQuery(int u, int v)
    {
            makeRoot(u);
            access(v);
            return t[v].sum;

    }
    }
    ;
}

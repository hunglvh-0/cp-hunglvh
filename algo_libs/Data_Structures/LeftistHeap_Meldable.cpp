// Source: Local/Reconstructed

namespace LeftistHeap_Meldable
{
    template <class T>
    struct LeftistHeap
    {
        struct Node
        {
            T val{};
            int l = 0, r = 0;
            int dist = 1;
        };
        vector<Node> t;
        LeftistHeap()
        {
            t.push_back(Node());
            t[0].dist = 0;
        }
        int newNode(T v)
        {
            Node x;
            x.val = v;
            x.l = x.r = 0;
            x.dist = 1;
            t.push_back(x);
            return (int)t.size() - 1;
        }
        int meld(int a, int b)
        {
            if (!a or !b)
                return a | b;
            if (t[b].val < t[a].val)
                swap(a, b);
            t[a].r = meld(t[a].r, b);
            if (t[t[a].l].dist < t[t[a].r].dist)
                swap(t[a].l, t[a].r);
            t[a].dist = t[t[a].r].dist + 1;
            return a;
        }
        int push(int root, T v)
        {
            return meld(root, newNode(v));
        }
        int pop(int root)
        {
            if (!root)
                return 0;
            return meld(t[root].l, t[root].r);
        }
        T top(int root) const
        {
            return t[root].val;
        }
        bool empty(int root) const
        {
            return root == 0;
        }
    };
}

// Source: https://cp-algorithms.com/data_structures/treap.html

namespace Treap_Implicit
{
        namespace TreapImplicitDS
        {
                struct Node
                {
                        int pr;
                        int sz;
                        long long val;
                        long long sum;
                        bool rev;
                        Node *l;
                        Node *r;
                        Node(long long _v, int _p)
                        {
                                pr = _p;
                                sz = 1;
                                val = sum = _v;
                                rev = false;
                                l = r = nullptr;
                        }
                };
                int getsz(Node *t)
                {
                        return t ? t->sz : 0;
                }
                long long getsum(Node *t)
                {
                        return t ? t->sum : 0;
                }
                void push(Node *t)
                {
                        if (!t or !t->rev)
                        {
                                return;
                        }
                        t->rev = false;
                        swap(t->l, t->r);
                        if (t->l)
                        {
                                t->l->rev = !t->l->rev;
                        }
                        if (t->r)
                        {
                                t->r->rev = !t->r->rev;
                        }
                }
                void pull(Node *t)
                {
                        if (!t)
                        {
                                return;
                        }
                        t->sz = 1 + getsz(t->l) + getsz(t->r);
                        t->sum = t->val + getsum(t->l) + getsum(t->r);
                }
                void split(Node *t, int k, Node *&a, Node *&b)
                {
                        if (!t)
                        {
                                a = b = nullptr;
                                return;
                        }
                        push(t);
                        if (getsz(t->l) >= k)
                        {
                                split(t->l, k, a, t->l);
                                b = t;
                                pull(b);
                        }
                        else
                        {
                                split(t->r, k - getsz(t->l) - 1, t->r, b);
                                a = t;
                                pull(a);
                        }
                }
                Node *merge(Node *a, Node *b)
                {
                        if (!a or !b)
                        {
                                return a ? a : b;
                        }
                        if (a->pr > b->pr)
                        {
                                push(a);
                                a->r = merge(a->r, b);
                                pull(a);
                                return a;
                        }
                        push(b);
                        b->l = merge(a, b->l);
                        pull(b);
                        return b;
                }
                struct Treap
                {
                        mt19937 rng;
                        Node *root;
                        Treap(uint32_t seed = chrono::steady_clock::now().time_since_epoch().count()) : rng(seed)
                        {
                                root = nullptr;
                        }
                        Node *make_node(long long v)
                        {
                                return new Node(v, (int)rng());
                        }
                        int size() const
                        {
                                return getsz(root);
                        }
                        void insert(int pos, long long v)
                        {
                                Node *a, *b;
                                split(root, pos, a, b);
                                root = merge(merge(a, make_node(v)), b);
                        }
                        void erase(int pos)
                        {
                                Node *a, *b, *c;
                                split(root, pos, a, b);
                                split(b, 1, b, c);
                                root = merge(a, c);
                        }
                        void reverse(int l, int r)
                        {
                                if (l > r)
                                {
                                        return;
                                }
                                Node *a, *b, *c;
                                split(root, l, a, b);
                                split(b, r - l + 1, b, c);
                                if (b)
                                {
                                        b->rev = !b->rev;
                                }
                                root = merge(merge(a, b), c);
                        }
                        long long range_sum(int l, int r)
                        {
                                if (l > r)
                                {
                                        return 0;
                                }
                                Node *a, *b, *c;
                                split(root, l, a, b);
                                split(b, r - l + 1, b, c);
                                long long ans = getsum(b);
                                root = merge(merge(a, b), c);
                                return ans;
                        }
                        void inorder(Node *t, vector<long long> &out)
                        {
                                if (!t)
                                {
                                        return;
                                }
                                push(t);
                                inorder(t->l, out);
                                out.push_back(t->val);
                                inorder(t->r, out);
                        }
                        vector<long long> to_array()
                        {
                                vector<long long> out;
                                out.reserve(size());
                                inorder(root, out);
                                return out;
                        }
                };
        }
}

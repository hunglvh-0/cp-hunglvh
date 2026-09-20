// Source: https://oi-wiki.org/string/trie/

namespace Trie_Persistent
{
        namespace TriePersistentDS
        {
                struct Node
                {
                        int ch[2];
                        int cnt;
                        Node()
                        {
                                ch[0] = ch[1] = 0;
                                cnt = 0;
                        }
                };
                struct PersistentBinaryTrie
                {
                        static const int LOG = 30;
                        vector<Node> t;
                        vector<int> root;
                        PersistentBinaryTrie()
                        {
                                t.reserve(1);
                                t.push_back(Node());
                                root.clear();
                                root.push_back(0);
                        }
                        int clone_node(int p)
                        {
                                t.push_back(t[p]);
                                return (int)t.size() - 1;
                        }
                        int insert(int prev, int x)
                        {
                                int cur = clone_node(prev);
                                int head = cur;
                                t[cur].cnt++;
                                for (int b = LOG; b >= 0; --b)
                                {
                                        int bit = (x >> b) & 1;
                                        int nxt = t[cur].ch[bit];
                                        int nn = clone_node(nxt);
                                        t[cur].ch[bit] = nn;
                                        cur = nn;
                                        t[cur].cnt++;
                                }
                                return head;
                        }
                        void add_value_new_version(int x)
                        {
                                root.push_back(insert(root.back(), x));
                        }
                        int max_xor_between(int left_ver, int right_ver, int x) const
                        {
                                int L = root[left_ver];
                                int R = root[right_ver];
                                if (t[R].cnt - t[L].cnt <= 0)
                                {
                                        return 0;
                                }
                                int ans = 0;
                                for (int b = LOG; b >= 0; --b)
                                {
                                        int bit = (x >> b) & 1;
                                        int want = bit ^ 1;
                                        int cntWant = t[t[R].ch[want]].cnt - t[t[L].ch[want]].cnt;
                                        if (cntWant > 0)
                                        {
                                                ans |= (1 << b);
                                                L = t[L].ch[want];
                                                R = t[R].ch[want];
                                        }
                                        else
                                        {
                                                L = t[L].ch[bit];
                                                R = t[R].ch[bit];
                                        }
                                }
                                return ans;
                        }
                        int min_xor_between(int left_ver, int right_ver, int x) const
                        {
                                int L = root[left_ver];
                                int R = root[right_ver];
                                if (t[R].cnt - t[L].cnt <= 0)
                                {
                                        return 0;
                                }
                                int ans = 0;
                                for (int b = LOG; b >= 0; --b)
                                {
                                        int bit = (x >> b) & 1;
                                        int cntSame = t[t[R].ch[bit]].cnt - t[t[L].ch[bit]].cnt;
                                        if (cntSame > 0)
                                        {
                                                L = t[L].ch[bit];
                                                R = t[R].ch[bit];
                                        }
                                        else
                                        {
                                                ans |= (1 << b);
                                                L = t[L].ch[bit ^ 1];
                                                R = t[R].ch[bit ^ 1];
                                        }
                                }
                                return ans;
                        }
                };
        }
}

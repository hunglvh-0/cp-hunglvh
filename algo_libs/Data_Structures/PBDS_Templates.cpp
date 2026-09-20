// Source: Local/Reconstructed

namespace PBDS_Templates
{
    using namespace __gnu_pbds;
    template <class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    template <class T>
    using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
    template <class K, class V, class H = hash<K>>
    using gp_hash = gp_hash_table<K, V, H>;
    struct PBDSExamples
    {
        ordered_set<int> os;
        ordered_multiset<int> oms;
        int timer = 0;
        void insertSet(int x)
    {
     os.insert(x); 
    }
        void eraseSet(int x)
    {
            auto it = os.find(x);
            if (it != os.end())
                os.erase(it);

    }
        int kthSet(int k) const
    {
            if (k < 0 or k >= (int)os.size())
                return -1;
            return *os.find_by_order(k);

    }
        int countLessSet(int x) const
    {
            return (int)os.order_of_key(x);

    }
        void insertMulti(int x)
    {
            oms.insert(
    {
    x, timer++
    }
    );

    }
        void eraseOneMulti(int x)
    {
            auto it = oms.lower_bound(
    {
    x, -1
    }
    );
            if (it != oms.end() and it->first == x)
                oms.erase(it);

    }
        int kthMulti(int k) const
    {
            if (k < 0 or k >= (int)oms.size())
                return -1;
            return oms.find_by_order(k)->first;

    }
        int countLessMulti(int x) const
    {
            return (int)oms.order_of_key(
    {
    x, -1
    }
    );

    }
    }
    ;
}

// Source: Local/Reconstructed

namespace KD_Tree
{
    template <int K, class T = long long>
    struct KDTree
    {
        struct Node
    {
            array<T, K> p
    {
    }
    , mn
    {
    }
    , mx
    {
    }
    ;
            int l = -1, r = -1, id = -1;

    }
    ;
        vector<Node> tr;
        vector<pair<array<T, K>, int>> pts;
        int root = -1;
        static long long sqDistPoint(const array<T, K> &a, const array<T, K> &b)
    {
            __int128 s = 0;
            for (int i = 0; i < K; ++i)
    {
                __int128 d = (__int128)a[i] - b[i];
                s += d * d;

    }
            return (long long)s;

    }
        void pull(int u)
    {
            for (int i = 0; i < K; ++i)
                tr[u].mn[i] = tr[u].mx[i] = tr[u].p[i];
            for (int v :
    {
    tr[u].l, tr[u].r
    }
    )

    {
                if (v == -1)
                    continue;
                for (int i = 0; i < K; ++i)
    {
                    tr[u].mn[i] = min(tr[u].mn[i], tr[v].mn[i]);
                    tr[u].mx[i] = max(tr[u].mx[i], tr[v].mx[i]);

    }

    }

    }
        int buildRec(int l, int r, int dep)
    {
            if (l > r)
                return -1;
            int m = (l + r) >> 1;
            int axis = dep % K;
            nth_element(pts.begin() + l, pts.begin() + m, pts.begin() + r + 1,
                        [&](const auto &A, const auto &B)

    {
     return A.first[axis] < B.first[axis]; 
    }
    );
            int u = (int)tr.size();
            tr.push_back(Node());
            tr[u].p = pts[m].first;
            tr[u].id = pts[m].second;
            tr[u].l = buildRec(l, m - 1, dep + 1);
            tr[u].r = buildRec(m + 1, r, dep + 1);
            pull(u);
            return u;

    }
        void build(const vector<array<T, K>> &a)
    {
            pts.clear();
            tr.clear();
            for (int i = 0; i < (int)a.size(); ++i)
                pts.push_back(
    {
    a[i], i
    }
    );
            if (pts.empty())
    {
                root = -1;
                return;

    }
            root = buildRec(0, (int)pts.size() - 1, 0);

    }
        long long boxDist(const array<T, K> &q, int u) const
    {
            if (u == -1)
                return (long long)4e18;
            __int128 s = 0;
            for (int i = 0; i < K; ++i)
    {
                if (q[i] < tr[u].mn[i])
    {
                    __int128 d = (__int128)tr[u].mn[i] - q[i];
                    s += d * d;

    }
    else if (q[i] > tr[u].mx[i])
    {
                    __int128 d = (__int128)q[i] - tr[u].mx[i];
                    s += d * d;

    }

    }
            return (long long)s;

    }
        void nearestRec(int u, const array<T, K> &q, pair<long long, int> &best) const
    {
            if (u == -1)
                return;
            long long d = sqDistPoint(tr[u].p, q);
            if (d < best.first or (d == best.first and tr[u].id < best.second))
    {
                best =
    {
    d, tr[u].id
    }
    ;

    }
            int L = tr[u].l, R = tr[u].r;
            long long dl = boxDist(q, L), dr = boxDist(q, R);
            if (dl > dr)
    {
                swap(dl, dr);
                swap(L, R);

    }
            if (L != -1 and dl <= best.first)
                nearestRec(L, q, best);
            if (R != -1 and dr <= best.first)
                nearestRec(R, q, best);

    }
        pair<long long, int> nearest(const array<T, K> &q) const
    {
            pair<long long, int> best =
    {
    (long long)4e18, -1
    }
    ;
            nearestRec(root, q, best);
            return best;

    }
    }
    ;
}

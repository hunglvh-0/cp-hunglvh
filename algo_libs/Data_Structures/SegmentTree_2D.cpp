// Source: https://cp-algorithms.com/data_structures/segment_tree.html#generalization-to-higher-dimensions

namespace SegmentTree_2D
{
    namespace SegmentTree2D
    {
        struct Node
    {
            int x1, y1, x2, y2;
            long long sum;
            Node *c1, *c2, *c3, *c4;
            Node(int _x1, int _y1, int _x2, int _y2)
    {
                x1 = _x1;
                y1 = _y1;
                x2 = _x2;
                y2 = _y2;
                sum = 0;
                c1 = c2 = c3 = c4 = nullptr;

    }

    }
    ;
        struct QuadSegTree
    {
            int n, m;
            Node *root;
            QuadSegTree(int _n = 0, int _m = 0)
    {
                init(_n, _m);

    }
            void init(int _n, int _m)
    {
                n = _n;
                m = _m;
                if (n > 0 and m > 0)
    {
                    root = new Node(1, 1, n, m);

    }
    else
    {
                    root = nullptr;

    }

    }
            void pull(Node *nd)
    {
                nd->sum = 0;
                if (nd->c1)
    {
                    nd->sum += nd->c1->sum;

    }
                if (nd->c2)
    {
                    nd->sum += nd->c2->sum;

    }
                if (nd->c3)
    {
                    nd->sum += nd->c3->sum;

    }
                if (nd->c4)
    {
                    nd->sum += nd->c4->sum;

    }

    }
            void ensure(Node *nd)
    {
                if (nd->x1 == nd->x2 and nd->y1 == nd->y2)
    {
                    return;

    }
                int mx = (nd->x1 + nd->x2) >> 1;
                int my = (nd->y1 + nd->y2) >> 1;
                if (!nd->c1 and nd->x1 <= mx and nd->y1 <= my)
    {
                    nd->c1 = new Node(nd->x1, nd->y1, mx, my);

    }
                if (!nd->c2 and nd->x1 <= mx and my + 1 <= nd->y2)
    {
                    nd->c2 = new Node(nd->x1, my + 1, mx, nd->y2);

    }
                if (!nd->c3 and mx + 1 <= nd->x2 and nd->y1 <= my)
    {
                    nd->c3 = new Node(mx + 1, nd->y1, nd->x2, my);

    }
                if (!nd->c4 and mx + 1 <= nd->x2 and my + 1 <= nd->y2)
    {
                    nd->c4 = new Node(mx + 1, my + 1, nd->x2, nd->y2);

    }

    }
            void point_add(Node *nd, int x, int y, long long v)
    {
                if (!nd)
    {
                    return;

    }
                if (nd->x1 == nd->x2 and nd->y1 == nd->y2)
    {
                    nd->sum += v;
                    return;

    }
                ensure(nd);
                int mx = (nd->x1 + nd->x2) >> 1;
                int my = (nd->y1 + nd->y2) >> 1;
                if (x <= mx)
    {
                    if (y <= my)
    {
                        point_add(nd->c1, x, y, v);

    }
    else
    {
                        point_add(nd->c2, x, y, v);

    }

    }
    else
    {
                    if (y <= my)
    {
                        point_add(nd->c3, x, y, v);

    }
    else
    {
                        point_add(nd->c4, x, y, v);

    }

    }
                pull(nd);

    }
            long long query(Node *nd, int x1, int y1, int x2, int y2) const
    {
                if (!nd)
    {
                    return 0;

    }
                if (x2 < nd->x1 or nd->x2 < x1 or y2 < nd->y1 or nd->y2 < y1)
    {
                    return 0;

    }
                if (x1 <= nd->x1 and nd->x2 <= x2 and y1 <= nd->y1 and nd->y2 <= y2)
    {
                    return nd->sum;

    }
                return query(nd->c1, x1, y1, x2, y2) + query(nd->c2, x1, y1, x2, y2) + query(nd->c3, x1, y1, x2, y2) + query(nd->c4, x1, y1, x2, y2);

    }
            void point_add(int x, int y, long long v)
    {
                point_add(root, x, y, v);

    }
            long long query(int x1, int y1, int x2, int y2) const
    {
                if (x1 > x2 or y1 > y2)
    {
                    return 0;

    }
                return query(root, x1, y1, x2, y2);

    }

    }
    ;
    }
}

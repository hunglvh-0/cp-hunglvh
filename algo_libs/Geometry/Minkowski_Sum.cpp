// Source: Local/Reconstructed

namespace Minkowski_Sum
{
    namespace geom_minkowski
    {
        const long double EPS = 1e-12L;
        struct Pt
    {
            long double x = 0, y = 0;
            Pt() = default;
            Pt(long double _x, long double _y) : x(_x), y(_y)
    {
    }
            Pt operator+(const Pt &o) const
    {
     return Pt(x + o.x, y + o.y); 
    }
            Pt operator-(const Pt &o) const
    {
     return Pt(x - o.x, y - o.y); 
    }

    }
    ;
        long double cross(Pt a, Pt b)
    {
     return a.x * b.y - a.y * b.x; 
    }
        int lowestPoint(const vector<Pt> &p)
    {
            int id = 0;
            for (int i = 1; i < (int)p.size(); ++i)
    {
                if (p[i].y < p[id].y - EPS or (fabsl(p[i].y - p[id].y) <= EPS and p[i].x < p[id].x))
                    id = i;

    }
            return id;

    }
        vector<Pt> rotateStart(const vector<Pt> &p)
    {
            if (p.empty())
                return p;
            int id = lowestPoint(p);
            vector<Pt> q;
            for (int i = 0; i < (int)p.size(); ++i)
                q.push_back(p[(id + i) % p.size()]);
            return q;

    }
        vector<Pt> convexMinkowskiSum(vector<Pt> A, vector<Pt> B)
    {
            if (A.empty() or B.empty())
                return
    {
    }
    ;
            A = rotateStart(A);
            B = rotateStart(B);
            int n = (int)A.size(), m = (int)B.size();
            A.push_back(A[0]);
            A.push_back(A[1]);
            B.push_back(B[0]);
            B.push_back(B[1]);
            vector<Pt> C;
            int i = 0, j = 0;
            while (i < n or j < m)
    {
                C.push_back(A[i] + B[j]);
                long double z = cross(A[i + 1] - A[i], B[j + 1] - B[j]);
                if (z >= -EPS and i < n)
                    ++i;
                if (z <= EPS and j < m)
                    ++j;

    }
            vector<Pt> R;
            for (auto p : C)
    {
                while ((int)R.size() >= 2)
    {
                    Pt a = R[(int)R.size() - 2], b = R.back();
                    if (fabsl(cross(b - a, p - b)) <= EPS)
                        R.pop_back();
                    else
                        break;

    }
                R.push_back(p);

    }
            if ((int)R.size() > 1 and fabsl(R.front().x - R.back().x) <= EPS and fabsl(R.front().y - R.back().y) <= EPS)
                R.pop_back();
            return R;

    }
    }
     // namespace geom_minkowski
}

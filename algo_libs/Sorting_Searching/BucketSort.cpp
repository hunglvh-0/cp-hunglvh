// Source: https://en.oi-wiki.org/basic/bucket-sort/

namespace BucketSort
{
        namespace BucketSort
        {
                vector<double> srt(const vector<double> &a)
                {
                        int n = (int)a.size();
                        if (n <= 1)
                        {
                                return a;
                        }
                        vector<vector<double>> b(n);
                        for (double x : a)
                        {
                                double y = x;
                                if (y < 0.0)
                                {
                                        y = 0.0;
                                }
                                if (y >= 1.0)
                                {
                                        y = nextafter(1.0, 0.0);
                                }
                                int id = (int)(y * n);
                                b[id].push_back(x);
                        }
                        vector<double> r;
                        r.reserve(n);
                        for (int i = 0; i < n; i++)
                        {
                                sort(b[i].begin(), b[i].end());
                                for (double x : b[i])
                                {
                                        r.push_back(x);
                                }
                        }
                        return r;
                }
        }
}

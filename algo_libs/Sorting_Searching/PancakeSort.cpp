// Source: https://en.wikipedia.org/wiki/Pancake_sorting

namespace PancakeSort
{
    namespace PancakeSort
    {
        void flp(vector<int> &a, int k)
        {
            int l = 0;
            int r = k - 1;
            while (l < r)
            {
                swap(a[l], a[r]);
                l++;
                r--;
            }
        }
        vector<int> ops(vector<int> &a)
        {
            int n = (int)a.size();
            vector<int> f;
            for (int s = n; s > 1; s--)
            {
                int m = 0;
                for (int i = 1; i < s; i++)
                {
                    if (a[i] > a[m])
                    {
                        m = i;
                    }
                }
                if (m == s - 1)
                {
                    continue;
                }
                if (m > 0)
                {
                    flp(a, m + 1);
                    f.push_back(m + 1);
                }
                flp(a, s);
                f.push_back(s);
            }
            return f;
        }
    }
}

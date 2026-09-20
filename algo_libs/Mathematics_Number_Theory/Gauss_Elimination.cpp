// Source: https://cp-algorithms.com/linear_algebra/linear-system-gauss.html

namespace Gauss_Elimination
{
        namespace GaussElimination
        {
                const double EPS = 1e-9;
                const int INF = 2;
                int gauss(vector<vector<double>> a, vector<double> &ans)
                {
                        int n = (int)a.size();
                        if (n == 0)
                        {
                                ans.clear();
                                return 1;
                        }
                        int m = (int)a[0].size() - 1;
                        vector<int> wh(m, -1);
                        for (int col = 0, row = 0; col < m and row < n; ++col)
                        {
                                int sel = row;
                                for (int i = row; i < n; ++i)
                                {
                                        if (fabs(a[i][col]) > fabs(a[sel][col]))
                                        {
                                                sel = i;
                                        }
                                }
                                if (fabs(a[sel][col]) < EPS)
                                {
                                        continue;
                                }
                                for (int j = col; j <= m; ++j)
                                {
                                        swap(a[sel][j], a[row][j]);
                                }
                                wh[col] = row;
                                for (int i = 0; i < n; ++i)
                                {
                                        if (i == row)
                                        {
                                                continue;
                                        }
                                        double c = a[i][col] / a[row][col];
                                        for (int j = col; j <= m; ++j)
                                        {
                                                a[i][j] -= a[row][j] * c;
                                        }
                                }
                                ++row;
                        }
                        ans.assign(m, 0.0);
                        for (int i = 0; i < m; ++i)
                        {
                                if (wh[i] != -1)
                                {
                                        ans[i] = a[wh[i]][m] / a[wh[i]][i];
                                }
                        }
                        for (int i = 0; i < n; ++i)
                        {
                                double s = 0;
                                for (int j = 0; j < m; ++j)
                                {
                                        s += ans[j] * a[i][j];
                                }
                                if (fabs(s - a[i][m]) > EPS)
                                {
                                        return 0;
                                }
                        }
                        for (int i = 0; i < m; ++i)
                        {
                                if (wh[i] == -1)
                                {
                                        return INF;
                                }
                        }
                        return 1;
                }
        }
}

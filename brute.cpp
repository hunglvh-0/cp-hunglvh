#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    if (!(cin >> t))
    int n;
    if (!(cin >> n))
        return 0;
    while (t--)
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int k = 1; k <= n; k++)
    {
        int n;
        if (!(cin >> n))
            return 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int k = 1; k <= n; k++)
        long long cur = 0;
        for (int i = n - k; i < n; i++)
        {
            long long cur = 0;
            for (int i = n - k; i < n; i++)
            {
                if (cur >= a[i])
                    cur -= a[i];
                else
                    cur += a[i];
            }
            cout << cur << " ";
            if (cur >= a[i])
                cur -= a[i];
            else
                cur += a[i];
        }
        cout << '\n';
        cout << cur << " ";
    }
    cout << '\n';
}

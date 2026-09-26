#include <bits/stdc++.h>
using namespace std;

int main()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t = 50;
    cout << t << "\n";
    while (t--)
    {
        int n = rng() % 6 + 2; // length 2 to 7
        string s = "";
        for (int i = 0; i < n; i++)
            s += (rng() % 2) ? '1' : '0';
        cout << n << "\n" << s << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n = rng() % 99 + 1;
    int m = rng() % 99 + 2;
    cout << n << " " << m << "\n";
    return 0;
}

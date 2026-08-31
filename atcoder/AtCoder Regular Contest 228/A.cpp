#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;
#define ll long long
#define ld long double
using u64 = uint64_t;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define el '\n'
#define f first
#define s second
#define arr(a, n)                                                              \
    for (int i = 0; i < n; i++)                                                \
        cin >> a[i];
#define fast                                                                   \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define TIME()                                                                 \
    cerr << endl                                                               \
         << "Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << " ms." << endl
#define i128 __int128
const ll INF = 1e18;
const ll MOD = 998244353;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
ll gcd(ll a, ll b) { return std::gcd(a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow_mod(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll fact[1005], invf[1005];
void pre()
{
    fact[0] = 1;
    invf[0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        invf[i] = pow_mod(fact[i], MOD - 2);
    }
}
ll ncr(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
}
ll prob[505][505];
ll nxtp[505][505];
ll dp[505][505];
ll nxtdp[505][505];

inline void solve()
{
    pre();
    int n, m;
    if (!(cin >> n >> m))
        return;
    vi p(n), q(n);
    arr(p, n);
    arr(q, n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            prob[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    vi posp(n + 1);
    for (int i = 0; i < n; i++)
    {
        posp[p[i]] = i;
    }
    vi pi(n);
    for (int i = 0; i < n; i++)
    {
        pi[i] = posp[q[i]];
    }
    vi vis(n, 0);
    vi cycles;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int curr = i;
            int len = 0;
            while (!vis[curr])
            {
                vis[curr] = 1;
                curr = pi[curr];
                len++;
            }
            cycles.pb(len);
        }
    }
    dp[0][0] = 1;
    int curn = 0;
    for (int l : cycles)
    {
        for (int k = 0; k <= curn + l; k++)
        {
            for (int c = 0; c <= curn + l; c++)
            {
                nxtdp[k][c] = 0;
            }
        }
        for (int a = 0; a <= l; a++)
        {
            for (int b = 0; b <= min(a, l - a); b++)
            {
                ll w = 0;
                if (a == 0 && b == 0)
                {
                    w = 1;
                }
                else if (a == l && b == 0)
                {
                    w = 1;
                }
                else if (b > 0)
                {
                    w = (ncr(l - a, b) * ncr(a - 1, b - 1) % MOD + ncr(l - a - 1, b - 1) * ncr(a, b) % MOD) % MOD;
                }
                if (!w)
                    continue;
                for (int k = 0; k <= curn; k++)
                {
                    for (int c = 0; c <= min(k, curn - k); c++)
                    {
                        if (dp[k][c])
                        {
                            nxtdp[k + a][c + b] = (nxtdp[k + a][c + b] + dp[k][c] * w) % MOD;
                        }
                    }
                }
            }
        }
        curn += l;
        for (int k = 0; k <= curn; k++)
        {
            for (int c = 0; c <= min(k, curn - k); c++)
            {
                dp[k][c] = nxtdp[k][c];
            }
        }
    }
    prob[n][0] = 1;
    for (int step = 0; step < m; step++)
    {
        for (int k = 0; k <= n; k++)
        {
            int maxc = min(k, n - k);
            for (int c = 0; c <= maxc; c++)
            {
                nxtp[k][c] = 0;
            }
        }
        for (int k = 0; k <= n; k++)
        {
            int maxc = min(k, n - k);
            for (int c = 0; c <= maxc; c++)
            {
                ll v = prob[k][c];
                if (!v)
                    continue;
                if (k > 0)
                {
                    nxtp[k - 1][c] = (nxtp[k - 1][c] + v * (k - c)) % MOD;
                }
                if (k < n)
                {
                    nxtp[k + 1][c] = (nxtp[k + 1][c] + v * (n - k - c)) % MOD;
                }
                nxtp[k][c] = (nxtp[k][c] + v * (2 * c)) % MOD;
                if (c > 0)
                {
                    nxtp[k][c - 1] = (nxtp[k][c - 1] + v * 2 * c * c) % MOD;
                }
                if (k - c > 0 && n - k - c > 0)
                {
                    nxtp[k][c + 1] = (nxtp[k][c + 1] + v * (2LL * (k - c) * (n - k - c) % MOD)) % MOD;
                }
                ll same = 1LL * k * (k - 1) + 1LL * (n - k) * (n - k - 1) + 2LL * c * n - 4LL * c * c;
                same %= MOD;
                if (same < 0)
                {
                    same += MOD;
                }
                nxtp[k][c] = (nxtp[k][c] + v * same) % MOD;
            }
        }
        for (int k = 0; k <= n; k++)
        {
            int maxc = min(k, n - k);
            for (int c = 0; c <= maxc; c++)
            {
                prob[k][c] = nxtp[k][c];
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= n; k++)
    {
        for (int c = 0; c <= min(k, n - k); c++)
        {
            if (!dp[k][c] || !prob[k][c])
                continue;
            ll num = prob[k][c];
            ll ways = dp[k][c];
            ll denom = 1;
            denom = (denom * ncr(n, c)) % MOD;
            denom = (denom * ncr(n - c, k - c)) % MOD;
            denom = (denom * ncr(n - k, n - k - c)) % MOD;
            ll invd = pow_mod(denom, MOD - 2);
            ll term = (num * ways) % MOD;
            term = (term * invd) % MOD;
            ans = (ans + term) % MOD;
        }
    }
    cout << ans << el;
}
int32_t main()
{
    fast;
#define file "main"
    if (fopen(file ".INP", "r"))
    {
        freopen(file ".INP", "r", stdin);
        freopen(file ".OUT", "w", stdout);
    }
    solve();
    TIME();
    return 0;
}


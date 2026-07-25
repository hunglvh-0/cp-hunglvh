#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using i128 = __int128;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define bk back()
#define fr front()
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRAV(a, x) for (auto &a : x)
#define bit(x, i) (((x) >> (i)) & 1)
#define mask(i) (1LL << (i))
#define turn_on(x, i) ((x) | mask(i))
#define turn_off(x, i) ((x) & ~mask(i))
#define flip(x, i) ((x) ^ mask(i))
#define cnt_bit(x) __builtin_popcountll(x)
#define lg(x) (63 - __builtin_clzll(x))
#define ctz(x) __builtin_ctzll(x)
#define ms(a, x) memset(a, x, sizeof(a))
#define mc(a, b) memcpy(a, b, sizeof(b))
#define uni(v) v.resize(unique(all(v)) - v.begin())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl '\n'
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a - 1; i >= b; --i)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 998244353;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

string to_string_i128(i128 x)
{
    if (x == 0)
        return "0";
    bool neg = (x < 0);
    if (neg)
        x = -x;
    string s;
    while (x > 0)
    {
        s.push_back(char('0' + int(x % 10)));
        x /= 10;
    }
    if (neg)
        s.push_back('-');
    reverse(all(s));
    return s;
}

void read_i128(i128 &x)
{
    string s;
    cin >> s;
    int p = 0;
    bool neg = 0;
    if (!s.empty() && s[0] == '-')
    {
        neg = 1;
        p = 1;
    }
    x = 0;
    for (; p < sz(s); ++p)
        x = x * 10 + (s[p] - '0');
    if (neg)
        x = -x;
}

template <class T>
void in_one(T &x) { cin >> x; }
void in_one(i128 &x) { read_i128(x); }
template <class A, class B>
void in_one(pair<A, B> &p)
{
    in_one(p.fi);
    in_one(p.se);
}
template <class T>
void in_one(vector<T> &a)
{
    TRAV(x, a)
    in_one(x);
}
template <class T, size_t N>
void in_one(array<T, N> &a)
{
    TRAV(x, a)
    in_one(x);
}
template <class... Ts>
void in(Ts &...xs) { (in_one(xs), ...); }

template <class T>
void out_one(const T &x) { cout << x; }
void out_one(const i128 &x) { cout << to_string_i128(x); }
template <class A, class B>
void out_one(const pair<A, B> &p)
{
    out_one(p.fi);
    cout << ' ';
    out_one(p.se);
}
template <class T>
void out_one(const vector<T> &a)
{
    REP(i, sz(a))
    {
        if (i)
            cout << ' ';
        out_one(a[i]);
    }
}
template <class T, size_t N>
void out_one(const array<T, N> &a)
{
    REP(i, (int)N)
    {
        if (i)
            cout << ' ';
        out_one(a[i]);
    }
}

template <class... Ts>
void print(const Ts &...xs)
{
    int c = 0;
    ((c++ ? cout << ' ' : cout, out_one(xs)), ...);
}

template <class... Ts>
void println(const Ts &...xs)
{
    print(xs...);
    cout << nl;
}

template <class... Ts>
void print_flush(const Ts &...xs)
{
    println(xs...);
    cout.flush();
}

template <class T>
vector<T> read_vec(int n)
{
    vector<T> a(n);
    in(a);
    return a;
}

template <class T>
void in1(vector<T> &a)
{
    for (int i = 1; i < sz(a); ++i)
        in(a[i]);
}

template <class T>
void print1(const vector<T> &a)
{
    for (int i = 1; i < sz(a); ++i)
    {
        if (i > 1)
            cout << ' ';
        out_one(a[i]);
    }
    cout << nl;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rng_ll(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
int rng_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T>
void sort_unique(vector<T> &v)
{
    sort(all(v));
    uni(v);
}

template <class T>
vector<T> pref_sum(const vector<T> &a)
{
    vector<T> pref(sz(a) + 1, 0);
    REP(i, sz(a))
    pref[i + 1] = pref[i] + a[i];
    return pref;
}

template <class F>
int fst_true(int l, int r, F f)
{
    int ans = r + 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (f(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

template <class F>
int lst_true(int l, int r, F f)
{
    int ans = l - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (f(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}

vvi read_graph(int n, int m, bool undirected = 1)
{
    vvi g(n + 1);
    REP(i, m)
    {
        int u, v;
        in(u, v);
        g[u].pb(v);
        if (undirected)
            g[v].pb(u);
    }
    return g;
}

template <class T>
vector<vector<T>> read_matrix(int n, int m)
{
    vector<vector<T>> a(n, vector<T>(m));
    REP(i, n)
    REP(j, m)
    in(a[i][j]);
    return a;
}

#ifdef LOCAL
void _dbg() { cerr << nl; }
template <class H, class... T>
void _dbg(H &&h, T &&...t)
{
    cerr << h;
    if (sizeof...(t))
        cerr << " | ";
    _dbg(forward<T>(t)...);
}
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "] = ", _dbg(__VA_ARGS__)
#else
#define dbg(...)
#endif

template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
ll binpow(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll m = MOD) { return binpow(a, m - 2, m); }

struct Comb
{
    int n;
    vll f, iv;
    Comb(int n) : n(n), f(n + 1), iv(n + 1)
    {
        f[0] = 1;
        FOR(i, 1, n)
        f[i] = f[i - 1] * i % MOD;
        iv[n] = inv(f[n]);
        ROF(i, n - 1, 0)
        iv[i] = iv[i + 1] * (i + 1) % MOD;
    }
    ll ncr(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        return f[n] * iv[k] % MOD * iv[n - k] % MOD;
    }
};
struct DSU
{
    vi p, sz;
    DSU(int n)
    {
        p.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        iota(all(p), 0);
    }
    int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
    bool unite(int i, int j)
    {
        int x = find(i), y = find(j);
        if (x != y)
        {
            if (sz[x] < sz[y])
                swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
            return 1;
        }
        return 0;
    }
};
struct Fenwick
{
    int n;
    vll t;
    Fenwick(int n) : n(n), t(n + 1, 0) {}
    void upd(int i, ll v)
    {
        for (; i <= n; i += i & -i)
            t[i] += v;
    }
    ll qry(int i)
    {
        ll r = 0;
        for (; i > 0; i -= i & -i)
            r += t[i];
        return r;
    }
};
struct ST
{
    int n;
    vll t, lz;
    ST(int n) : n(n), t(4 * n + 1, 0), lz(4 * n + 1, 0) {}
    void ps(int v, int tl, int tr)
    {
        if (lz[v] != 0)
        {
            t[v] += lz[v];
            if (tl != tr)
            {
                lz[2 * v] += lz[v];
                lz[2 * v + 1] += lz[v];
            }
            lz[v] = 0;
        }
    }
    void upd(int v, int tl, int tr, int l, int r, ll x)
    {
        ps(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            lz[v] += x;
            ps(v, tl, tr);
        }
        else
        {
            int tm = (tl + tr) / 2;
            upd(2 * v, tl, tm, l, min(r, tm), x);
            upd(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, x);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }
    ll qry(int v, int tl, int tr, int l, int r)
    {
        ps(v, tl, tr);
        if (l > r)
            return -LINF;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return max(qry(2 * v, tl, tm, l, min(r, tm)), qry(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};
struct Treap
{
    struct nd
    {
        int ls, rs, v, pr, sz;
        ll sm;
    };
    vector<nd> t;
    int rt, id;
    Treap(int n) : t(n + 1), rt(0), id(0) {}
    int nn(int v)
    {
        t[++id] = {0, 0, v, rand(), 1, v};
        return id;
    }
    void upd(int u)
    {
        if (u)
        {
            t[u].sz = 1 + t[t[u].ls].sz + t[t[u].rs].sz;
            t[u].sm = t[u].v + t[t[u].ls].sm + t[t[u].rs].sm;
        }
    }
    void sp(int u, int k, int &l, int &r)
    {
        if (!u)
        {
            l = r = 0;
            return;
        }
        int c = 1 + t[t[u].ls].sz;
        if (k >= c)
        {
            sp(t[u].rs, k - c, t[u].rs, r);
            l = u;
        }
        else
        {
            sp(t[u].ls, k, l, t[u].ls);
            r = u;
        }
        upd(u);
    }
    int mg(int l, int r)
    {
        if (!l || !r)
            return l ? l : r;
        if (t[l].pr > t[r].pr)
        {
            t[l].rs = mg(t[l].rs, r);
            upd(l);
            return l;
        }
        else
        {
            t[r].ls = mg(l, t[r].ls);
            upd(r);
            return r;
        }
    }
};
struct NTT
{
    void ntt(vll &a, bool in)
    {
        int n = sz(a);
        for (int i = 1, j = 0; i < n; i++)
        {
            int b = n >> 1;
            for (; j & b; b >>= 1)
                j ^= b;
            j ^= b;
            if (i < j)
                swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1)
        {
            ll w = binpow(3, (MOD - 1) / len);
            if (in)
                w = inv(w);
            for (int i = 0; i < n; i += len)
            {
                ll cur = 1;
                for (int j = 0; j < len / 2; j++)
                {
                    ll u = a[i + j], v = a[i + j + len / 2] * cur % MOD;
                    a[i + j] = (u + v) % MOD;
                    a[i + j + len / 2] = (u - v + MOD) % MOD;
                    cur = cur * w % MOD;
                }
            }
        }
        if (in)
        {
            ll in_n = inv(n);
            TRAV(x, a)
            x = x * in_n % MOD;
        }
    }
    vll mul(vll const &a, vll const &b)
    {
        vll fa(all(a)), fb(all(b));
        int n = 1;
        while (n < sz(a) + sz(b))
            n <<= 1;
        fa.resize(n);
        fb.resize(n);
        ntt(fa, 0);
        ntt(fb, 0);
        REP(i, n)
        fa[i] = fa[i] * fb[i] % MOD;
        ntt(fa, 1);
        return fa;
    }
};
struct HLD
{
    int n, ti;
    vi p, d, hv, hd, ps;
    HLD(int n, int rt, vvi &adj) : n(n), ti(0)
    {
        p.assign(n + 1, 0);
        d.assign(n + 1, 0);
        hv.assign(n + 1, 0);
        hd.assign(n + 1, 0);
        ps.assign(n + 1, 0);
        ds(rt, rt, adj);
        hd[rt] = rt;
        dl(rt, rt, adj);
    }
    int ds(int u, int pr, vvi &adj)
    {
        int s = 1, ms = 0;
        p[u] = pr;
        TRAV(v, adj[u])
        {
            if (v != pr)
            {
                d[v] = d[u] + 1;
                int cs = ds(v, u, adj);
                s += cs;
                if (cs > ms)
                {
                    ms = cs;
                    hv[u] = v;
                }
            }
        }
        return s;
    }
    void dl(int u, int pr, vvi &adj)
    {
        ps[u] = ++ti;
        if (hv[u] != 0)
        {
            hd[hv[u]] = hd[u];
            dl(hv[u], u, adj);
        }
        TRAV(v, adj[u])
        {
            if (v != pr && v != hv[u])
            {
                hd[v] = v;
                dl(v, u, adj);
            }
        }
    }
};
struct SCC
{
    int n, ti, sc;
    vi df, lw, cp, st;
    vector<bool> in;
    SCC(int n, vvi &adj) : n(n), ti(0), sc(0)
    {
        df.assign(n + 1, 0);
        lw.assign(n + 1, 0);
        cp.assign(n + 1, 0);
        in.assign(n + 1, 0);
        FOR(i, 1, n)
        {
            if (!df[i])
                dfs(i, adj);
        }
    }
    void dfs(int u, vvi &adj)
    {
        df[u] = lw[u] = ++ti;
        st.pb(u);
        in[u] = 1;
        TRAV(v, adj[u])
        {
            if (!df[v])
            {
                dfs(v, adj);
                chmin(lw[u], lw[v]);
            }
            else if (in[v])
            {
                chmin(lw[u], df[v]);
            }
        }
        if (lw[u] == df[u])
        {
            sc++;
            while (1)
            {
                int v = st.bk;
                st.pop_back();
                in[v] = 0;
                cp[v] = sc;
                if (u == v)
                    break;
            }
        }
    }
};
struct MCMF
{
    struct E
    {
        int v;
        ll f, c, w;
        int id;
    };
    int n, s, t;
    vector<vector<E>> adj;
    vll d;
    vi p, pe;
    vector<bool> in;
    MCMF(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.assign(n + 1, vector<E>());
        d.assign(n + 1, 0);
        p.assign(n + 1, 0);
        pe.assign(n + 1, 0);
        in.assign(n + 1, 0);
    }
    void add(int u, int v, ll c, ll w)
    {
        adj[u].pb({v, 0, c, w, sz(adj[v])});
        adj[v].pb({u, 0, 0, -w, sz(adj[u]) - 1});
    }
    bool sp()
    {
        fill(all(d), LINF);
        fill(all(in), 0);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        in[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            in[u] = 0;
            REP(i, sz(adj[u]))
            {
                auto &e = adj[u][i];
                if (e.f < e.c && d[e.v] > d[u] + e.w)
                {
                    d[e.v] = d[u] + e.w;
                    p[e.v] = u;
                    pe[e.v] = i;
                    if (!in[e.v])
                    {
                        q.push(e.v);
                        in[e.v] = 1;
                    }
                }
            }
        }
        return d[t] != LINF;
    }
    pll flow()
    {
        ll f = 0, c = 0;
        while (sp())
        {
            ll pu = LINF;
            int cu = t;
            while (cu != s)
            {
                pu = min(pu, adj[p[cu]][pe[cu]].c - adj[p[cu]][pe[cu]].f);
                cu = p[cu];
            }
            f += pu;
            c += pu * d[t];
            cu = t;
            while (cu != s)
            {
                adj[p[cu]][pe[cu]].f += pu;
                adj[cu][adj[p[cu]][pe[cu]].id].f -= pu;
                cu = p[cu];
            }
        }
        return {f, c};
    }
};
struct SAM
{
    struct st
    {
        int len, lk;
        map<char, int> nx;
    };
    vector<st> a;
    int ls;
    SAM()
    {
        a.push_back({0, -1, {}});
        ls = 0;
    }
    void ext(char c)
    {
        int cr = sz(a);
        a.push_back({a[ls].len + 1, 0, {}});
        int p = ls;
        while (p != -1 && !a[p].nx.count(c))
        {
            a[p].nx[c] = cr;
            p = a[p].lk;
        }
        if (p == -1)
        {
            a[cr].lk = 0;
        }
        else
        {
            int q = a[p].nx[c];
            if (a[p].len + 1 == a[q].len)
            {
                a[cr].lk = q;
            }
            else
            {
                int cl = sz(a);
                a.push_back({a[p].len + 1, a[q].lk, a[q].nx});
                while (p != -1 && a[p].nx[c] == q)
                {
                    a[p].nx[c] = cl;
                    p = a[p].lk;
                }
                a[q].lk = a[cr].lk = cl;
            }
        }
        ls = cr;
    }
};
struct Pt
{
    ll x, y;
    Pt() : x(0), y(0) {}
    Pt(ll x, ll y) : x(x), y(y) {}
    Pt operator-(const Pt &o) const { return Pt(x - o.x, y - o.y); }
    ll cr(const Pt &o) const { return x * o.y - y * o.x; }
    bool operator<(const Pt &o) const { return x < o.x || (x == o.x && y < o.y); }
};
vector<Pt> ch(vector<Pt> &a)
{
    int n = sz(a), k = 0;
    if (n <= 2)
        return a;
    vector<Pt> r(2 * n);
    sort(all(a));
    REP(i, n)
    {
        while (k >= 2 && (r[k - 1] - r[k - 2]).cr(a[i] - r[k - 2]) <= 0)
            k--;
        r[k++] = a[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && (r[k - 1] - r[k - 2]).cr(a[i] - r[k - 2]) <= 0)
            k--;
        r[k++] = a[i];
    }
    if (k > 0)
        r.resize(k - 1);
    else
        r.clear();
    return r;
}
struct KMP
{
    vi pi;
    KMP(string s)
    {
        int n = sz(s);
        pi.assign(n, 0);
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
    }
};
struct ZFunc
{
    vi z;
    ZFunc(string s)
    {
        int n = sz(s);
        z.assign(n, 0);
        for (int i = 1, l = 0, r = 0; i < n; i++)
        {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
    }
};
struct Dinic
{
    struct E
    {
        int v;
        ll cap, flow;
        int rev;
    };
    vvi adj;
    vector<E> edges;
    vi d, ptr;
    int n, s, t;
    Dinic(int n, int s, int t) : n(n), s(s), t(t), adj(n + 1), d(n + 1), ptr(n + 1) {}
    void add(int u, int v, ll c)
    {
        adj[u].pb(sz(edges));
        edges.pb({v, c, 0, sz(edges) + 1});
        adj[v].pb(sz(edges));
        edges.pb({u, 0, 0, sz(edges) - 1});
    }
    bool bfs()
    {
        fill(all(d), -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            TRAV(id, adj[u])
            {
                auto &e = edges[id];
                if (d[e.v] == -1 && e.flow < e.cap)
                {
                    d[e.v] = d[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[t] != -1;
    }
    ll dfs(int u, ll pushed)
    {
        if (u == t || !pushed)
            return pushed;
        for (int &cid = ptr[u]; cid < sz(adj[u]); ++cid)
        {
            auto &e = edges[adj[u][cid]];
            ll tr;
            if (d[u] + 1 != d[e.v] || !(tr = dfs(e.v, min(pushed, e.cap - e.flow))))
                continue;
            e.flow += tr;
            edges[e.rev].flow -= tr;
            return tr;
        }
        return 0;
    }
    ll flow()
    {
        ll f = 0;
        while (bfs())
        {
            fill(all(ptr), 0);
            while (ll pushed = dfs(s, LINF))
                f += pushed;
        }
        return f;
    }
};
template <int AL = 26, char base = 'a'>
struct Aho
{
    struct Node
    {
        int nx[AL], link, out;
        Node()
        {
            ms(nx, -1);
            link = out = 0;
        }
    };
    vector<Node> t;
    Aho() { t.eb(); }
    void add(string s, int id)
    {
        int u = 0;
        TRAV(c, s)
        {
            int ch = c - base;
            if (t[u].nx[ch] == -1)
            {
                t[u].nx[ch] = sz(t);
                t.eb();
            }
            u = t[u].nx[ch];
        }
        t[u].out += id;
    }
    void build()
    {
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            REP(c, AL)
            {
                int v = t[u].nx[c];
                if (v != -1)
                {
                    t[v].link = (u == 0) ? 0 : t[t[u].link].nx[c];
                    t[v].out += t[t[v].link].out;
                    q.push(v);
                }
                else
                    t[u].nx[c] = (u == 0) ? 0 : t[t[u].link].nx[c];
            }
        }
    }
};
template <int MAX>
struct Sieve
{
    vi p, pr;
    Sieve() : p(MAX + 1, 1)
    {
        p[0] = p[1] = 0;
        for (int i = 2; i <= MAX; i++)
        {
            if (p[i])
                pr.pb(i);
            for (int j = 0; j < sz(pr) && i * pr[j] <= MAX; j++)
            {
                p[i * pr[j]] = 0;
                if (i % pr[j] == 0)
                    break;
            }
        }
    }
};

const int MAX_S = 500005;
const int LOG = 19;
int s[MAX_S];
int offset[MAX_S];
vector<pair<int, int>> segs[MAX_S];
int up_L[LOG][MAX_S];
int up_R[LOG][MAX_S];
int Down[MAX_S];
int Up[MAX_S];
ll bit_arr[MAX_S + 2];
int seg_len[MAX_S];

struct Query {
    int a, b, c, l, r;
    int id;
};

void bit_add(int S_tot, int idx, ll val) {
    for(; idx <= S_tot; idx += idx & -idx) bit_arr[idx] += val;
}

ll bit_query(int idx) {
    ll sum = 0;
    for(; idx > 0; idx -= idx & -idx) sum += bit_arr[idx];
    return sum;
}

int L_arr[MAX_S];
int R_arr[MAX_S];

int Val_L(int anc) {
    if (anc < 0) return -anc - 1;
    return L_arr[anc];
}

int Val_R(int anc) {
    if (anc < 0) return -anc - 1;
    return R_arr[anc];
}

int jump_L(int u, int steps) {
    for(int k = 18; k >= 0; --k) {
        if((steps >> k) & 1) {
            if(u < 0) break;
            u = up_L[k][u];
        }
    }
    return u;
}

int jump_R(int u, int steps) {
    for(int k = 18; k >= 0; --k) {
        if((steps >> k) & 1) {
            if(u < 0) break;
            u = up_R[k][u];
        }
    }
    return u;
}

void solve()
{
    int n, m;
    if (scanf("%d%d", &n, &m) != 2) return;
    int S_tot = 0;
    for (int i = 0; i < n; ++i) {
        offset[i] = S_tot;
        int si; scanf("%d", &si);
        s[i] = si;
        segs[i].push_back({-1, -1});
        for (int j = 1; j <= si; ++j) {
            int l, r; scanf("%d%d", &l, &r);
            segs[i].push_back({l, r});
            seg_len[S_tot + j] = r - l;
            L_arr[S_tot + j] = l;
            R_arr[S_tot + j] = r;
            Down[S_tot + j] = i;
            Up[S_tot + j] = i;
        }
        S_tot += si;
    }

    for (int i = n - 2; i >= 0; --i) {
        int pt = 1;
        for (int u = 1; u <= s[i]; ++u) {
            int L_u = segs[i][u].first;
            int R_u = segs[i][u].second;
            while (pt <= s[i+1] && segs[i+1][pt].second <= L_u) pt++;
            int temp = pt;
            while (temp <= s[i+1] && segs[i+1][temp].first < R_u) {
                Down[offset[i] + u] = max(Down[offset[i] + u], Down[offset[i+1] + temp]);
                temp++;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        int pt = 1;
        for (int u = 1; u <= s[i]; ++u) {
            int L_u = segs[i][u].first;
            int R_u = segs[i][u].second;
            while (pt <= s[i-1] && segs[i-1][pt].second <= L_u) pt++;
            int temp = pt;
            while (temp <= s[i-1] && segs[i-1][temp].first < R_u) {
                Up[offset[i] + u] = min(Up[offset[i] + u], Up[offset[i-1] + temp]);
                temp++;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= s[i]; ++j) {
            int u = offset[i] + j;
            int L_u = segs[i][j].first;
            int R_u = segs[i][j].second;

            int low = 1, high = s[i-1], ans_L = s[i-1] + 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (segs[i-1][mid].second > L_u) {
                    ans_L = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (ans_L <= s[i-1] && segs[i-1][ans_L].first < R_u) {
                up_L[0][u] = offset[i-1] + ans_L;
            } else {
                up_L[0][u] = -L_u - 1;
            }

            low = 1; high = s[i-1]; int ans_R = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (segs[i-1][mid].first < R_u) {
                    ans_R = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (ans_R >= 1 && segs[i-1][ans_R].second > L_u) {
                up_R[0][u] = offset[i-1] + ans_R;
            } else {
                up_R[0][u] = -(R_u - 1) - 1;
            }
        }
    }

    for (int k = 1; k <= 18; ++k) {
        for (int u = 1; u <= S_tot; ++u) {
            int pL = up_L[k-1][u];
            if (pL < 0) up_L[k][u] = pL;
            else up_L[k][u] = up_L[k-1][pL];

            int pR = up_R[k-1][u];
            if (pR < 0) up_R[k][u] = pR;
            else up_R[k][u] = up_R[k-1][pR];
        }
    }

    int q; scanf("%d", &q);
    vector<Query> queries(q);
    vector<vector<int>> queries_by_a(n);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d%d", &queries[i].a, &queries[i].b, &queries[i].c, &queries[i].l, &queries[i].r);
        queries[i].id = i;
        queries_by_a[queries[i].a].push_back(i);
    }

    vector<vector<int>> segs_by_up(n);
    for (int u = 1; u <= S_tot; ++u) {
        segs_by_up[Up[u]].push_back(u);
    }

    vector<ll> final_ans(q, 0);
    for (int a = 0; a < n; ++a) {
        for (int u : segs_by_up[a]) {
            bit_add(S_tot, u, seg_len[u]);
        }
        for (int q_id : queries_by_a[a]) {
            int b = queries[q_id].b;
            int c = queries[q_id].c;
            int l = queries[q_id].l;
            int r_coord = queries[q_id].r;

            int S_0_j = 0;
            int low_s = 1, high_s = s[a];
            while (low_s <= high_s) {
                int mid = (low_s + high_s) / 2;
                if (segs[a][mid].second > b) {
                    S_0_j = mid;
                    high_s = mid - 1;
                } else {
                    low_s = mid + 1;
                }
            }
            if (S_0_j > s[a] || segs[a][S_0_j].first > b) {
                S_0_j = 0;
            }

            if (S_0_j == 0 || Down[offset[a] + S_0_j] < c) {
                final_ans[q_id] = 0;
                continue;
            }

            int idx_L = s[c] + 1;
            int low_L = 1, high_L = s[c];
            while (low_L <= high_L) {
                int mid = (low_L + high_L) / 2;
                if (segs[c][mid].second > l) {
                    idx_L = mid;
                    high_L = mid - 1;
                } else {
                    low_L = mid + 1;
                }
            }
            int idx_R = 0;
            if (idx_L <= s[c] && segs[c][idx_L].first <= r_coord) {
                int low_R = 1, high_R = s[c];
                while (low_R <= high_R) {
                    int mid = (low_R + high_R) / 2;
                    if (segs[c][mid].first <= r_coord) {
                        idx_R = mid;
                        low_R = mid + 1;
                    } else {
                        high_R = mid - 1;
                    }
                }
            } else {
                idx_L = s[c] + 1;
                idx_R = 0;
            }

            int S_0_L = segs[a][S_0_j].first;
            int S_0_R = segs[a][S_0_j].second;

            int X_min = s[c] + 1;
            int low_min = 1, high_min = s[c];
            while (low_min <= high_min) {
                int mid = (low_min + high_min) / 2;
                int anc = jump_R(offset[c] + mid, c - a);
                if (Val_R(anc) > S_0_L) {
                    X_min = mid;
                    high_min = mid - 1;
                } else {
                    low_min = mid + 1;
                }
            }

            int X_max = 0;
            int low_max = 1, high_max = s[c];
            while (low_max <= high_max) {
                int mid = (low_max + high_max) / 2;
                int anc = jump_L(offset[c] + mid, c - a);
                if (Val_L(anc) < S_0_R) {
                    X_max = mid;
                    low_max = mid + 1;
                } else {
                    high_max = mid - 1;
                }
            }

            int A = max(X_min, idx_L);
            int B = min(X_max, idx_R);
            ll ans = 0;
            if (A <= B) {
                if (A == B) {
                    if (Up[offset[c] + A] <= a) {
                        ans += max(0LL, (ll)min(r_coord, segs[c][A].second - 1) - max(l, segs[c][A].first) + 1);
                    }
                } else {
                    if (Up[offset[c] + A] <= a) {
                        ans += max(0LL, (ll)min(r_coord, segs[c][A].second - 1) - max(l, segs[c][A].first) + 1);
                    }
                    if (Up[offset[c] + B] <= a) {
                        ans += max(0LL, (ll)min(r_coord, segs[c][B].second - 1) - max(l, segs[c][B].first) + 1);
                    }
                    if (A + 1 <= B - 1) {
                        ans += bit_query(offset[c] + B - 1) - bit_query(offset[c] + A);
                    }
                }
            }
            final_ans[q_id] = ans;
        }
    }

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", final_ans[i]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

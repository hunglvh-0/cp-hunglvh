// Source: https://en.oi-wiki.org/misc/cdq-divide/

namespace CDQ_DivideAndConquer
{
        namespace CDQDivideAndConquer
        {
                struct Nd
                {
                        int a;
                        int b;
                        int c;
                        int w;
                        int g;
                        ll an;
                };
                struct Bit
                {
                        int n;
                        vector<int> t;
                        Bit()
                        {
                                n = 0;
                        }
                        Bit(int n_)
                        {
                                init(n_);
                        }
                        void init(int n_)
                        {
                                n = n_;
                                t.assign(n + 1, 0);
                        }
                        void add(int i, int v)
                        {
                                for (; i <= n; i += i & -i)
                                {
                                        t[i] += v;
                                }
                        }
                        int sum(int i)
                        {
                                int s = 0;
                                for (; i > 0; i -= i & -i)
                                {
                                        s += t[i];
                                }
                                return s;
                        }
                };
                vector<Nd> p;
                vector<Nd> q;
                Bit fw;
                bool cmp_a(const Nd &x, const Nd &y)
                {
                        if (x.a != y.a)
                        {
                                return x.a < y.a;
                        }
                        if (x.b != y.b)
                        {
                                return x.b < y.b;
                        }
                        return x.c < y.c;
                }
                bool cmp_b(const Nd &x, const Nd &y)
                {
                        if (x.b != y.b)
                        {
                                return x.b < y.b;
                        }
                        return x.c < y.c;
                }
                void cdq(int l, int r)
                {
                        if (l >= r)
                        {
                                return;
                        }
                        int m = (l + r) / 2;
                        cdq(l, m);
                        cdq(m + 1, r);
                        int i = l;
                        for (int j = m + 1; j <= r; j++)
                        {
                                while (i <= m and p[i].b <= p[j].b)
                                {
                                        fw.add(p[i].c, p[i].w);
                                        i++;
                                }
                                p[j].an += fw.sum(p[j].c);
                        }
                        for (int k = l; k < i; k++)
                        {
                                fw.add(p[k].c, -p[k].w);
                        }
                        int x = l;
                        int y = m + 1;
                        int z = l;
                        while (x <= m and y <= r)
                        {
                                if (cmp_b(p[x], p[y]))
                                {
                                        q[z++] = p[x++];
                                }
                                else
                                {
                                        q[z++] = p[y++];
                                }
                        }
                        while (x <= m)
                        {
                                q[z++] = p[x++];
                        }
                        while (y <= r)
                        {
                                q[z++] = p[y++];
                        }
                        for (int k = l; k <= r; k++)
                        {
                                p[k] = q[k];
                        }
                }
                vector<ll> dom(const vector<array<int, 3>> &v)
                {
                        int n = (int)v.size();
                        vector<Nd> a(n);
                        vector<int> cs;
                        cs.reserve(n);
                        for (int i = 0; i < n; i++)
                        {
                                a[i].a = v[i][0];
                                a[i].b = v[i][1];
                                a[i].c = v[i][2];
                                a[i].w = 1;
                                a[i].g = i;
                                a[i].an = 0;
                                cs.push_back(a[i].c);
                        }
                        sort(cs.begin(), cs.end());
                        cs.erase(unique(cs.begin(), cs.end()), cs.end());
                        for (int i = 0; i < n; i++)
                        {
                                a[i].c = (int)(lower_bound(cs.begin(), cs.end(), a[i].c) - cs.begin()) + 1;
                        }
                        sort(a.begin(), a.end(), cmp_a);
                        vector<vector<int>> gs;
                        p.clear();
                        for (int i = 0; i < n;)
                        {
                                int j = i;
                                while (j < n and a[i].a == a[j].a and a[i].b == a[j].b and a[i].c == a[j].c)
                                {
                                        j++;
                                }
                                Nd u;
                                u.a = a[i].a;
                                u.b = a[i].b;
                                u.c = a[i].c;
                                u.w = j - i;
                                u.g = (int)gs.size();
                                u.an = 0;
                                gs.push_back(vector<int>());
                                for (int k = i; k < j; k++)
                                {
                                        gs.back().push_back(a[k].g);
                                }
                                p.push_back(u);
                                i = j;
                        }
                        int m = (int)p.size();
                        q.assign(m, Nd());
                        fw.init((int)cs.size() + 2);
                        cdq(0, m - 1);
                        vector<ll> r(n, 0);
                        for (int i = 0; i < m; i++)
                        {
                                ll d = p[i].an + p[i].w - 1;
                                for (int id : gs[p[i].g])
                                {
                                        r[id] = d;
                                }
                        }
                        return r;
                }
                ll inv3(const vector<array<int, 3>> &v)
                {
                        vector<ll> d = dom(v);
                        ll s = 0;
                        for (ll x : d)
                        {
                                s += x;
                        }
                        return s;
                }
        }
}

// Source: https://usaco.guide/silver/sorting-custom?lang=cpp

namespace Custom_Comparators
{
        namespace CustomComparators
        {
                struct Ed
                {
                        int u;
                        int v;
                        int w;
                };
                struct Fr
                {
                        ll p;
                        ll q;
                };
                struct Pt
                {
                        ll x;
                        ll y;
                };
                bool cmp_ed(const Ed &a, const Ed &b)
                {
                        if (a.w != b.w)
                        {
                                return a.w < b.w;
                        }
                        if (a.u != b.u)
                        {
                                return a.u < b.u;
                        }
                        return a.v < b.v;
                }
                bool cmp_fr(const Fr &a, const Fr &b)
                {
                        __int128 l = (__int128)a.p * b.q;
                        __int128 r = (__int128)b.p * a.q;
                        return l < r;
                }
                ll cr(const Pt &a, const Pt &b)
                {
                        return a.x * b.y - a.y * b.x;
                }
                int hp(const Pt &p)
                {
                        if (p.y > 0)
                        {
                                return 1;
                        }
                        if (p.y == 0 and p.x >= 0)
                        {
                                return 1;
                        }
                        return 0;
                }
                bool cmp_pl(const Pt &a, const Pt &b)
                {
                        int ha = hp(a);
                        int hb = hp(b);
                        if (ha != hb)
                        {
                                return ha > hb;
                        }
                        ll c = cr(a, b);
                        if (c != 0)
                        {
                                return c > 0;
                        }
                        ll da = a.x * a.x + a.y * a.y;
                        ll db = b.x * b.x + b.y * b.y;
                        return da < db;
                }
                void srt_ed(vector<Ed> &e)
                {
                        sort(e.begin(), e.end(), cmp_ed);
                }
                void srt_fr(vector<Fr> &f)
                {
                        for (Fr &x : f)
                        {
                                if (x.q < 0)
                                {
                                        x.q = -x.q;
                                        x.p = -x.p;
                                }
                        }
                        sort(f.begin(), f.end(), cmp_fr);
                }
                void srt_pl(vector<Pt> &p)
                {
                        sort(p.begin(), p.end(), cmp_pl);
                }
        }
}

// Source: Local/Reconstructed

namespace Mo_Algorithm
{
    template <class Ans = long long>
    struct MoAlgorithm
    {
        struct Query
    {
            int l, r, idx;

    }
    ;
        int n;
        vector<Query> qs;
        MoAlgorithm(int n_ = 0)
    {
     init(n_); 
    }
        void init(int n_)
    {
            n = n_;
            qs.clear();

    }
        void addQuery(int l, int r)
    {
            qs.push_back(
    {
    l, r, (int)qs.size()
    }
    );

    }
        template <class Add, class Remove, class Get>
        vector<Ans> process(Add add, Remove remove, Get getAnswer)
    {
            int q = (int)qs.size();
            int B = max(1, (int)(n / max(1.0, sqrt((double)q))));
            vector<Query> ord = qs;
            sort(ord.begin(), ord.end(), [&](const Query &a, const Query &b)
    {
    			int ba = a.l / B, bb = b.l / B;
    			if (ba != bb) return ba < bb;
    			if (ba & 1) return a.r > b.r;
    			return a.r < b.r; 
    }
    );
            vector<Ans> ans(q);
            int L = 0, R = -1;
            for (auto qu : ord)
    {
                while (L > qu.l)
                    add(--L);
                while (R < qu.r)
                    add(++R);
                while (L < qu.l)
                    remove(L++);
                while (R > qu.r)
                    remove(R--);
                ans[qu.idx] = getAnswer();

    }
            return ans;

    }
    }
    ;
}

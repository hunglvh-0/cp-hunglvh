// Source: https://codeforces.com/blog/entry/89212

namespace FastIO_Template
{
    namespace FastIOTemplate
    {
        struct FastInput
    {
            static const int SZ = 1 << 20;
            int idx;
            int size;
            char buf[SZ];
            FastInput()
    {
                idx = 0;
                size = 0;

    }
            inline char gc()
    {
                if (idx >= size)
    {
                    size = (int)fread(buf, 1, SZ, stdin);
                    idx = 0;
                    if (!size)
    {
                        return 0;

    }

    }
                return buf[idx++];

    }
            template <class T>
            bool read_int(T &out)
    {
                char c = gc();
                if (!c)
    {
                    return false;

    }
                while (c != '-' and (c < '0' or c > '9'))
    {
                    c = gc();
                    if (!c)
    {
                        return false;

    }

    }
                int neg = 0;
                if (c == '-')
    {
                    neg = 1;
                    c = gc();

    }
                T val = 0;
                while (c >= '0' and c <= '9')
    {
                    val = (T)(val * 10 + (c - '0'));
                    c = gc();

    }
                out = (neg ? -val : val);
                return true;

    }
            bool read_string(string &s)
    {
                s.clear();
                char c = gc();
                if (!c)
    {
                    return false;

    }
                while (c <= ' ')
    {
                    c = gc();
                    if (!c)
    {
                        return false;

    }

    }
                while (c > ' ')
    {
                    s.push_back(c);
                    c = gc();
                    if (!c)
    {
                        break;

    }

    }
                return true;

    }

    }
    ;
        struct FastOutput
    {
            static const int SZ = 1 << 20;
            int idx;
            char buf[SZ];
            FastOutput()
    {
                idx = 0;

    }
            ~FastOutput()
    {
                flush();

    }
            inline void pc(char c)
    {
                if (idx == SZ)
    {
                    flush();

    }
                buf[idx++] = c;

    }
            void flush()
    {
                if (idx)
    {
                    fwrite(buf, 1, idx, stdout);
                    idx = 0;

    }

    }
            template <class T>
            void write_int(T x, char end = '\n')
    {
                if (x == 0)
    {
                    pc('0');
                    if (end)
    {
                        pc(end);

    }
                    return;

    }
                if (x < 0)
    {
                    pc('-');
                    x = -x;

    }
                char s[32];
                int n = 0;
                while (x)
    {
                    s[n++] = (char)('0' + (x % 10));
                    x /= 10;

    }
                while (n--)
    {
                    pc(s[n]);

    }
                if (end)
    {
                    pc(end);

    }

    }
            void write_string(const string &s, char end = '\n')
    {
                for (char c : s)
    {
                    pc(c);

    }
                if (end)
    {
                    pc(end);

    }

    }

    }
    ;
    }
}

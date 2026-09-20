// Source: https://prng.di.unimi.it/

namespace Random_Xoshiro_RNG
{
        namespace RandomXoshiroRNG
        {
                static inline uint64_t rotl(const uint64_t x, int k)
                {
                        return (x << k) | (x >> (64 - k));
                }
                struct SplitMix64
                {
                        uint64_t x;
                        SplitMix64(uint64_t seed = chrono::steady_clock::now().time_since_epoch().count()) : x(seed)
                        {
                        }
                        uint64_t next()
                        {
                                uint64_t z = (x += 0x9e3779b97f4a7c15ULL);
                                z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
                                z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
                                return z ^ (z >> 31);
                        }
                };
                struct Xoshiro256StarStar
                {
                        uint64_t s[4];
                        Xoshiro256StarStar(uint64_t seed = chrono::steady_clock::now().time_since_epoch().count())
                        {
                                seed_rng(seed);
                        }
                        void seed_rng(uint64_t seed)
                        {
                                SplitMix64 sm(seed);
                                for (int i = 0; i < 4; ++i)
                                {
                                        s[i] = sm.next();
                                }
                        }
                        uint64_t next_u64()
                        {
                                uint64_t res = rotl(s[1] * 5ULL, 7) * 9ULL;
                                uint64_t t = s[1] << 17;
                                s[2] ^= s[0];
                                s[3] ^= s[1];
                                s[1] ^= s[2];
                                s[0] ^= s[3];
                                s[2] ^= t;
                                s[3] = rotl(s[3], 45);
                                return res;
                        }
                        uint32_t next_u32()
                        {
                                return (uint32_t)(next_u64() >> 32);
                        }
                        double next_double()
                        {
                                return (next_u64() >> 11) * (1.0 / (1ULL << 53));
                        }
                        long long next_ll(long long l, long long r)
                        {
                                uint64_t span = (uint64_t)(r - l + 1);
                                uint64_t x = next_u64();
                                return l + (long long)(x % span);
                        }
                        template <class T>
                        void shuffle_vec(vector<T> &a)
                        {
                                for (int i = (int)a.size() - 1; i > 0; --i)
                                {
                                        int j = (int)(next_u64() % (uint64_t)(i + 1));
                                        swap(a[i], a[j]);
                                }
                        }
                };
        }
}

import math

MOD = 998244353
def solve(N, K):
    C = 2*N - K
    if C < 0 or C > N: return 0
    if N == 0: return 0
    P = [0] * (N + 1)
    P[0] = 0; P[1] = 1 # x
    for i in range(1, N):
        # multiply by (x + i)
        nxt = [0] * (N + 1)
        for j in range(N):
            if P[j]:
                nxt[j+1] = (nxt[j+1] + P[j]) % MOD
                nxt[j] = (nxt[j] + P[j] * i) % MOD
        P = nxt
    ans = P[C] * pow(math.factorial(N), MOD - 2, MOD) % MOD
    return ans

print("N=3, K=4:", solve(3, 4))
print("N=3, K=6:", solve(3, 6))
print("N=1, K=1:", solve(1, 1))
print("N=1, K=2:", solve(1, 2))


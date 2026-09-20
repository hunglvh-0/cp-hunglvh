import sys
import numpy as np
import random
import itertools

def rank(M, n):
    if len(M) == 0: return 0
    M = [list(row) for row in M]
    r = 0
    rows = len(M)
    cols = len(M[0])
    for c in range(cols):
        pivot = -1
        for i in range(r, rows):
            if M[i][c]:
                pivot = i
                break
        if pivot != -1:
            M[r], M[pivot] = M[pivot], M[r]
            for i in range(rows):
                if i != r and M[i][c]:
                    for j in range(cols):
                        M[i][j] ^= M[r][j]
            r += 1
    return r

def gf2_inv(M):
    n = len(M)
    A = np.eye(n, dtype=int)
    M_copy = M.copy()
    for i in range(n):
        pivot = -1
        for j in range(i, n):
            if M_copy[j, i]:
                pivot = j
                break
        if pivot == -1: return None
        if pivot != i:
            M_copy[[i, pivot]] = M_copy[[pivot, i]]
            A[[i, pivot]] = A[[pivot, i]]
        for j in range(n):
            if i != j and M_copy[j, i]:
                M_copy[j] ^= M_copy[i]
                A[j] ^= A[i]
    return A

def test():
    for _ in range(10):
        n = 4
        m = 11

        while True:
            ones = random.sample([(i, j) for i in range(n) for j in range(n)], m)
            M = np.zeros((n, n), dtype=int)
            for r, c in ones:
                M[r, c] = 1
            if rank(M, n) == n:
                break

        rem = list(ones)
        random.shuffle(rem)
        seq = []

        curr_M = M.copy()
        while len(rem) > n:
            A = gf2_inv(curr_M)
            f1 = False
            for idx, (i, j) in enumerate(rem):
                if A[j, i] == 0:
                    seq.append((i, j))
                    curr_M[i, j] = 0
                    rem.pop(idx)
                    f1 = True
                    break
            if f1: continue

            f2 = False
            for i1 in range(len(rem)):
                for i2 in range(i1 + 1, len(rem)):
                    r1, c1 = rem[i1]
                    r2, c2 = rem[i2]
                    if A[c1, r2] and A[c2, r1]:
                        seq.append((r1, c1))
                        seq.append((r2, c2))
                        curr_M[r1, c1] = 0
                        curr_M[r2, c2] = 0
                        rem.pop(i2)
                        rem.pop(i1)
                        f2 = True
                        break
                if f2: break

            if not f2:
                print("FAIL!")
                return

        # Now we have seq and rem.
        full_seq = seq + rem

        # Calculate moves by taking rank
        moves = 0
        idx = 0

        sim_M = M.copy()

        while idx < m:
            rk = rank(sim_M, n)
            assert rk > 0

            # take rk elements
            for i in range(rk):
                r, c = full_seq[idx + i]
                sim_M[r, c] = 0

            idx += rk
            moves += 1

        optimal = (m + n - 1) // n
        if moves > optimal:
            print(f"n={n}, m={m}, optimal={optimal}, moves={moves}")
            return

    print("ALL OPTIMAL!")

test()

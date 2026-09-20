import sys
import numpy as np
import random
import itertools
from collections import deque

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

def greedy_moves(ones, n):
    curr_M = np.zeros((n, n), dtype=int)
    for r, c in ones: curr_M[r, c] = 1

    moves = 0
    while len(ones) > 0:
        rk = rank(curr_M, n)
        if rk == 0: break

        # We must remove exactly rk elements.
        # To minimize moves, we want the remaining rank to be as LARGE as possible.
        # But let's just use my algorithm: remove using Woodbury, then chunk!
        # Wait, my C++ algorithm does exactly what?
        pass

def bfs_min_moves(ones_list, n):
    q = deque()
    q.append((tuple(sorted(ones_list)), 0))
    visited = set()
    visited.add(tuple(sorted(ones_list)))

    while q:
        curr, dist = q.popleft()
        if not curr:
            return dist

        curr_M = [[0]*n for _ in range(n)]
        for r, c in curr:
            curr_M[r][c] = 1
        rk = rank(curr_M, n)

        for combo in itertools.combinations(curr, rk):
            nxt = list(curr)
            for x in combo:
                nxt.remove(x)
            nxt = tuple(sorted(nxt))
            if nxt not in visited:
                visited.add(nxt)
                q.append((nxt, dist + 1))
    return -1

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

        min_moves = bfs_min_moves(ones, n)
        print(f"n={n}, m={m}, min_moves={min_moves}")

test()

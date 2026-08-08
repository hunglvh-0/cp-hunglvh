import sys

def hack():
    edges = []
    n_id = 3
    edges.append((1, 2))
    r = 237865
    curr = 2
    for _ in range(r):
        edges.append((curr, n_id))
        curr = n_id
        n_id += 1
    k = 237847
    curr = 1
    for _ in range(k):
        edges.append((curr, n_id))
        curr = n_id
        n_id += 1
    h = 18
    level = [curr]
    for _ in range(h):
        next_level = []
        for u in level:
            left = n_id
            right = n_id + 1
            edges.append((u, left))
            edges.append((u, right))
            n_id += 2
            next_level.append(left)
            next_level.append(right)
        level = next_level
    n = n_id - 1
    out = []
    out.append("1")
    out.append(str(n))
    for u, v in edges:
        out.append(f"{u} {v}")
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == "__main__":
    hack()
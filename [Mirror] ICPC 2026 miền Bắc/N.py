import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    a, b, c = map(int, data[:3])
    print(a + b + c)

if __name__ == "__main__":
    solve()


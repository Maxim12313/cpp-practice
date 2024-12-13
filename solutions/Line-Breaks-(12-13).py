import sys

input = sys.stdin.readline
write = sys.stdout.write


def solve():
    n, m = map(int, input().split())
    words = [""] * n
    for i in range(n):
        words[i] = input().strip()

    x = 0
    length = 0
    for w in words:
        if length + len(w) > m:
            break
        length += len(w)
        x += 1

    print(x)


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()

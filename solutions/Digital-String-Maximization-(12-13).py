import sys

input = sys.stdin.readline
write = sys.stdout.write


def solve():
    # make left as big as possible
    # if curr > left + 1
    # always swap, repeatedly too
    s = [int(x) for x in input().strip()]
    for i in range(1, len(s)):
        for j in range(i, 0, -1):  # at most ~9 iterations
            if not (s[j - 1] < s[j] - 1):
                break
            s[j - 1], s[j] = s[j] - 1, s[j - 1]

    write("".join(map(str, s)) + "\n")


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()

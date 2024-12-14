import sys

input = sys.stdin.readline
write = sys.stdout.write


def solve():
    a = list(input().strip())
    b = list(input().strip())
    c = list(input().strip())
    INT_MAX = 2**31 - 1

    dp = [[INT_MAX] * (len(b) + 1) for _ in range(len(a) + 1)]
    dp[0][0] = 0

    for i in range(1, len(a) + 1):
        dp[i][0] = dp[i - 1][0] + int(a[i - 1] != c[i - 1])

    for j in range(1, len(b) + 1):
        dp[0][j] = dp[0][j - 1] + int(b[j - 1] != c[j - 1])

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            k = i + j
            candA = dp[i - 1][j] + int(a[i - 1] != c[k - 1])
            candB = dp[i][j - 1] + int(b[j - 1] != c[k - 1])
            dp[i][j] = min(candA, candB)

    print(dp[len(a)][len(b)])


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()

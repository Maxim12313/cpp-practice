import sys

input = sys.stdin.readline
write = sys.stdout.write


def solve():
    # can only pass between same parity
    n = int(input())
    nums = list(map(int, input().split()))

    sum1 = 0
    for i in range(0, n, 2):
        sum1 += nums[i]

    sum2 = 0
    for i in range(1, n, 2):
        sum2 += nums[i]

    sizea = int((n + 1) / 2)
    sizeb = int(n / 2)
    a = sum1 % sizea == 0
    b = sum2 % sizeb == 0
    works = a and b and sum1 / sizea == sum2 / sizeb
    print("YES" if works else "NO")


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()

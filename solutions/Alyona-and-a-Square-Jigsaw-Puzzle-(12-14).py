import sys

input = sys.stdin.readline
write = sys.stdout.write


def solve():
    n = int(input())
    arr = list(map(int, input().split()))

    curr = 1
    adding = 0
    sum = 0
    happy = 0
    for i in range(n):
        sum += arr[i]
        while curr < sum:
            curr += adding
            adding += 8
        if sum == curr:
            happy += 1

    print(happy)
    # 1, 1 + 8, 9 + 16, 25 + 24
    # sum of


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()

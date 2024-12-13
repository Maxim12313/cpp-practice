import sys

input = sys.stdin.readline
write = sys.stdout.write


def solve():
    n = input().strip()
    curr = sum(int(c) for c in n)
    # for every 2, can add 2
    # for every 3, can add 6
    # if sum digits divisible by 9, then works

    count2 = min(n.count("2"), 9)  # 2 * 9 = 18, divisible by 9 wraparound
    count3 = min(n.count("3"), 3)  # 6 * 3 = 18, divisible by 9 wraparround

    canMake = [False] * (count2 * 2 + count3 * 6 + 1)
    canMake[0] = True

    for i in range(2, len(canMake), 2):
        if count2 == 0:
            break
        canMake[i] = True
        count2 -= 1

    for i in range(count3):
        for j in range(6, len(canMake)):
            canMake[j] |= canMake[j - 6]

    diff = 9 - (curr % 9)
    works = diff % 9 == 0
    for i in range(diff, len(canMake), 9):
        if canMake[i]:
            works = True

    print("YES" if works else "NO")


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()

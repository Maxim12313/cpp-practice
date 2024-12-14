import sys

input = sys.stdin.readline
write = sys.stdout.write


def solve():
    n = int(input())
    s = list(input().strip())
    # change from min freq to max freq
    # n! / each freq!...
    charFreq = [0] * 26
    for c in s:
        charFreq[ord(c) - ord("a")] += 1

    maxVal = 0
    minVal = 25
    for i in range(26):
        if charFreq[i] == 0:
            continue

        if charFreq[maxVal] < charFreq[i] or charFreq[maxVal] == 0:
            maxVal = i

        # >= to separate min and max
        if charFreq[minVal] >= charFreq[i] or charFreq[minVal] == 0:
            minVal = i

    maxVal = chr(maxVal + ord("a"))
    minVal = chr(minVal + ord("a"))
    i = s.index(minVal)
    s[i] = maxVal
    print("".join(s))


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()

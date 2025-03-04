import sys
from collections import Counter

input = sys.stdin.read
data = input().split()
index = 0

t = int(data[index])
index += 1

for _ in range(t):
    index += 1  # skip the empty line
    a = list(map(int, data[index:index + int(data[index - 1])]))
    index += len(a)
    C = Counter(a)
    d = len(a) - 2
    for n in range(1, 10**7):
        if n*n == d and C[n] > 1:
            print(n, n)
            break
        if d % n == 0:
            m = d // n
            if n in C and m in C:
                print(n, m)
                break
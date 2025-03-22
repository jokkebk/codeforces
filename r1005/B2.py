from collections import Counter
import sys
input = sys.stdin.readline

for _ in [0]*int(input()):
    input()
    l = list(map(int, input().split()))

    c = Counter(l)
    
    # Indices of numbers with multiple occurences
    p = [i for i,v in enumerate(l) if c[v] > 1]

    # (left, right) ranges
    R = [(l, r) for l, r in zip([-1]+p, p+[len(l)])]

    # Find the longest range
    l, r = max(R, key=lambda x: x[1]-x[0])

    print(0 if r-l <= 1 else f"{l+2} {r}")

    

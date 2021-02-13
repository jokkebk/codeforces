from collections import Counter

(n,m), a, b = (list(map(int, input().split())) for _ in '012')

c = Counter(b)
for x in sorted((m + i - a[0]) % m for i in c):
    if Counter((i+x)%m for i in a) == c:
        print(x)
        break

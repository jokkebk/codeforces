from collections import Counter

t = int(input())
for i in range(t):
    input() # discard n
    c = Counter(i%3 for i in map(int, input().split()))
    mi = min(c[1], c[2])
    ma = max(c[1], c[2])
    print(c[0] + mi + (ma-mi)//3)

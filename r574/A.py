from collections import Counter

n, k = map(int, input().split())
c = Counter(int(input()) for i in range(n))
print(n - sum(1 for v in c if c[v]%2)//2)

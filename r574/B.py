can = lambda n, e: (n-e+1)*(n-e)//2 - e
n, k = map(int, input().split())
a = 0

for i in range(len(bin(n))-3, -1, -1):
    if a + 2**i < n and can(n, a + 2**i) >= k: a += 2**i

print(a)

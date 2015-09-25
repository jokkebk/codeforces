from itertools import product, combinations
from functools import reduce

n, m, k = (int(v) for v in input().split())

dp = [[0]*(1<<n) for i in range(n)]

for i,a in enumerate(input().split()): dp[i][0] = int(a)

sat = {p: 0 for p in product(range(n), repeat=2)}
for i in range(k):
    x, y, c = (int(v) for v in input().split())
    sat[(x-1,y-1)] = c

for bits in range(m):
    for bt in combinations(range(n), bits+1):
        ma = reduce(lambda x,y: x|(1<<y), bt, 0)
        for j in range(n):
            if ma & (1<<j): continue # not a new bit
            dp[j][ma] = dp[j][0] + max(dp[b][ma-(1<<b)] +
                        sat[(b,j)] for b in bt)

best = 0
for bt in combinations(range(n), m):
    ma = reduce(lambda x,y: x|(1<<y), bt, 0)
    for j in bt: best = max(best, dp[j][ma-(1<<j)])
print(best)

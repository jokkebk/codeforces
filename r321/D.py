n, m, k = (int(v) for v in input().split())

masks = [list() for i in range(n+1)]
for i in range(1<<n): masks[bin(i).count('1')].append(i)

dp = [[0]*(1<<n) for i in range(n)]

for i,a in enumerate(input().split()): dp[i][0] = int(a)

sat = {}
for i in range(k):
    x, y, c = (int(v) for v in input().split())
    sat[(x-1,y-1)] = c

for bits in range(1,m+1):
    for ma in masks[bits]:
        for j in range(n):
            if ma & (1<<j): continue # not a new bit
            dp[j][ma] = max(dp[b][ma-(1<<b)] +
                        dp[j][0] + sat.setdefault((b,j), 0) \
                                for b in range(n) if (ma&(1<<b)))

best = 0
for ma in masks[m]:
    for j in range(n):
        if not (ma & (1<<j)): continue
        best = max(best, dp[j][ma-(1<<j)])
print(best)

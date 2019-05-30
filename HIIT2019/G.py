n = int(input())
g = [[int(v) for v in input().split()] for i in range(n)]

for r in range(n):
    for c in range(n):
        (i, a) = g[r][c-1] if c else (0, 0)
        (j, b) = g[r-1][c] if r else (0, 0)
        w = max(1, i+j)
        g[r][c] = (w, a + b + w * g[r][c])

print(g[-1][-1][1] % int(1e9+7))

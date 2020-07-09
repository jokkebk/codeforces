n, m, s, d = map(int, input().split())
c = sorted((v,i) for i,v in enumerate(map(int, input().split())))
ans = [0] * s

while n > 0 and c:
    ans[c[0][1]] = min(n, d - c[0][0]) # soda into cooler
    n -= d - c[0][0]
    del c[0]

if sum(x for x,i in c) < m: print('impossible')
else: print(*ans, sep=' ')

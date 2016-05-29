n, a, b, c, d = (int(s) for s in input().strip().split())

def ok(i):
    j = i + b - c
    l = i + a - d
    m = l + b - c
    return all(v > 0 and v <= n for v in (i,j,l,m))

print(sum(n for i in range(1,n+1) if ok(i)))

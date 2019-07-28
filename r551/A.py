n, t = map(int, input().split())
b = (1e6, 0)
for i in range(n):
    s, d = map(int, input().split())
    if s > t: w = s-t
    else:
        w = (t-s)%d
        if w: w = d - w
    b = min(b, (w, i+1))

print(b[1])

a, b = (int(v) for v in input().split())
c, d = (int(v) for v in input().split())

r = {b+a*i for i in range(100)}
s = {d+c*i for i in range(100)}
i = r.intersection(s)

print(min(i) if len(i) else -1)

n, m, k = (int(v) for v in input().split())
b, h = 1, set()
for v in input().split(): h.add(int(v))
for i in range(k):
    u, v = (int(v) for v in input().split())
    if b in h: break
    if u != b: u,v = v, u
    if u != b: continue
    b = v
print(b)

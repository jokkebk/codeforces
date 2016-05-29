full = 0
n, t = (int(v) for v in input().strip().split())
g = [t]
for i in range(n):
    g2 = [0] * (len(g)+1)
    for j,l in enumerate(g):
        if l<1: continue
        full += 1
        g2[j] += (l-1)/2
        g2[j+1] += (l-1)/2
    g = g2
print(full)

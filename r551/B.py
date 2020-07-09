n, m, h = map(int, input().split())
H = [list(map(int, input().split()))] * n
c = list(map(int, input().split()))
for i,hc in enumerate(c): H[i] = [min(hc, v) for v in H[i]]

for i in range(n):
    t = list(map(int, input().split()))
    print(' '.join(str(a*b) for a,b in zip(H[i], t)))

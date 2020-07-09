r = len(input().split())
n = int(input())
k = [input() for i in range(n)]
t = [[], []]
i = 0

while k:
    p = (r-1) % len(k)
    t[i].append(k[p])
    i ^= 1
    k = k[p+1:] + k[:p]

for i in (0,1): print(len(t[i]), *t[i], sep='\n')

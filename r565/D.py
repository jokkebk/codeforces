from collections import Counter

prime = [True] * 2750132
for i in range(2, 1659):
    if not prime[i]: continue
    for j in range(2*i, len(prime), i):
        prime[j] = False
pr = [i for i,p in enumerate(prime) if p][1:] # 1, 2, 3, 5, 7, ...
#print(pr[:10])
#pos = {p:i-1 for i,p in enumerate(pr) if p}
#print(len(pr), pr[-10:])
#print(pos[2750131])
#print(pos[7])
#exit(1)

input()
b = sorted(map(int, input().split()), reverse=True)
skip = Counter()
p, a = [], [] # prime, a

for v in b:
    if skip[v]:
        skip[v] -= 1
        continue
    prime = True
    if v <= 200000:
        for d in range(2,min(448, v)):
            if v%d: continue
            #print(v, 'is composite, skip', v//d)
            a.append(v) # composite, and not biggest divisor
            skip[v//d] += 1 # skip the biggest divisor later on
            prime = False
            break
    if prime:
        #print(v, 'is prime')
        p.append(v)

skip = Counter() # again
for v in sorted(p):
    if skip[v]:
        skip[v] -= 1
        continue
    a.append(v)
    skip[pr[v]] += 1

print(' '.join(str(v) for v in a))

n = int(input())
op = [int(v) for v in input().split()]
f = [int(v) for v in input().split()]

ch = [[] for p in op]
for i, p in enumerate(f): ch[p-1].append(i+1) # children

q = [0]
for i in range(n): q += ch[q[i]] # queue parents first

x = [0]*n # how many largest numbers the node consumes
nl = 0 # number of leaves

for p in q[::-1]: # Leaves first
    if not ch[p]: nl += 1 # count leaves
    elif op[p]: x[p] = min(x[c] for c in ch[p])
    else: x[p] = sum(x[c]+1 for c in ch[p])-1

print(nl - x[0])

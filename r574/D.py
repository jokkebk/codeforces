input() # discard n
a = list(map(int, input().split()))
cl = [0]*10
for i in a: cl[len(str(i))-1] += 1
ans, M = 0, 998244353

pad = lambda a, d: a%d + (a - a%d) * 10

for i in a:
    t = i
    for p in range(10):
        #print(p, 'bottom is', i*10)
        i = pad(i, 100**p)
        print(p, 'top is', i)
        
        #if p:
            #print(p-1, 'bottom is', i//10)
        ans = (ans + i * cl[p]) % M
    i = t # restore
    for p in range(10):
        print(p, 'top is', i*10)
        i = pad(i, 10 * 100**p)
        print(p, 'bottom is', i)
        ans = (ans + i * cl[p]) % M

print(ans)

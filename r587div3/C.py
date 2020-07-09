c = lambda s: [(s[0 if (i&1) else 2], s[1 if (i&2) else 3]) for i in range(4)]
ins = lambda p,s: s[0] <= p[0] <= s[2] and s[1] <= p[1] <= s[3]

w = list(map(int,input().split()))
b = [list(map(int,input().split())) for _ in '12']

cn = [set(i for i,p in enumerate(c(w)) if ins(p, s)) for s in b]

if len(cn[0]|cn[1]) < 4: print('YES')
elif any(len(x)==4 for x in cn): print('NO')
else: print('YES' if any(min(b[0][2+i], b[1][2+i]) < max(b[0][i], b[1][i]) \
        for i in (0,1)) else 'NO')

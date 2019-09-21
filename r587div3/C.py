c = lambda s: [(s[0 if (i&1) else 2], s[1 if (i&2) else 3]) for i in range(4)]
ins = lambda p,s: s[0] <= p[0] <= s[2] and s[1] <= p[1] <= s[3]

w = list(map(int,input().split()))
b = [list(map(int,input().split())) for _ in '12']

cn = [set(i for i,p in enumerate(c(w)) if ins(p, s)) for s in b]

if len(cn[0]|cn[1]) < 4: print('YES')
elif len(cn[0])==4 or len(cn[1])==4: print('NO')
elif min(b[0][2], b[1][2]) < max(b[0][0], b[1][0]): print('YES')
else: print('YES' if min(b[0][3], b[1][3]) < max(b[0][1], b[1][1]) else 'NO')

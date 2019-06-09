t = int(input())

for i in range(t):
    n, m = map(int, input().split())
    e = [[] for i in range(n)]
    for j in range(m):
        u, v = map(int, input().split())
        e[u-1].append(v-1)
        e[v-1].append(u-1)
    q = [(0,0)] # make 0 vertex tree root
    s = [[], []] # two alternative sets
    seen = [False] * n # will become -1, 1
    while q: # depth first search to make a tree
        (v, j) = q.pop()
        if seen[v]: continue # been here
        seen[v] = True
        s[j].append(v)
        #for v in e[v]: q.append((v, j^1))
        q += ((v, j^1) for v in e[v])
    ans = s[0] if len(s[0]) < len(s[1]) else s[1]
    print(len(ans))
    print(' '.join(str(v+1) for v in ans))

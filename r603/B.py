for _ in range(int(input())):
    n = int(input())
    p = [input().strip() for _ in range(n)]
    c = 0
    for i,b in enumerate(p):
        if p.count(b) > 1:
            for x in '0123456789':
                p[i] = x + b[1:]
                if p.count(p[i]) == 1: break
            c += 1
    print(c)
    for x in p: print(x)


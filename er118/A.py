t = int(input())
p = lambda x: x[0]*10**x[1]
for _ in range(t):
    a, b = [list(map(int, input().split())) for i in (1,2)]
    if a[1] > b[1]:
        a[1] -= b[1]
        b[1] = 0
        if a[1] > 6: print('>')
    else:
        b[1] -= a[1]
        a[1] = 0
        if b[1] > 6: print('<')
    print('=' if p(a) == p(b) else ('<' if p(a) < p(b) else '>'))

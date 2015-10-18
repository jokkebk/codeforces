from operator import gt, lt

x, y = (int(w) for w in input().split())

if x>y:
    ch = 'AB'
    op1, op2 = lt, gt
    ax, ay, bx, by = 1, 0, 0, 1
else:
    ch = 'BA'
    op1, op2 = gt, lt
    ax, ay, bx, by = 0, 1, 1, 0

ans = []

while(ax+ay+bx+by < x+y):
    n=0
    for sh in range(59,-1,-1):
        t = n + (1<<sh)
        if op1(y * (bx + t*ax), x * (by + t*ay)): n = t
    if not n:
        print('Impossible')
        exit(0)
    ans.append(n)
    ax, bx = bx + n*ax, ax # Increment and swap
    ay, by = by + n*ay, ay # Increment and swap
    op1, op2 = op2, op1

for i,a in enumerate(ans): print('%d%s' % (a, ch[i&1]), end='')
print()

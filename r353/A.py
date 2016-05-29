a, b, c = (int(s) for s in input().strip().split())

if a==b: print('YES')
elif c==0: print('NO')
else:
    if a > b:
        c = -c
        a, b = b, a

    if c > 0 and (b-a)%c == 0: print('YES')
    else: print('NO')

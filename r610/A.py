for _ in range(int(input())):
    a,b,c,r = map(int, input().split())
    if a > b: a,b = b,a
    if b < c-r or a > c+r: print(b-a)
    else: print(max(c-r-a,0) + max(b-c-r,0))

from math import sqrt

n, m, a = map(int, input().split())

two = lambda x: any(min(d,x//d) <= min(n,m) and max(d,x//d) <= max(n,m) 
        for d in range(1, int(sqrt(x))+1) if not x%d)

if not a % n or not a % m: print(1)
elif two(a) or two(n*m-a): print(2)
else: print(3)

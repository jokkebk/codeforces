from math import gcd

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print('Infinite' if gcd(a,b)>1 else 'Finite')

from math import gcd
for _ in range(int(input())):
    print('Infinite' if gcd(*map(int, input().split()))>1 else 'Finite')

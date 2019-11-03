import operator as op
import re
from functools import reduce, lru_cache

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom

@lru_cache(maxsize=None)
def w(n):
    if n < 5: return sum(ncr(n-i, i) for i in range(n//2+1))
    a = n//2
    b = n-a
    return (w(a)*w(b) + w(a-1)*w(b-1)) % 1000000007

s = input().strip()

if 'm' in s or 'w' in s: print(0)
else:
    s = [w(len(l)) for l in re.findall(r'u+|n+', s)]
    print(reduce(op.mul, s, 1) % 1000000007)


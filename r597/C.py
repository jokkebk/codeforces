import re
from functools import reduce, lru_cache

M = int(1e9+7)

@lru_cache(maxsize=None)
def w(n):
    if n < 5: return (1, 1, 2, 3, 5, 8)[n]
    a = n//2
    b = n-a
    return (w(a)*w(b) + w(a-1)*w(b-1)) % M

s = input().strip()

if 'm' in s or 'w' in s: print(0)
else:
    s = [w(len(l)) for l in re.findall(r'u+|n+', s)]
    print(reduce(lambda a,b: a * b % M, s, 1))

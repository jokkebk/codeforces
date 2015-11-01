from functools import lru_cache
import sys

sys.setrecursionlimit(10000)

@lru_cache(maxsize=None)
def S(n,k):
    if k==0: return 0 if n else 1
    if n==k or k==1: return 1
    return k*S(n-1,k)+S(n-1,k-1)

while True:
    print(S(int(input('n> ')), int(input('k> '))))

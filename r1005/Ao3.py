import sys, itertools
I = iter(sys.stdin.read().split())
print("\n".join("0" if "1" not in s else str(sum(1 for _ in itertools.groupby(s[s.index("1"):])))
              for _ in range(int(next(I))) for _ in [next(I)] for s in [next(I)]))
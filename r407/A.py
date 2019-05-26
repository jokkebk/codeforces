n, k = (int(v) for v in input().split())
w = list(int(v) for v in input().split())
up = lambda a, d: a//d + (1 if a%d else 0)
print(up(sum(up(v, k) for v in w), 2))

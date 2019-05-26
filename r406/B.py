n, m = (int(v) for v in input().split())
for i in range(m):
    s = set([int(v) for v in input().split()][1:])
    if len(s) == len({abs(v) for v in s}):
        print('YES')
        exit(0)
print('NO')

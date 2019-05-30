n, k = (int(v) for v in input().split())
print('YES' if (k>2 or (k==2 and (n&1^1))) else 'NO')

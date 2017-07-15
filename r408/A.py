n,m,k = (int(v) for v in input().split())
a = list(int(v) for v in input().split())
print(10*min(abs(m-1-i) for i in range(n) if a[i] and a[i] <= k))

input()
a = list(int(v)&1 for v in input().split())
b = list(int(v)&1 for v in input().split())
print(min(a.count(0), b.count(1)) + min(a.count(1), b.count(0)))

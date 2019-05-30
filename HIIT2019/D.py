input()
a = [sorted(int(v) for v in input().split()) for i in (0,1)]
print(sum(abs(x-y) for x,y in zip(*a)))

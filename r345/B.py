n = int(input())
a = list(int(v) for v in input().strip().split())
joy = 0

while a:
    a.sort()
    b = []
    for i in range(1, len(a)):
        if a[i-1] == a[i]: b.append(a[i])
        else: joy += 1
    a = b

print(joy)

a, b = (int(v) for v in input().strip().split())

m = 0

while a > 0 and b > 0:
    if a<b: a += 3
    else: b += 3
    a, b = a-2, b-2
    m += 1

if a < 0 or b < 0: m -= 1

print(m)

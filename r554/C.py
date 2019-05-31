from fractions import gcd
import math

lcm = lambda a, b: a // gcd(a, b) * b
a, b = (map(int, input().split()))
ans = (lcm(a, b), 0)

if a != b:
    d = abs(b-a)
    divs = {d}

    for i in range(2, int(math.sqrt(d))):
        if not d%i: divs |= {i, d//i}

    for d in divs:
        k = d-a%d if a%d else 0
        ans = min(ans, ((lcm(a+k, b+k), k)))

print(ans[1])

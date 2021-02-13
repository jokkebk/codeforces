from collections import Counter

int(input())
c = Counter(map(int, input().split()))
s8 = {l for l in c if c[l]>7}
s6 = {l for l in c if c[l]>5}
s4 = {l for l in c if c[l]>3}
s2 = {l for l in c if c[l]>1}

for _ in range(int(input())): # ops
    op, n = input().split()
    n = int(n)
    s8.discard(n)
    s6.discard(n)
    s4.discard(n)
    s2.discard(n)
    a = c[n] = c[n] + (1 if op=='+' else -1)
    if a > 7: s8.add(n)
    if a > 5: s6.add(n)
    if a > 3: s4.add(n)
    if a > 1: s2.add(n)

    print('YES' if len(s8) or (len(s4) and len(s6)+len(s4)+len(s2) > 3) else 'NO')

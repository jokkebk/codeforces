from collections import Counter

start = input()[-1]
n = int(input())
w = [input() for i in range(n)]
c = Counter(a[0] for a in w)
ok = [a for a in w if a[0]==start]

if not ok: print('?')
else:
    for a in ok:
        if c[a[-1]] == (1 if a[-1]==start else 0):
            print(a+'!')
            exit(0)
    print(ok[0])


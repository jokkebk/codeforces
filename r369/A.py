n = int(input())
ok = False
rows = []
for i in range(n):
    s = input()
    if not ok and 'OO' in s:
        s = s.replace('OO', '++', 1)
        ok = True
    rows.append(s)

if ok:
    print('YES')
    print('\n'.join(rows))
else:
    print('NO')

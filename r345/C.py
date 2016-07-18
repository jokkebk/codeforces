row, col, pos = {}, {}, {}
C = lambda n: n*(n-1)//2

for i in range(int(input())):
    x, y = (int(v) for v in input().strip().split())

    row[y] = row.setdefault(y, 0) + 1
    col[x] = col.setdefault(x, 0) + 1
    pos[(x,y)] = pos.setdefault((x,y), 0) + 1

ways = sum(C(row[y]) for y in row) + \
    sum(C(col[x]) for x in col) -\
    sum(C(pos[(x,y)]) for x,y in pos)

print(ways)

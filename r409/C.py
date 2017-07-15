n, p = (int(v) for v in input().split())
end, draw, t = [], 0, 0

for i in range(n):
    a, b = (int(v) for v in input().split())
    end.append((b/a, a))
end = sorted(end)

print(end)

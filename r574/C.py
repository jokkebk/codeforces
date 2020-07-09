n = int(input())
h = [list(map(int, input().split())) for i in range(2)]

for i in range(n-1):
    for t in range(2):
        h[t][i+1] = max(h[t][i+1] + h[t^1][i], h[t][i])

print(max(h[0][-1], h[1][-1]))

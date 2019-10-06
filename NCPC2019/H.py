n = int(input())
t = list(map(int, input().split()))
print(*min((max(t[i-1], t[i+1]), i) for i in range(1, len(t)-1))[::-1])

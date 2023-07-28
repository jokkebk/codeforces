t = int(input())
for _ in range(t):
    input()
    a = sorted(map(int, input().split()))
    for i in range(len(a)//2):
        print(a[-i-1], a[0])

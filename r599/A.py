for _ in range(int(input())):
    input()
    a = sorted(map(int, input().split()))[::-1]
    print(max(i+1 for i,x in enumerate(a) if x>i))

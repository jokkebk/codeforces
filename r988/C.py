for _ in range(int(input())):
    n = int(input())
    print(-1 if n <= 4 else ' '.join(map(str, [x for x in range(1, n+1, 2) if x != 5] + [5, 4] + [x for x in range(2, n+1, 2) if x != 4])))
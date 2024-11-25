for _ in range(int(input())):
    input()
    print(sum(v // 2 for v in __import__('collections').Counter(input().split()).values()))
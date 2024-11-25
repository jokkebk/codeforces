from collections import Counter

for _ in range(int(input())):
    input()
    a = list(map(int, input().split()))
    C = Counter(a)
    d = len(a) - 2
    for n in range(1, 10**7):
        if n*n == d and C[n] > 1:
            print(n, n)
            break
        if d % n == 0:
            m = d // n
            if n in C and m in C:
                print(n, m)
                break
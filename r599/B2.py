from collections import Counter

for _ in range(int(input())):
    input()
    s, t = (list(input().strip()) for i in 'st')
    print(s, t)
    sc = Counter(s)
    tc = Counter(t)

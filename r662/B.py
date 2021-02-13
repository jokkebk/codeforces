from collections import Counter

a = [0] * 100001
s = [0] * 9

int(input())
for c in map(int, input().split()): a[c] += 1
for i,n in enumerate(a): s[min(n, 8)] += 1

#print(s)

for _ in range(int(input())): # ops
    op, n = input().split()
    n = int(n)
    s[min(a[n], 8)] -= 1
    a[n] = a[n] + (1 if op=='+' else -1)
    s[min(a[n], 8)] += 1

    #print(s)
    if s[8]: print('YES') # 8
    elif sum(s[4:9]) > 1: print('YES') # 4+4
    elif sum(s[6:8]) and sum(s[2:4]): print('YES') # 6+2
    elif sum(s[4:8]) and sum(s[2:4]) > 1: print('YES') # 4+2+2
    else: print('NO')

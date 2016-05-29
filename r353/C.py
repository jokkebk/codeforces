n = int(input())
a = [int(s) for s in input().strip().split()]
b = a[::-1]

def trans(a):
    need = 0
    for i in range(len(a)-1):
        if a[i]:
            a[i+1] += a[i]
            need += 1
    return need

print(n,a, trans(a), trans(b))

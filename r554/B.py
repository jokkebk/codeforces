x = int(input())
ns = []

for i in range(40):
    b = format(x, 'b') # reverse
    n = len(b) - b.find('0')

    if n > len(b): # longcat
        print(i)
        if i: print(' '.join(ns))
        break

    if i&1: x += 1
    else:
        ns.append(str(n))
        x = x ^ 2**n - 1

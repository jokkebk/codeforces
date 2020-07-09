n = int(input())
s = input()
hi, lo = 0, 0

for c in s:
    if c=='(':
        hi += 1
        lo += 1
    elif c==')':
        hi -= 1
        lo -= 1
    else:
        hi += 1
        lo = lo-1 if lo else lo+1
    if lo<0:
        print(':(')
        exit()
if lo:

def maxsub(a):
    meh = msf = a[0]
    for x in a[1:]:
        meh = max(x, meh + x)
        msf = max(msf, meh)
    return msf

n = int(input())
a = [int(v) for v in input().split()]
b = [abs(a[i]-a[i+1])*(-1)**i for i in range(n-1)]

print(max(maxsub(b), maxsub([-v for v in b])))

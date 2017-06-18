def a(h, m, i):
    m += i
    h += m//60
    return (h%24, m%60)

h, m = (int(v) for v in input().split(':'))
s = lambda h, m: '%02d:%02d' % (h,m)
p = lambda s: s == s[::-1]


print(next(i for i in range(1440) if p(s(*a(h,m,i)))))


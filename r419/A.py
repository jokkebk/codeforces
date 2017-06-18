a = lambda h, m, i: ((h+(m+i)//60)%24, (m+i)%60)
s = lambda h, m: '%02d:%02d' % (h,m)
p = lambda s: s == s[::-1]

h, m = (int(v) for v in input().split(':'))

print(next(i for i in range(999) if p(s(*a(h,m,i)))))


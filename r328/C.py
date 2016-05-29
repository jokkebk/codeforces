def gcd(a,b):
    while b: a, b = b, a%b
    return a

t, w, s = [int(v) for v in input().split()]
com = gcd(w,s)
lcm = w*s//com
seq = t//lcm
num = (seq+1) * min(w,s) - 1
end = seq*lcm + min(w,s) - 1
if end > t: num -= end-t
g = gcd(num, t)
print("%d/%d" % (num//g, t//g))

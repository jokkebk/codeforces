input() # discard n
a = list(map(int, input().split()))
cl = [0]*10
for i in a: cl[len(str(i))-1] += 1
ans = 0 

for i in a:
    for p,l in enumerate(cl):
        ans += i * 10 * l # bottom zero pad
        d = 10 * 100**p
        i = i%d + (i - i%d) * 10
        ans += i * l # top zero pad

print(ans % 998244353)

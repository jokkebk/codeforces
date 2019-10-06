from itertools import product, permutations

t = int(input())
f = lambda aw,ah,bw,bh,cw,ch: min(
        (aw+bw+cw)*max(ah,bh,ch),
        max(aw+bw,cw)*max(ah+ch,bh+ch),
        (aw+max(bw,cw))*max(ah, bh+ch))

def gen(c):
    for o in permutations((0,2,4)): # (0,2,4), (0,4,2), ..., (4,2,0)
        for i in product(range(2), repeat=3): # (0,0,0), ..., (1,1,1)
            yield(sum(([c[a+b],c[a+b^1]] for a,b in zip(o,i)),[])) # !!!

for _ in range(t):
    c = list(map(int, input().split()))
    print(min(f(*i) for i in gen(c)))

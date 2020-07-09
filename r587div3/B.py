input()
a = sorted((b,a) for a,b in enumerate(map(int,input().split())))[::-1]
print(sum(ai*x+1 for x,(ai,n) in enumerate(a)))
print(' '.join(str(n+1) for v,n in a))

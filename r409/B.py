a, b = input(), input()

print(b if b == ''.join(min(x,y) for x,y in zip(a,b)) else -1)

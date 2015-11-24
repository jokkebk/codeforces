def readnum():
    n, b = (int(w) for w in input().split())
    x = 0
    nums = list(int(w) for w in input().split())
    return sum(nums[i] * b**(n-1-i) for i in range(n))

x = readnum()
y = readnum()

if x==y: print('=')
if x<y: print('<')
if x>y: print('>')

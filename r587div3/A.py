input()
s = list(input().strip())
n = 0
for i in range(1,len(s),2):
    if s[i-1] == s[i]: s[i], n = 'a' if s[i]=='b' else 'b', n+1
print(n)
print(''.join(s))


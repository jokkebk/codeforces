n = int(input())
s = input().strip()

print('YES' if s[:-10].count('8')*2 > n-10 else 'NO')

import re

for _ in [0]*int(input()):
    input()
    t = re.findall(r'(.)\1*', input().strip())
    print(len(t) - (t[0] == '0'))
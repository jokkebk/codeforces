for _ in range(int(input())):
    n = int(input())
    s, l = [0], []
    for d in range(1,n//2+2):
        #print(d, s, l)
        if n//d <= s[-1]: break
        l.append(n//d)
        if d >= l[-1]: break
        s.append(d)
    s += l[::-1]
    print(len(s))
    print(' '.join(str(i) for i in s))

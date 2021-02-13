for _ in range(int(input())):
    n,p,k = map(int, input().split())
    a = sorted(map(int, input().split()))
    #print(a, a[k-1])
    if a[k-1] > p:
        #print('Less than k')
        for i in range(n):
            p -= a[i]
            if p<0:
                print(i)
                break # guaranteed
    else:
        p -= a[k-1] # p >= 0
        #print('k or more', p, 'coins left')
        for i in range(n-k):
            p -= a[i] + a[i+k] - a[i+k-1]
            #print('at', i, 'we have', p, 'coins left')
            if p<0:
                print(i+k)
                break
        if p>=0: print(n) # money for all

from collections import Counter

for _ in [0]*int(input()):
    input()
    l = list(map(int, input().split()))

    c = Counter(l)
    best = (0,0) # (left, right) range of best answer
    last = -1 # last number with multiple occurences
    for i,v in enumerate(l):
        if c[v] > 1:
            if i-last > best[1] - best[0] + 1:
                best = (last+2, i) # range between this and last on 1 based indexing
                #print("\nCandidate: ", best)
            last = i
    if best[1] > 0:
        print(best[0], best[1])
    else:
        print(0)
from collections import defaultdict

def brute(cards):
    for c in cards:
        if c: yield(c[:1]) # one card
    if cards[0] and cards[1]: # two cards, 2+1
        yield(sorted([cards[0][0], cards[1][0]], reverse=True))
    if len(cards[0]) > 1: # two cards, 1+1
        yield(cards[0][:2])
    if len(cards[0]) > 2: # three cards, 1+1+1
        yield(cards[0][:3])

n = int(input())
best = defaultdict(int)
best[0] = 0

for i in range(n):
    cards = [[], [], []] # 1 2 3 cost cards
    k = int(input())
    for j in range(k):
        c, d, = map(int, input().split())
        cards[c-1].append(d)
    for j in range(3):
        cards[j] = sorted(cards[j], reverse=True)

    outcomes = best.copy()
    for c in brute(cards):
        for n in best:
            pts = best[n]
            n += len(c)
            pts += sum(c)
            if n >= 10:
                n -= 10
                pts += c[0] # double up
            outcomes[n] = max(outcomes[n], pts)
    best = outcomes
    #print(list((a,b) for a,b in best.items()))
print(max(best.values()))


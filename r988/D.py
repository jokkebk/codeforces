import heapq

for _ in range(int(input())):
    n, m, L = map(int, input().split())

    # Read n "l r" integer pairs into a list
    I = [list(map(int, input().split())) for _ in range(n)]

    # Read m "x p" integer pairs into a list
    P = [list(map(int, input().split())) for _ in range(m)]

    # Heap of powerups, initial jumping power, and consumed powerups
    p, j, c, idx = [], 1, 0, 0

    for (l, r) in I:
        # Add powerups at positions before l to the heap
        while idx < len(P) and P[idx][0] < l:
            heapq.heappush(p, -P[idx][1])
            idx += 1
        
        # Increase the jumping power until we can reach r
        while j < r - l + 2:
            if not p:
                j = -1
                break # abort
            j -= heapq.heappop(p)
            c += 1
        
        if j == -1: break # abort

    print(c if j >= 0 else -1)
for _ in range(int(input())):
    n = int(input())
    rps = list(map(int, input().split()))
    bob = input().strip()
    sol = []
    for b in bob:
        need = 'SRP'.index(b)
        sol.append('RPS'[need] if rps[need] else 'x')
        if rps[need]: rps[need] -= 1
    if sol.count('x') * 2 > len(bob): print('NO')
    else:
        print('YES')
        # Shit we have left
        left = ['RPS'[n] for n in range(3) for _ in range(rps[n])]
        print(''.join(left.pop() if s=='x' else s for s in sol))

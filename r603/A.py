for _ in range(int(input())):
    a,b,c = sorted(map(int, input().split()))

    # eat most common with least common, but at most until b==c
    d = min(a, c-b)
    a -= d
    # either a==0 or b==c

    # take turns eathing b and c with a until exhausted, then pair b+c
    print(a - a%2 + b - a//2 + d)

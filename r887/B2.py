# Calculate 30 first Fibonacci numbers to list
fib = [0, 1]
for i in range(30): fib.append(fib[i] + fib[i+1])

for _ in range(int(input())):
    n, k = map(int, input().split())

    if n == 0: print(1)
    elif k > 30: print(0)
    else:
        a, b = fib[k-2], fib[k-1]
        print(sum(1 for i in range(n//(a+b) + 1) if (n - a * i) % b == 0))
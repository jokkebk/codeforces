# Calculate 30 first Fibonacci numbers to list
fib = [0, 1]
for i in range(30): fib.append(fib[i] + fib[i+1])

def extended_euclidean(a, b):
    """Calculate a solution to ax + by = 1"""
    if b == 0: return (1, 0)
    x, y = extended_euclidean(b, a % b)
    return (y, x - (a // b) * y)

# Iterate through consecutive pairs of Fibonacci numbers
# and calculate the solutions to the equation
# a * x + b * y = 1
ab = []
for i in range(len(fib)-1):
    ab.append(extended_euclidean(fib[i], fib[i+1]))
    a, b = ab[-1]
    x, y = fib[i], fib[i+1]
    #print(f'{a} * {x} + {b} * {y} = {a*x + b*y}')

for _ in range(int(input())):
#while True:
    n, k = map(int, input().split())

    if n == 0: print(1)
    elif k > 30: print(0)
    else:
        x, y = fib[k-2], fib[k-1]
        a, b = ab[k-1]
        # Multiply a and b by n
        a, b = a * n, b * n

        print(f'{a} * {x} + {b} * {y} = {a*x + b*y}')

        if a < 0: # Need to make a positive
            a2 = a % y
            b2 = b - (a2 - a) // y * x
            a, b = a2, b2
            print(f'{a} * {x} + {b} * {y} = {a*x + b*y}')

        if a > b: # Need to make a smaller than b
            steps = (a - b) // (x + y) + (1 if (a - b) % (x + y) else 0)
            a -= steps * y
            b += steps * x
            print(f'{a} * {x} + {b} * {y} = {a*x + b*y}')

        print(0 if a < 0 or b < 0 else (b - a) // (x + y) + 1)
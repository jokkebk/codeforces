# Calculate Nth Fibonacci number using matrix exponentiation
def matrix_multiply(A, B):
    return [[A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]],
            [A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]]]

def matrix_power(A, n):
    if n == 1:
        return A
    if n % 2 == 0:
        half_power = matrix_power(A, n // 2)
        return matrix_multiply(half_power, half_power)
    else:
        return matrix_multiply(A, matrix_power(A, n - 1))

def fibonacci_with_prev(n):
    if n <= 0:
        return 0, 0
    if n == 1:
        return 0, 1
    matrix = [[1, 1], [1, 0]]
    result_matrix = matrix_power(matrix, n - 1)
    return result_matrix[0][1], result_matrix[0][0]

def fibonacci_fast(n):
    if n <= 0:
        return 0
    matrix = [[1, 1], [1, 0]]
    result_matrix = matrix_power(matrix, n - 1)
    return result_matrix[0][0]

for _ in range(int(input())):
    n, k = map(int, input().split())

    if n == 0:
        print(1)
        continue
    if k > 30:
        print(0)
        continue

    a, b = fibonacci_with_prev(k-1)

    #print('Fibonacci multipliers before k:', a, b)
    N = 0
    for i in range(n):
        if (a+b) * i > n: break
        s = a * i
        if (n - s) % b == 0: N += 1
    print(N)
# For reference: Fibonacci series is
# 1 1 2 3 5 8 13 21 34 55 89
# 1  2  3  4  5  6  7  8  9  10
# 0  1  1  2  3  5  8  13 21 34

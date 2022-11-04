from sys import setrecursionlimit, stdin
setrecursionlimit(10**6)

def pow_mod(a, b, y):
    if a == 0:
        return 0
    if a == 1:
        return 1

    if b == 0:
        return 1
    if b == 1:
        return a % y

    if y == 1:
        return 0

    z = 1
    while b > 0:
        if b & 1 == 1:
            z = (a * z) % y
        a = (a * a) % y
        b >>= 1
    return z

def phi(x):
    result = x
    for i in range(2, x+1):
        if i*i > x:
            break
        if x % i == 0:
            result //= i
            result *= i-1
            while x % i == 0:
                x //= i
    if x > 1:
        result //= x
        result *= x-1
    return result

def e(x, y):
    if y == 1:
        return 0

    if x == 0:
        return 0
    if x == 1:
        return 1

    phi_y = phi(y)
    return pow_mod(x%y, (e(x, phi_y) + phi_y), y)

t = int(stdin.readline().rstrip())
for _ in range(t):
    n, m = [int(x) for x in stdin.readline().rstrip().split()]
    print(f'{e(n, m)}')

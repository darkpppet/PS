import sys, math
sys.setrecursionlimit(10**6)

def pow_mod(a, b, y):
    z = 1
    while b > 0:
        if b & 1 == 1:
            z = (a * z) % y
        a = (a * a) % y
        b = b >> 1
    return z

def factorize(x):
    factors = set()
    i = 2
    sqrt = round(math.sqrt(x))
    while x > 1 and i <= sqrt:
        if x % i == 0:
            factors.add(i)
            x //= i
        else:
            i += 1
    if x != 1:
        factors.add(x)
    return factors

def phi(x):
    factors = factorize(x)
    result = x
    for factor in factors:
        result //= factor
        result *= (factor-1)
    return result

def e(x, y):
    if y == 1:
        return 0

    match x:
        case 1:
            return 1
        case 2:
            return 2 % y
        case 3:
            return 9 % y
        case 4:
            return 262144 % y

    phi_y = phi(y)
    return pow_mod(x%y, (e(x-1, phi_y) + phi_y), y)

n, m = [int(x) for x in input().split()]

print(e(n, m))

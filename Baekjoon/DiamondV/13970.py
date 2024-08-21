import sys, math
sys.setrecursionlimit(10**6)

def pow_mod(a, b, y):
    z_divided = False
    a_divided = False
    z = 1
    while b > 0:
        if b & 1 == 1:
            temp = a * z
            if temp >= y or a_divided:
                z_divided = True
            z = temp % y
        temp = a * a
        if temp >= y:
            a_divided = True
        a = temp % y
        b = b >> 1
    return z, z_divided

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

x_list = []

def e(index, y):
    if y == 1:
        return 1, False

    if index == len(x_list) - 1:
        return x_list[index] % y, x_list[index] >= y

    phi_y = phi(y)
    x, is_big = e(index + 1, phi_y)
    if is_big:
        return pow_mod(x_list[index], x + phi_y, y)
    else:
        return pow_mod(x_list[index], x, y)

t, m = [int(x) for x in input().split()]
result_list = []

for _ in range(t):
    n, *x_list = [int(x) for x in input().split()]

    result_list.append(e(0, m)[0])

print('\n'.join([str(x) for x in result_list]))

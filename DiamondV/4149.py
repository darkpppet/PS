import math

def is_prime(n):
    n_minus_1 = n-1
    d, s = find_d_and_s(n_minus_1)

    is_n_prime = check_is_prime_with_a(n, d, s, 2)
    for i in [3, 5, 7, 11]:
        if n > i and is_n_prime:
            is_n_prime &= check_is_prime_with_a(n, d, s, i)
        else:
            break

    return is_n_prime

def check_is_prime_with_a(n, d, s, a):
    is_prime_with_a = False
    if pow_mod(a, d, n) == 1:
        is_prime_with_a = True

    for r in range(s):
        if is_prime_with_a or pow_mod(a, d*pow(2, r), n) == n-1:
            is_prime_with_a = True
            break

    return is_prime_with_a

def find_d_and_s(n_minus_1):
    s = 0
    while n_minus_1 % 2 == 0:
        n_minus_1 //= 2
        s += 1
    d = n_minus_1

    return d, s

def pow_mod(a, exp, n):
    if exp == 0:
        return 1
    if exp == 1:
        return a % n

    sqrt = pow_mod(a, exp//2, n)
    pre_result = (sqrt*sqrt) % n

    if exp%2 == 0:
        return pre_result
    else:
        return (pre_result*a) % n

def rho(n):
    x = 2
    y = 2
    d = 1

    while d == 1:
        x = g(x, n)
        y = g(g(y, n), n)
        d = math.gcd(abs(x-y), n)

    if d == n:
        return False
    else:
        return d

def g(x, n):
    return (x*x + 1) % n


print(rho(8051))






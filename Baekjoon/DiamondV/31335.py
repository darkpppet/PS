import math

def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True

    n_minus_1 = n-1
    d, s = find_d_and_s(n_minus_1)

    is_n_prime = check_is_prime_with_a(n, d, s, 2)
    for i in [3, 5, 7, 11, 13, 17, 31, 61, 73]:
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

def pow_mod(n, p, y):
    z = 1
    while p > 0:
        if p & 1 == 1:
            z = (n*z) % y
        n = (n*n) % y
        p = p >> 1
    return z

def g(x, n, c=1):
    return (x*x + c) % n

def rho(n, x0=2, c=1):
    x = x0
    y = x0
    d = 1

    while d == 1:
        x = g(x, n, c)
        y = g(g(y, n, c), n, c)
        d = math.gcd(abs(x-y), n)

    if d == n:
        if c == 1:
            return rho(n, x0, -1)
        elif c == -1:
            return rho(n, x0, 2)
        elif x0 < 20:
            return rho(n, x0+1, 1)
        else:
            return False
    else:
        return d

prime_factors = {}
def factorization(n):
    while n % 2 == 0:
        add_in_prime_factors(2)
        n //= 2

    if n <= 1:
        return

    if is_prime(n):
        add_in_prime_factors(n)
        return

    a = rho(n)
    if a is False:
        return
    b = n // a

    if is_prime(a):
        add_in_prime_factors(a)
    else:
        factorization(a)

    if is_prime(b):
        add_in_prime_factors(b)
    else:
        factorization(b)

def add_in_prime_factors(p):
    if p in prime_factors:
        prime_factors[p] += 1
    else:
        prime_factors[p] = 1

a, n = [int(x) for x in input().split()]

factorization(a)

keys = sorted(prime_factors.keys(), reverse=True)

for p in keys:
    if a * p <= n:
        print(a * p)
        exit(0)
    while a % p == 0:
        a //= p
    a *= p

print(-1)

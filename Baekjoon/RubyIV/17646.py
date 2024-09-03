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
    if n <= 1:
        return

    if is_prime(n):
        append_prime_factor(n)
        return

    a = rho(n)
    if a is False:
        return
    b = n // a

    if is_prime(a):
        append_prime_factor(a)
    else:
        factorization(a)

    if is_prime(b):
        append_prime_factor(b)
    else:
        factorization(b)

def append_prime_factor(f):
    if not f in prime_factors.keys():
        prime_factors[f] = 1
    else:
        prime_factors[f] += 1

def check_2(n):
    is_count_2 = True
    for factor in prime_factors.keys():
        if factor % 4 == 3 and prime_factors[factor] % 2 != 0:
            is_count_2 = False
            break
    return is_count_2

def tonelli_shanks(p):
    q = p-1
    s = 0
    while q % 2 == 0:
        q //= 2
        s += 1

    if ((q+1) / 2) % 2 == 0:
        r = 1
    else:
        r = -1
    t = -1

    # Find b from the table such that b^2 === t and set r === r/b
    # return r





def decompose_2(n):



    return 0, 0

def decompose_3(n):
    t = 1
    while not check_2(n - t*t):
        t += 1
    a, b = decompose_2(n - t*t)
    return a, b, t

num = int(input())

factorization(num)

is_count_1 = True
for factor_count in prime_factors.values():
    if factor_count % 2 != 0:
        is_count_1 = False
        break

if is_count_1:
    print(1)
    print(int(math.sqrt(num)))
    exit(0)

is_count_2 = True
for factor in prime_factors.keys():
    if factor % 4 == 3 and prime_factors[factor] % 2 != 0:
        is_count_2 = False
        break

if is_count_2:
    print(2)
    a, b = decompose_2(num)
    print(a, b)
    exit(0)

factor_4 = 1
is_count_3= True
while num % 4 == 0:
    num //= 4
    factor_4 *= 4

if num % 8 != 7:
    print(3)
    x, y, z = decompose_3(num)
    print(x, y, z)
else:
    print(4)
    x, y, z = [o*factor_4 for o in decompose_3(num - 1)]
    print(x, y, z, factor_4)

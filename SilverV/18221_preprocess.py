import math

def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True

    n_minus_1 = n-1
    d, s = find_d_and_s(n_minus_1)

    is_n_prime = check_is_prime_with_a(n, d, s, 2)
    for i in [2, 7, 61]:
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

prime_factors = []

def factorization(n):
    if n <= 1:
        return

    if is_prime(n):
        prime_factors.append(n)
        return

    a = rho(n)
    if a is False:
        return
    b = n // a

    if is_prime(a):
        prime_factors.append(a)
    else:
        factorization(a)

    if is_prime(b):
        prime_factors.append(b)
    else:
        factorization(b)

start = 906_150_257
end = 906_488_079
even_count = 0
odd_count = 0

# 906,150,257 ~ 906,488,079
even_list = []
for i in range(start, end+1):
    prime_factors = []
    num = i

    while num % 2 == 0:
        prime_factors.append(2)
        num //= 2

    factorization(num)

    if len(prime_factors) % 2 == 0:
        odd_count += 1
    else:
        even_count += 1

    if even_count < odd_count:
        even_list.append(i)

result = []

start = even_list[0]
end = even_list[0]
before = even_list[0]
for i in range(1, len(even_list)):
    if even_list[i] - before == 1:
        before = even_list[i]
    else:
        end = before
        result.append((start, end))
        start = even_list[i]
        end = even_list[i]
        before = even_list[i]
result.append((start, before))

with open('18221_out.txt', 'w') as file:
    file.write('even_list = [')
    file.write(', '.join([f'({x[0]}, {x[1]})' for x in result]))
    file.write(']')

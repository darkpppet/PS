import math
import itertools

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
    if a == 0:
        return 0
    if a == 1:
        return 1

    if exp == 0:
        return 1
    if exp == 1:
        return a % n

    if n == 1:
        return 0

    result = 1
    while exp > 0:
        if (exp & 1) == 1:
            result = (a * result) % n
        a = (a * a) % n
        exp >>= 1
    return result

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

def append_to_dictionary(dictionary, n):
    if n in dictionary.keys():
        dictionary[n] += 1
    else:
        dictionary[n] = 1

def factorization(n, prime_factors):
    while n % 2 == 0:
        append_to_dictionary(prime_factors, 2)
        n //= 2

    if n <= 1:
        return

    if is_prime(n):
        append_to_dictionary(prime_factors, n)
        return

    a = rho(n)
    if a is False:
        return
    b = n // a

    if is_prime(a):
        append_to_dictionary(prime_factors, a)
    else:
        factorization(a, prime_factors)

    if is_prime(b):
        append_to_dictionary(prime_factors, b)
    else:
        factorization(b, prime_factors)

if __name__ == '__main__':
    k = int(input())
    kk = k*k

    prime_factors = {}
    factorization(k, prime_factors)

    prime_powers = []
    for prime, exponent in prime_factors.items():
        powers_of_current_prime = [prime ** i for i in range(2*exponent + 1) if prime ** i < k]
        prime_powers.append(powers_of_current_prime)

    is_k_even = k % 2 == 0
    min_sum = 2*kk
    pp, qq = 0, 0

    def dfs(prime_powers, p, index):
        global min_sum, pp, qq
        if index >= len(prime_powers):
            q = kk // p
            if not (is_k_even and (p % 2 != 0 or q % 2 != 0)):
                if p + q < min_sum:
                    min_sum = p + q
                    pp, qq = p, q
            return
        for power in prime_powers[index]:
            temp_p = p * power
            if temp_p >= k:
                return
            dfs(prime_powers, temp_p, index + 1)

    dfs(prime_powers, 1, 0)

    x, y = (pp+k) // 2, (qq+k) // 2
    print(f'{x} {y}')

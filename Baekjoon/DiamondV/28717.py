import sys
import math
from collections import Counter, defaultdict

class Prime:
    @classmethod
    def __pow_mod(cls, a, b, y):
        if a == 0:
            return 0
        if a == 1:
            return 1

        if b == 0:
            return 1
        if b == 1:
            return a%y

        if y == 1:
            return 0

        z = 1
        while b > 0:
            if b&1 == 1:
                z = (a*z) % y
            a = (a*a) % y
            b >>= 1
        return z

    @staticmethod
    def __find_d_and_s(n_minus_1):
        s = 0
        while n_minus_1 % 2 == 0:
            n_minus_1 //= 2
            s += 1
        d = n_minus_1

        return d, s

    @classmethod
    def __check_is_prime_with_a(cls, n, d, s, a):
        a_power_d = cls.__pow_mod(a, d, n)
        if a_power_d == 1 or a_power_d == n-1:
            return True

        for r in range(s):
            a_power_d = (a_power_d*a_power_d) % n
            if a_power_d == n-1:
                return True

        return False

    @classmethod
    def check(cls, n):
        if n <= 1:
            return False
        if n == 2:
            return True

        d, s = cls.__find_d_and_s(n-1)
        for i in [2, 3, 5, 7, 11, 13, 17, 19, 23]:
            if n <= i:
                break

            if not cls.__check_is_prime_with_a(n, d, s, i):
                return False

        return True

class Factorization:
    @staticmethod
    def __g(x, n, c=1):
        return (x*x + c) % n

    @classmethod
    def __rho(cls, n, x0=2, c=1):
        x = x0
        y = x0
        d = 1

        while d == 1:
            x = cls.__g(x, n, c)
            y = cls.__g(cls.__g(y, n, c), n, c)
            d = math.gcd(abs(x-y), n)

        if d == n:
            if c == 1:
                return cls.__rho(n, x0, -1)
            if c == -1:
                return cls.__rho(n, x0, 2)
            if x0 < 20:
                return cls.__rho(n, x0+1, 1)

            return False

        return d

    @classmethod
    def __do_internal(cls, n, prime_factors):
        if n <= 1:
            return

        if Prime.check(n):
            prime_factors.add(n)
            return

        a = cls.__rho(n)
        if a is False:
            return

        b = n // a

        cls.__do_internal(a, prime_factors)
        cls.__do_internal(b, prime_factors)

    @classmethod
    def do(cls, n, prime_factors):
        if n%2 == 0:
            prime_factors.add(2)
            while n%2 == 0:
                n //= 2
        cls.__do_internal(n, prime_factors)

def main():
    n = int(input())
    a_list = [int(x) for x in sys.stdin.read().split()]

    prime_factor_counts = Counter()
    for a in a_list:
        prime_factors = set()
        Factorization.do(a, prime_factors)
        prime_factor_counts.update(prime_factors)

    print(max(prime_factor_counts.values()))

if __name__ == '__main__':
    main()

import math

class Prime:
    @classmethod
    def __pow_mod(cls, a, exp, n):
        if exp == 0:
            return 1
        if exp == 1:
            return a % n

        sqrt = cls.__pow_mod(a, exp//2, n)
        pre_result = (sqrt*sqrt) % n
        if exp%2 != 0:
            pre_result *= a
            pre_result %= n

        return pre_result


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
        if cls.__pow_mod(a, d, n) == 1:
            return True

        for r in range(s):
            if cls.__pow_mod(a, d*pow(2, r), n) == n-1:
                return True

        return False

    @classmethod
    def check(cls, n):
        if n <= 1:
            return False
        if n == 2:
            return True

        d, s = cls.__find_d_and_s(n-1)
        for i in [2, 3, 5, 7, 11, 13, 17, 31, 61, 73]:
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
            elif c == -1:
                return cls.__rho(n, x0, 2)
            elif x0 < 20:
                return cls.__rho(n, x0+1, 1)
            else:
                return False
        else:
            return d

    @classmethod
    def __append_prime_factor(cls, f, prime_factors):
        if not f in prime_factors.keys():
            prime_factors[f] = 1
        else:
            prime_factors[f] += 1

    @classmethod
    def do(cls, n, prime_factors):
        if n <= 1:
            return

        if Prime.check(n):
            cls.__append_prime_factor(n, prime_factors)
            return

        a = cls.__rho(n)
        if a is False:
            return

        b = n // a

        if Prime.check(a):
            cls.__append_prime_factor(a, prime_factors)
        else:
            Factorization.do(a, prime_factors)

        if Prime.check(b):
            cls.__append_prime_factor(b, prime_factors)
        else:
            Factorization.do(b, prime_factors)


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
    return r

class One:
    @staticmethod
    def check(prime_factors):
        for factor_count in prime_factors.values():
            if factor_count % 2 != 0:
                return False
        return True

    @staticmethod
    def decompose(num):
        return int(math.sqrt(num))

class Two:
    @staticmethod
    def check(prime_factors):
        for factor in prime_factors.keys():
            if factor % 4 == 3 and prime_factors[factor] % 2 != 0:
                return False
        return True

    @staticmethod
    def decompose(num):
        a, b = 0, 0
        return a, b

class Three:
    @staticmethod
    def check(num):
        while num % 4 == 0:
            num //= 4
        return num % 8 != 7

    @staticmethod
    def decompose(num):
        t = 1
        while not Two.check(num - t*t):
            t += 1
        a, b = Two.decompose(num - t*t)
        return a, b, t

class Four:
    @staticmethod
    def decompose(num):
        sqrt_factor_4 = 1
        while num % 4 == 0:
            num //= 4
            sqrt_factor_4 *= 2
        x, y, z = Three.decompose(num/(sqrt_factor_4*sqrt_factor_4) - 1)
        return x, y, z, sqrt_factor_4

def main():
    num = int(input())

    prime_factors = {}
    Factorization.do(num, prime_factors)

    if One.check(prime_factors):
        print(1)
        print(One.decompose(num))
        exit(0)

    if Two.check(prime_factors):
        print(2)
        print(Two.decompose(num))
        exit(0)

    if Three.check(num):
        print(3)
        print(Three.decompose(num))
        exit(0)

    print(4)
    print(Four.decompose(num))
    exit(0)

if __name__ == '__main__':
    main()

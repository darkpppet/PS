import math

class MillerRabin:
    __a_list = [3, 5, 7, 11, 13, 17, 31, 61, 73]

    @classmethod
    def is_prime(cls, n):
        if n <= 1:
            return False
        if n == 2:
            return True

        n_minus_1 = n-1
        d, s = cls.__find_d_and_s(n_minus_1)

        is_n_prime = cls.__check_is_prime_with_a(n, d, s, 2)
        for i in cls.__a_list:
            if n > i and is_n_prime:
                is_n_prime &= cls.__check_is_prime_with_a(n, d, s, i)
            else:
                break

        return is_n_prime

    def __check_is_prime_with_a(self, n, d, s, a):
        is_prime_with_a = False
        if self.__pow_mod(a, d, n) == 1:
            is_prime_with_a = True

        for r in range(s):
            if is_prime_with_a or self.__pow_mod(a, d*pow(2, r), n) == n-1:
                is_prime_with_a = True
                break

        return is_prime_with_a

    def __find_d_and_s(self, n_minus_1):
        s = 0
        while n_minus_1 % 2 == 0:
            n_minus_1 //= 2
            s += 1
        d = n_minus_1

        return d, s

    def __pow_mod(self, a, exp, n):
        if exp == 0:
            return 1
        if exp == 1:
            return a % n

        sqrt = self.__pow_mod(a, exp//2, n)
        pre_result = (sqrt*sqrt) % n

        if exp%2 == 0:
            return pre_result
        else:
            return (pre_result*a) % n

class PollardRho:
    prime_factors_list = []
    prime_factors_dict = {}

    def factorization(self, n):
        if n <= 1:
            return

        if MillerRabin.is_prime(n):
            self.prime_factors_list.append(n)
            self.__append_to_dict(n)
            return

        while n % 2 == 0:
            self.prime_factors_list.append(2)
            self.__append_to_dict(2)
            n //= 2

        a = self.__rho(n)
        if a is False:
            return
        b = n // a

        if MillerRabin.is_prime(a):
            self.prime_factors_list.append(a)
            self.__append_to_dict(a)
        else:
            self.factorization(a)

        if MillerRabin.is_prime(b):
            self.prime_factors_list.append(b)
            self.__append_to_dict(b)
        else:
            self.factorization(b)

    def __append_to_dict(self, n):
        if not n in self.prime_factors_dict.keys():
            self.prime_factors_dict[n] = 1
        else:
            self.prime_factors_dict[n] += 1

    def __rho(self, n, x0=2, c=1):
        x = x0
        y = x0
        d = 1

        while d == 1:
            x = self.__g(x, n, c)
            y = self.__g(self.__g(y, n, c), n, c)
            d = math.gcd(abs(x-y), n)

        if d == n:
            if c == 1:
                return self.__rho(n, x0, -1)
            elif c == -1:
                return self.__rho(n, x0, 2)
            elif x0 < 20:
                return self.__rho(n, x0+1, 1)
            else:
                return False
        else:
            return d

    def __g(self, x, n, c=1):
        return (x*x + c) % n

class Checker:
    def __init__(self, prime_factor_dict):
        self.prime_factor_dict = prime_factor_dict

    def is_count_1(self):
        result = True
        for factor_count in self.prime_factor_dict.values():
            if factor_count % 2 != 0:
                result = False
                break
        return result

    def is_count_2(self):
        result = True
        for factor in self.prime_factor_dict.keys():
            if factor % 4 == 3 and self.prime_factor_dict[factor] % 2 != 0:
                result = False
                break
        return result

    def is_count_3(self, n):
        while n % 4 == 0:
            n //= 4
        if n % 8 != 7:
            return True
        else:
            return False

    def is_count_4(self, n):
        while n % 4 == 0:
            n //= 4
        if n % 8 == 7:
            return True
        else:
            return False

class SquaresFinder:
    def find_1_squares(self, n):
        return round(math.sqrt(n))

    def find_2_squares(self, n):
        x, y = 1, 1
        return x, y

    def find_3_squares(self, n):
        t = 1

        while True:
            r = PollardRho()
            r.factorization(n - t*t)
            c = Checker(r.prime_factors_dict)
            if c.is_count_2():
                x, y = self.find_2_squares(n - t*t)
                break

        return x, y, t

    def find_4_squares(self, n):
        a = 0
        while n % 4 == 0:
            a += 1
            n //= 4

        power_2_to_a = 2 ** a
        x, y, z = self.find_3_squares(n)

        return x * power_2_to_a, y * power_2_to_a, z * power_2_to_a, power_2_to_a

factorizator = PollardRho()

num = int(input())

factorizator.factorization(num)

checker = Checker(factorizator.prime_factors_dict)
finder = SquaresFinder()

if checker.is_count_1():
    print(1)
    print(finder.find_1_squares(num))
elif checker.is_count_2():
    print(2)
    print(finder.find_2_squares(num))
elif checker.is_count_3(num):
    print(3)
    print(finder.find_3_squares(num))
else:
    print(4)
    print(finder.find_4_squares(num))

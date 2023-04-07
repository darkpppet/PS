from math import floor, sqrt

def isPrime(num):
    for i in range(2, floor(sqrt(num))+1):
        if num % i == 0:
            return False
    return True

primes = []
for i in range(2, 31623):
    if isPrime(i):
        primes.append(i)
prime_len = len(primes)

def factorization(num): 
    factors = set()
    index = 0

    while index < prime_len and primes[index] <= num:
        if num % primes[index] == 0:
            factors.add(primes[index])
            num //= primes[index]
        else:
            index += 1

    if num != 1:
        factors.add(num)

    return list(factors)

while True:
    n = int(input())

    if n == 1:
        print(0)
        continue

    if n == 0:
        exit()

    factors = factorization(n)

    result = n

    for factor in factors:
        n //= factor
        n *= factor-1

    print(n)

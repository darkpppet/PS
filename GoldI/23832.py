from math import floor, sqrt

def isPrime(num):
    for i in range(2, floor(sqrt(num))+1):
        if num % i == 0:
            return False
    return True

primes = []
for i in range(2, 224):
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

n = int(input())

count = 0

for i in range(2, n+1):
    factors = factorization(i)
    
    for factor in factors:
        i //= factor
        i *= factor-1

    count += i

print(count)

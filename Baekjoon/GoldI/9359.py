from itertools import combinations
from math import prod, floor, sqrt

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

t = int(input())

for i in range(1, t+1):
    a, b, n = [int(x) for x in input().split()]

    factors = factorization(n)
    factor_count = len(factors)

    count = b-a+1
    plus = False

    for j in range(1, factor_count+1):
        now_comb = [prod(x) for x in combinations(factors, j)]
        now_b_count = sum([floor(b/x) for x in now_comb])
        now_a_count = sum([floor((a-1)/x) for x in now_comb])
        
        now_count = now_b_count - now_a_count

        if plus == True:
            count += now_count
        else:
            count -= now_count
        plus = not plus

    print(f'Case #{i}: {count}')

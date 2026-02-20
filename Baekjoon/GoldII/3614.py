
def get_prime_factors(x):
    prime_factors = set()
    divisor = 2
    while x > 1:
        if x % divisor == 0:
            prime_factors.add(divisor)
            while x % divisor == 0:
                x //= divisor
        divisor += 1

    return prime_factors

def phi(x):
    prime_factors = get_prime_factors(x)
    result = x
    for prime_factor in prime_factors:
        result //= prime_factor
        result *= (prime_factor-1)
    return result

def main():
    n = int(input())

    count = 0
    for i in range(1, n+1):
        if n % i == 0:
            count += phi(n//i + 1)

    print(count//2 + 1)

if __name__ == '__main__':
    main()

from itertools import combinations
from math import prod, floor

n, m = [int(x) for x in input().split()]

primes = [int(x) for x in input().split()]

count = 0
plus = True

for i in range(1, n+1):
    now_comb = [prod(x) for x in combinations(primes, i)]
    now_count = sum([floor(m/x) for x in now_comb])

    if plus == True:
        count += now_count
    else:
        count -= now_count
    plus = not plus
    
print(count)

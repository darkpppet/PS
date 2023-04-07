from itertools import combinations
from math import floor, lcm

n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

count = n
plus = False

for j in range(1, len(a)+1):
    now_comb = [lcm(*x) for x in combinations(a, j)]
    now_count = sum([floor(n/x) for x in now_comb])
    
    if plus == True:
        count += now_count
    else:
        count -= now_count
    plus = not plus

print(count)

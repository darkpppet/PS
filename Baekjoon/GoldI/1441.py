from itertools import combinations
from math import floor, lcm

n, l, r = [int(x) for x in input().split()]
nums = [int(x) for x in input().split()]

count = 0
plus = True

for j in range(1, len(nums)+1):
    now_comb = [lcm(*x) for x in combinations(nums, j)]
    now_r_count = sum([floor(r/x) for x in now_comb])
    now_l_count = sum([floor((l-1)/x) for x in now_comb])
    
    now_count = now_r_count - now_l_count

    if plus == True:
        count += now_count
    else:
        count -= now_count
    plus = not plus

print(count)

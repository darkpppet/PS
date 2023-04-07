from itertools import permutations
from math import sqrt

n = int(input())
r = [int(x) for x in input().split()]
r_len = len(r)

result = 2_000_000_000*8

for permutation_r in permutations(r):
    new_list = []

    for now_r in permutation_r:
        new_x = 0
        for (before_r, before_x) in new_list:
            temp_x = before_x + 2*sqrt(before_r*now_r)
            new_x = max(new_x, temp_x)

        new_list.append((now_r, new_x))

    result = min(result, new_list[-1][1])

print(result)
